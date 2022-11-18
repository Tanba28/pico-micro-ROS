#include <stdio.h>
#include "pico/stdlib.h"
#include "pico_uart_transports.h"

#include "FreeRTOS.h"
#include "task.h"

#include <rmw_microros/rmw_microros.h>
#include <uxr/client/profile/transport/custom/custom_transport.h>

static bool pico_serial_transport_open(struct uxrCustomTransport * transport);
static bool pico_serial_transport_close(struct uxrCustomTransport * transport);
static size_t pico_serial_transport_write(struct uxrCustomTransport * transport, const uint8_t *buf, size_t len, uint8_t *errcode);
static size_t pico_serial_transport_read(struct uxrCustomTransport* transport, uint8_t* buf, size_t len, int timeout, uint8_t* err);

/* Public Function */
void setCustomTransport(){
    rmw_uros_set_custom_transport(
		true,
		NULL,
		pico_serial_transport_open,
		pico_serial_transport_close,
		pico_serial_transport_write,
		pico_serial_transport_read
	);
}

// void usleep(uint64_t us)
// {
//     sleep_us(us);
// }

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

/* Private Function */
static bool pico_serial_transport_open(struct uxrCustomTransport * transport)
{
    stdio_init_all();
    return true;
}

static bool pico_serial_transport_close(struct uxrCustomTransport * transport)
{
    return true;
}

static size_t pico_serial_transport_write(struct uxrCustomTransport * transport, const uint8_t *buf, size_t len, uint8_t *errcode)
{
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

static size_t pico_serial_transport_read(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode)
{
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
