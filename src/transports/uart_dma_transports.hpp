#ifndef __UART_DMA_TRANSPORTS__
#define __UART_DMA_TRANSPORTS__

#include "transports.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

class UartDmaTransport : public Transport {
    public:
        UartDmaTransport(uart_inst_t *_uart_id,uint _baudrate,uint _gpio_tx,uint _gpio_rx);

        SemaphoreHandle_t getRxSemaphor();
        SemaphoreHandle_t getTxSemaphor();
        int getRxDmaChan();
        int getTxDmaChan();

    protected:
        bool open() override;
        bool close() override;
        size_t write(const uint8_t *buf, size_t len, uint8_t *errcode) override;
        size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode) override;

    private:
        uart_inst_t *uart_id;
        uint baudrate;
        uint gpio_tx;
        uint gpio_rx;

        int tx_dma_chan;
        int rx_dma_chan;

        SemaphoreHandle_t uart_rx_semaphor;
        SemaphoreHandle_t uart_tx_semaphor;
};
#endif