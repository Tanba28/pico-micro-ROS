#include "pico/stdlib.h"
#include "float_talker.hpp"

#include "uart_dma_transports.hpp"
#include "uart_transports.hpp"

const uint LED_PIN = 25;

extern FloatTalkerTask *floattalker;
extern UartDmaTransport *uart_dma_transports;

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);

    // UartTransport transport = UartTransport(uart0,115200);
    uart_dma_transports = new UartDmaTransport(uart0,115200,12,13);
    (void) uart_dma_transports;

    floattalker = new FloatTalkerTask();

    floattalker->create_task();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}