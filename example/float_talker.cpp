#include "float_talker.hpp"

#include <rcl/rcl.h>
#include <std_msgs/msg/float32.h>

#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// Task Constructor
FloatTalkerTask::FloatTalkerTask(const char *_node_name, const char *_name_space, const char *_topic_name,SemaphoreHandle_t *_initializing_semaphor,MicroRosContext *context):
    TaskBase("float_talker_task",1,2048),
    node_name(_node_name),name_space(_name_space),topic_name(_topic_name),initializing_semaphor(_initializing_semaphor){
    node = new MicroRosNode(context,node_name,name_space);
    publisher = new MicroRosPublisher(node,topic_name,ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));
    publisher2 = new MicroRosPublisher(node,"topic2",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));
}

// Publish Wrapper
void FloatTalkerTask::publish(){
    publisher->publish(&msg);
    publisher2->publish(&msg);
}

// Task
void FloatTalkerTask::task(){
    this->msg.data = 0;

    TickType_t last_wake_time;

    for(;;){
        last_wake_time = xTaskGetTickCount();
        this->msg.data = last_wake_time;

        this->publish();

        gpio_put(25, !gpio_get(25));

        xTaskDelayUntil(&last_wake_time,pdMS_TO_TICKS(20));
    }
}