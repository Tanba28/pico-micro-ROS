#include "microros_task.hpp"

#include <rcl/rcl.h>
#include <std_msgs/msg/float32.h>

#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

uint8_t count = 0;
static void _callback(const void * ros_message){
    count++;
    const std_msgs__msg__Float32 *msg = (const std_msgs__msg__Float32*)ros_message;
    printf("Hello World!%d data:%f\n",count,msg->data);
}

MicroRosController::MicroRosController():
TaskBase("microros_task",1,1024*16){
    node = new MicroRosNode(this,"float_talker","");

    this->createTask();
}

void MicroRosController::task(){
    TickType_t last_wake_time;

    for(;;){
        last_wake_time = xTaskGetTickCount();
        

        node->nodeRun();

        gpio_put(25, !gpio_get(25));
        xTaskDelayUntil(&last_wake_time,pdMS_TO_TICKS(100));
    }
}

MicroRosNode::MicroRosNode(MicroRos::Context *context,const char *node_name,const char *name_space):
    MicroRos::Node(context,node_name,name_space){
    publisher = new MicroRosPublisher(this,"topic1",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));
    publisher2 = new MicroRosPublisher(this,"topic2",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));

    subscriber = new MicroRosSubscriber(this,"topic3",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32));

    executor = new MicroRosExecutor(context,1);

    executor->add_subscription(subscriber,&subscriber->msg,_callback);
}

void MicroRosNode::nodeRun(){
    publisher->publishRun();
    publisher2->publishRun();
    executor->spin_some(10);
}


MicroRosPublisher::MicroRosPublisher(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Publisher(node,topic_name,type_support){

}

void MicroRosPublisher::publishRun(){
    msg.data = xTaskGetTickCount();
    publish(&msg);
}

MicroRosSubscriber::MicroRosSubscriber(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Subscriber(node,topic_name,type_support){
}

MicroRosExecutor::MicroRosExecutor(MicroRos::Context *context,size_t num_handle):
    MicroRos::Executor(context,num_handle){

}