#ifndef __FREERTOS_ALLOCATORS__
#define __FREERTOS_ALLOCATORS__

#ifdef	__cplusplus
extern "C" {
#endif	/* __cplusplus */

#include "pico/stdlib.h"

void *freertosAllocate(size_t size,void *state);
void freertosDeallocate(void *ptr,void *state);

#ifdef __cplusplus
}
#endif

#endif