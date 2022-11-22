#include "microros_task.hpp"

#include <rcl/rcl.h>
#include <std_msgs/msg/float32.h>

#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// Task Constructor
MicroRosTask::MicroRosTask(const char *_node_name, const char *_name_space):
    TaskBase("float_talker_task",1,4096),
    node_name(_node_name),name_space(_name_space){

}

// Publish Wrapper
void MicroRosTask::publish(){
    publisher->publish(&msg);

}

// Task
void MicroRosTask::task(){
    context = new MicroRosContext();
    node = new MicroRosNode(context,node_name,name_space);
    publisher = new MicroRosPublisher(node,"topic",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));

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