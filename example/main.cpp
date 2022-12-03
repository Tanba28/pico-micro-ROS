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

    UartDmaTransport::createInstance(uart0,460800,12,13);

    MicroRosController microros = MicroRosController();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}