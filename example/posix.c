#include "pico/stdio.h"
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

#include <rmw_microros/rmw_microros.h>

/* this function is from FreeRTOS + Posix */
int clock_gettime(clockid_t clock_id, struct timespec *tp)
{
    TimeOut_t current_time = {0};

    uint64_t tick_count = 0ULL;

    (void) clock_id;

    vTaskSetTimeOutState(&current_time);

    tick_count = (uint64_t)(current_time.xOverflowCount) << (sizeof(TickType_t)*8);

    tick_count += current_time.xTimeOnEntering;

    tp->tv_sec = (time_t)(tick_count/configTICK_RATE_HZ);
    tp->tv_nsec = (long)((tick_count*1000000000/configTICK_RATE_HZ) % 1000000000);

    // uint64_t m = time_us_64();
    // tp->tv_sec = m / 1000000;
    // tp->tv_nsec = (m % 1000000) * 1000;
    
    return 0;
}