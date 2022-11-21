#include "uart_transports.hpp"

#include "stdio.h"
#include "pico/stdlib.h"

UartTransport::UartTransport(uart_inst_t *_uart_id,uint _baudrate):uart_id(_uart_id),baudrate(_baudrate){

}

bool UartTransport::open(){
    uart_init(uart_id, baudrate);
    gpio_set_function(12,GPIO_FUNC_UART);
    gpio_set_function(13,GPIO_FUNC_UART);
    return true;
}
bool UartTransport::close(){
    uart_deinit(uart_id);
    return true;
}
size_t UartTransport::write(const uint8_t *buf, size_t len, uint8_t *errcode){
    //if(uart_is_writable(uart_id)){
        for(size_t i = 0; i < len; i++){
            uart_putc_raw(uart_id,buf[i]);
        }
        return len;
    // }
    // else{
    //     return 0;
    // }
}

size_t UartTransport::read(uint8_t *buf, size_t len, int timeout, uint8_t *errcode){
    for(size_t i = 0; i < len; i++){
        if(uart_is_readable_within_us(uart_id,timeout*1000)){
            buf[i] = uart_getc(uart_id);
        }
        else{
            return i;
        }
    }
    return len;
}