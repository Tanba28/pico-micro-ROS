#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/float32.h>
#include <rmw_microros/rmw_microros.h>

#include "float_talker.hpp"

#include "microros_base.hpp"


// Task Handler
FloatTalkerTask *floattalker;

// Timer Callback Func
void callback(rcl_timer_t *timer, int64_t last_call_time){
    gpio_put(PICO_DEFAULT_LED_PIN, !gpio_get(PICO_DEFAULT_LED_PIN));

    floattalker->msg.data = floattalker->msg.data + 0.1;

    floattalker->publish();
}

// Task Constructor
FloatTalkerTask::FloatTalkerTask():
    TaskBase("float_talker_task",1,1024),
    publisher(MicroRosPublisher("float_talker","","topic",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32))),
    timer(MicroRosTimer(&publisher,RCL_MS_TO_NS(100),callback)),
    executor(MicroRosExecutor(&publisher,1)){

    executor.add_timer(&timer);

    floattalker->msg.data = 0;
}

// Publish Wrapper
void FloatTalkerTask::publish(){
    publisher.publish(&msg);
}

// Task
void FloatTalkerTask::task(){
    // Publisher execute
    executor.execute();

    for(;;){

    }
}