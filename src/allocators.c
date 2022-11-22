#include "allocators.h"

#include "FreeRTOS.h"

int absolute_used_memory = 0;
int used_memory = 0;

void *freertosAllocate(size_t size,void *state){
    (void) state;

    absolute_used_memory += size;
    used_memory += size;
    return pvPortMalloc(size);
}

void freertosDeallocate(void *ptr,void *state){
    (void) state;
    if(NULL != ptr){
        used_memory -= getBlockSize(ptr);
        vPortFree(ptr);
    }
}
void *freertosReallocate(void *ptr,size_t size,void *state){
    (void) state;
    if(NULL != ptr){
        absolute_used_memory += size;
        used_memory += size;
        used_memory -= getBlockSize(ptr);
        return pvPortRealloc(ptr,size);
    }
    else{
        absolute_used_memory += size;
        used_memory += size;
        return pvPortMalloc(size);
    }
}
void *freertosZeroAllocate(size_t num_ele,size_t size_ele,void *state){
    (void) state;
    absolute_used_memory += num_ele * size_ele;
    used_memory += num_ele*size_ele;

    return pvPortCalloc(num_ele,size_ele);
}