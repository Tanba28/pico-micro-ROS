#include "pico/stdlib.h"
#include "float_talker.hpp"

#include "pico_uart_transports.h"

const uint LED_PIN = 25;

extern FloatTalkerTask *floattalker;

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);

    setCustomTransport();

    floattalker = new FloatTalkerTask();

    floattalker->create_task();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}