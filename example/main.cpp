#include "pico/stdlib.h"
#include "microros_task.hpp"

#include "FreeRTOS.h"
#include "task.h"

const uint LED_PIN = 25;

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);
    stdio_init_all();

    MicroRosController microros = MicroRosController();

    vTaskStartScheduler();

    while (true)
    {

    }
    return 0;
}