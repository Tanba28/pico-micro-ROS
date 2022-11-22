#include "pico/stdlib.h"
#include "microros_task.hpp"

#include "uart_dma_transports.hpp"
#include "uart_transports.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

const uint LED_PIN = 25;

extern UartDmaTransport *uart_dma_transports;

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);
    stdio_init_all();

    MicroRosTask microros_task = MicroRosTask("float_talker_1","");

    uart_dma_transports = new UartDmaTransport(uart0,460800,12,13);
    (void) uart_dma_transports;

    microros_task.create_task();
    // floattalker_2.create_task();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}