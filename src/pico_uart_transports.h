#ifndef MICRO_ROS_PICOSDK
#define MICRO_ROS_PICOSDK

#ifdef	__cplusplus
extern "C" {
#endif	/* __cplusplus */

#include <stdio.h>
#include <stdint.h>

void setCustomTransport();

extern int clock_gettime(clockid_t unused, struct timespec *tp);

#ifdef	__cplusplus
}
#endif	/* __cplusplus */
#endif //MICRO_ROS_PICOSDK
