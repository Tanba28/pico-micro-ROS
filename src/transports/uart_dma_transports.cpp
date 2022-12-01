#include "uart_dma_transports.hpp"

#include "stdio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "task_base.hpp"

UartDmaTransport *UartDmaTransport::uart_dma_transports = NULL;

void UartDmaTransport::createInstance(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx){
    if(UartDmaTransport::uart_dma_transports == NULL){
        UartDmaTransport::uart_dma_transports = new UartDmaTransport(_uart_id,_baudrate,_gpio_tx,_gpio_rx);
    }
}
UartDmaTransport* UartDmaTransport::getInstance(){
    return UartDmaTransport::uart_dma_transports;
}

static void txDmaHandler(){
    UartDmaTransport::getInstance()->txIrqHandler();
}

static void rxDmaHandler(){
    UartDmaTransport::getInstance()->rxIrqHandler();
}

UartDmaTransport::UartDmaTransport(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx)
:uart_id(_uart_id),baudrate(_baudrate),gpio_tx(_gpio_tx),gpio_rx(_gpio_rx){

}

void UartDmaTransport::txIrqHandler(){
    if(dma_hw->ints0 & 1u << tx_dma_chan){
        dma_hw->ints0 = 1u << tx_dma_chan;
        BaseType_t higher_priority_task_woken;
        
        higher_priority_task_woken = pdFALSE;   
        
        xSemaphoreGiveFromISR(tx_irq_semaphor, &higher_priority_task_woken);
        
        portEND_SWITCHING_ISR( higher_priority_task_woken );    
    }
}
void UartDmaTransport::rxIrqHandler(){
    if(dma_hw->ints0 & 1u << rx_dma_chan){
        dma_hw->ints0 = 1u << rx_dma_chan;
        BaseType_t higher_priority_task_woken;

        higher_priority_task_woken = pdFALSE;   

        xSemaphoreGiveFromISR(rx_irq_semaphor, &higher_priority_task_woken);

        portEND_SWITCHING_ISR( higher_priority_task_woken );
    } 
}

bool UartDmaTransport::isInitialize(){
    return init_flag;
}
void UartDmaTransport::initialize(){
    uart_init(uart_id, baudrate);
    gpio_set_function(gpio_tx,GPIO_FUNC_UART);
    gpio_set_function(gpio_rx,GPIO_FUNC_UART);

    rx_irq_semaphor = xSemaphoreCreateBinary();
    tx_irq_semaphor = xSemaphoreCreateBinary();

    // Tx DMA Confuguration
    tx_dma_chan = dma_claim_unused_channel(true);

    dma_channel_config c = dma_channel_get_default_config(tx_dma_chan);
    channel_config_set_transfer_data_size(&c,DMA_SIZE_8);
    channel_config_set_read_increment(&c,true);
    channel_config_set_write_increment(&c,false);
    channel_config_set_dreq(&c,uart_get_dreq(uart_id,true));

    dma_channel_configure(
        tx_dma_chan,
        &c,
        &uart_get_hw(uart0)->dr,
        NULL,
        0,
        false
    );

    dma_channel_set_irq0_enabled(tx_dma_chan,true);
    irq_add_shared_handler(DMA_IRQ_0,txDmaHandler,PICO_SHARED_IRQ_HANDLER_DEFAULT_ORDER_PRIORITY);

    // RX DMA Configuration
    rx_dma_chan = dma_claim_unused_channel(true);

    c = dma_channel_get_default_config(rx_dma_chan);
    channel_config_set_transfer_data_size(&c,DMA_SIZE_8);
    channel_config_set_read_increment(&c,false);
    channel_config_set_write_increment(&c,true);
    channel_config_set_dreq(&c,uart_get_dreq(uart_id,false));

    dma_channel_configure(
        rx_dma_chan,
        &c,
        NULL,
        &uart_get_hw(uart0)->dr,
        0,
        false
    );

    dma_channel_set_irq0_enabled(rx_dma_chan,true);
    irq_add_shared_handler(DMA_IRQ_0,rxDmaHandler,PICO_SHARED_IRQ_HANDLER_DEFAULT_ORDER_PRIORITY);
    irq_set_enabled(DMA_IRQ_0,true);

    init_flag = true;
}

void UartDmaTransport::deinitialize(){
    uart_deinit(uart_id);
    dma_channel_set_irq0_enabled(tx_dma_chan,false);
    dma_channel_set_irq0_enabled(rx_dma_chan,false);
    irq_remove_handler(DMA_IRQ_0,txDmaHandler);
    irq_remove_handler(DMA_IRQ_0,rxDmaHandler);
    dma_channel_unclaim(tx_dma_chan);
    dma_channel_unclaim(rx_dma_chan);

    init_flag = false;
}

bool UartDmaTransport::open(){
    if(!isInitialize()){
        initialize();
    }

    return true;
}

bool UartDmaTransport::close(){
    if(isInitialize()){
        deinitialize();
    }
    return true;
}
size_t UartDmaTransport::write(const uint8_t *buf, size_t len, uint8_t *errcode){
    dma_channel_set_read_addr(tx_dma_chan,buf,false);
    dma_channel_set_trans_count(tx_dma_chan,len,true);

    xSemaphoreTake(tx_irq_semaphor,portMAX_DELAY);

    return len;
}
size_t UartDmaTransport::read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode){
    dma_channel_set_write_addr(rx_dma_chan,buf,false);
    dma_channel_set_trans_count(rx_dma_chan,len,true);

    xSemaphoreTake(rx_irq_semaphor,pdMS_TO_TICKS(timeout));
    return len;   
}