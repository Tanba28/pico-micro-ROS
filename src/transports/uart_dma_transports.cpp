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

UartDmaTransport *uart_dma_transports;

static void txDmaHandler(){
    if(dma_hw->ints0 & 1u << uart_dma_transports->getTxDmaChan()){
        dma_hw->ints0 = 1u << uart_dma_transports->getTxDmaChan();
        BaseType_t higher_priority_task_woken;
        
        higher_priority_task_woken = pdFALSE;   
        
        xSemaphoreGiveFromISR(uart_dma_transports->getTxIrqSemaphor(), &higher_priority_task_woken);
        
        portEND_SWITCHING_ISR( higher_priority_task_woken );    
    }
}

static void rxDmaHandler(){
    if(dma_hw->ints0 & 1u << uart_dma_transports->getRxDmaChan()){
        dma_hw->ints0 = 1u << uart_dma_transports->getRxDmaChan();
        BaseType_t higher_priority_task_woken;

        higher_priority_task_woken = pdFALSE;   

        xSemaphoreGiveFromISR(uart_dma_transports->getRxIrqSemaphor(), &higher_priority_task_woken);

        portEND_SWITCHING_ISR( higher_priority_task_woken );
    } 
}

UartDmaTransport::UartDmaTransport(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx)
:uart_id(_uart_id),baudrate(_baudrate),gpio_tx(_gpio_tx),gpio_rx(_gpio_rx){

}

SemaphoreHandle_t UartDmaTransport::getRxIrqSemaphor(){
    return uart_rx_irq_semaphor;
}
SemaphoreHandle_t UartDmaTransport::getTxIrqSemaphor(){
    return uart_tx_irq_semaphor;
}
int UartDmaTransport::getRxDmaChan(){
    return rx_dma_chan;
}
int UartDmaTransport::getTxDmaChan(){
    return tx_dma_chan;
}

bool UartDmaTransport::isInitialize(){
    return init_flag;
}
void UartDmaTransport::initialize(){
    uart_init(uart_id, baudrate);
    gpio_set_function(gpio_tx,GPIO_FUNC_UART);
    gpio_set_function(gpio_rx,GPIO_FUNC_UART);

    uart_rx_irq_semaphor = xSemaphoreCreateBinary();
    uart_tx_irq_semaphor = xSemaphoreCreateBinary();
    uart_rx_semaphor = xSemaphoreCreateBinary();
    uart_tx_semaphor = xSemaphoreCreateBinary();

    // Tx DMA Confuguration
    tx_dma_chan = dma_claim_unused_channel(true);

    dma_channel_config c = dma_channel_get_default_config(tx_dma_chan);
    channel_config_set_transfer_data_size(&c,DMA_SIZE_8);
    channel_config_set_read_increment(&c,true);
    channel_config_set_write_increment(&c,false);
    channel_config_set_dreq(&c,DREQ_UART0_TX);

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
    channel_config_set_dreq(&c,DREQ_UART0_RX);

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

    xSemaphoreTake(uart_tx_irq_semaphor,portMAX_DELAY);

    return len;
}
size_t UartDmaTransport::read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode){
    dma_channel_set_write_addr(rx_dma_chan,buf,false);
    dma_channel_set_trans_count(rx_dma_chan,len,true);

    xSemaphoreTake(uart_rx_irq_semaphor,pdMS_TO_TICKS(timeout));
    return len;   
}