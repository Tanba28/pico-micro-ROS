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