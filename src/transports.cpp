#include "transports.hpp"

#include "pico/stdio.h"
#include "pico/stdlib.h"

#include "allocators.h"

#include <uxr/client/profile/transport/custom/custom_transport.h>
#include <rmw_microros/rmw_microros.h>
#include <rcl/rcl.h>


Transport::Transport(){
    rmw_uros_set_custom_transport(
        true,
        this,
        openEntryPoint,
        closeEntryPoint,
        writeEntryPoint,
        readEntryPoint
    );

    rcutils_allocator_t allocators = rcutils_get_default_allocator();
    allocators.allocate = freertosAllocate;
    allocators.deallocate = freertosDeallocate;

    rcl_ret_t ret = rcutils_set_default_allocator(&allocators);
    if (ret != RCL_RET_OK){return;}
}

bool Transport::openEntryPoint(uxrCustomTransport *transport){
    return static_cast<Transport*>(transport->args)->open();
}
bool Transport::closeEntryPoint(uxrCustomTransport *transport){
    return static_cast<Transport*>(transport->args)->close();
}
size_t Transport::writeEntryPoint(struct uxrCustomTransport * transport, const uint8_t *buf, size_t len, uint8_t *errcode){
    return static_cast<Transport*>(transport->args)->write(buf,len,errcode);
}
size_t Transport::readEntryPoint(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode){
    return static_cast<Transport*>(transport->args)->read(buf,len,timeout,errcode);
}

StdioTransport::StdioTransport(){

}

bool StdioTransport::open(){
    stdio_init_all();
    return true;
}
bool StdioTransport::close(){
    return true;
};
size_t StdioTransport::write(const uint8_t *buf, size_t len, uint8_t *errcode){
    for (size_t i = 0; i < len; i++)
    {
        if (buf[i] != putchar(buf[i]))
        {
            *errcode = 1;
            return i;
        }
    }
    return len;
}
size_t StdioTransport::read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode){
    uint64_t start_time_us = time_us_64();
    for (size_t i = 0; i < len; i++)
    {
        int64_t elapsed_time_us = timeout * 1000 - (time_us_64() - start_time_us);
        if (elapsed_time_us < 0)
        {
            *errcode = 1;
            return i;
        }

        int character = getchar_timeout_us(elapsed_time_us);
        if (character == PICO_ERROR_TIMEOUT)
        {
            *errcode = 1;
            return i;
        }
        buf[i] = character;
    }
    return len;
}