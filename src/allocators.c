#include "allocators.h"

#include "pico/stdio.h"
#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

void *freertosAllocate(size_t size,void *state){
    (void) state;
    return pvPortMalloc(size);
}

void freertosDeallocate(void *ptr,void *state){
    (void) state;
    if(NULL != ptr){
        vPortFree(ptr);
    }
}

