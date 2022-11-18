#ifndef __TRANSPORT__
#define __TRANSPORT__

#include "task_base.hpp"

#include <uxr/client/profile/transport/custom/custom_transport.h>

class Transport{
    public:
        Transport();        

    protected:
        virtual bool open() = 0;
        virtual bool close() = 0;
        virtual size_t write(const uint8_t *buf, size_t len, uint8_t *errcode) = 0;
        virtual size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode) = 0;

        static bool openEntryPoint(uxrCustomTransport *transport);
        static bool closeEntryPoint(uxrCustomTransport *transport);
        static size_t writeEntryPoint(struct uxrCustomTransport * transport, const uint8_t *buf, size_t len, uint8_t *errcode);
        static size_t readEntryPoint(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode);
};

class StdioTransport : public Transport {
    public:
        StdioTransport();

    protected:
        virtual bool open();
        virtual bool close();
        virtual size_t write(const uint8_t *buf, size_t len, uint8_t *errcode);
        virtual size_t read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode);
};

#endif //MICRO_ROS_PICOSDK
