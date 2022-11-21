#ifndef __STDIO_TRANSPORTS__
#define __STDIO_TRANSPORTS__

#include "transports.hpp"

class StdioTransport : public Transport {
    public:
        StdioTransport();

    protected:
        bool open() override;
        bool close() override;
        size_t write(const uint8_t *buf, size_t len, uint8_t *errcode) override;
        size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode) override;
};

#endif
