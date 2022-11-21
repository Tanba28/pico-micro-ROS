#ifndef __UART_TRANSPORTS__
#define __UART_TRANSPORTS__

#include "transports.hpp"

class UartTransport : public Transport {
    public:
        UartTransport(uart_inst_t *_uart_id,uint _baudrate);

    protected:
        bool open() override;
        bool close() override;
        size_t write(const uint8_t *buf, size_t len, uint8_t *errcode) override;
        size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode) override;

    private:
        uart_inst_t *uart_id;
        uint baudrate;
};

#endif
