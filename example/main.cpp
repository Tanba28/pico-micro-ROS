#include "pico/stdlib.h"
#include "float_talker.hpp"

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

    SemaphoreHandle_t semaphor = xSemaphoreCreateBinary();
    xSemaphoreGive(semaphor);

    UartTransport uart_transport = UartTransport(uart0,115200);
    (void) uart_transport;

    MicroRosContext context = MicroRosContext();
    FloatTalkerTask floattalker_1 = FloatTalkerTask("float_talker_1","","topic1",&semaphor,&context);
    // FloatTalkerTask floattalker_2 = FloatTalkerTask("float_talker_2","","topic2",&semaphor,&context);

    UartDmaTransport _uart_dma_transports = UartDmaTransport(uart0,115200,12,13);
    uart_dma_transports = &_uart_dma_transports;
    (void) uart_dma_transports;

    floattalker_1.create_task();
    // floattalker_2.create_task();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}