#ifndef __UART_DMA_TRANSPORTS__
#define __UART_DMA_TRANSPORTS__

#include "transports.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

class UartDmaTransport : public Transport {
    public:
        // Singleton Class
        static void createInstance(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx);
        static UartDmaTransport* getInstance();

        void rxIrqHandler();
        void txIrqHandler();

        bool isInitialize();
        void initialize();
        void deinitialize();

    protected:
        bool open() override;
        bool close() override;
        size_t write(const uint8_t *buf, size_t len, uint8_t *errcode) override;
        size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode) override;

    private:
        UartDmaTransport(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx);

        static UartDmaTransport *uart_dma_transports;

        bool init_flag = false;

        uart_inst_t *uart_id;
        uint baudrate;
        uint gpio_tx;
        uint gpio_rx;

        int tx_dma_chan;
        int rx_dma_chan;

        SemaphoreHandle_t rx_irq_semaphor;
        SemaphoreHandle_t tx_irq_semaphor;
};
#endif