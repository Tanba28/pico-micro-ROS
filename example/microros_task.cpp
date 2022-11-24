#include "microros_task.hpp"

#include <rcl/rcl.h>
#include <std_msgs/msg/int32.h>
#include <rmw_microros/rmw_microros.h>

#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

uint16_t count = 0;
static void subCallback(const void * ros_message){
    count++;
    const std_msgs__msg__Int64 *msg = (const std_msgs__msg__Int64*)ros_message;
    printf("Hello World!%d data:%d\n",count,msg->data);
}

MicroRosController::MicroRosController():
TaskBase("microros_task",1,1024*16){
    node = new MicroRosNode(this,"float_talker","");

    this->createTask();
}

void MicroRosController::task(){
    TickType_t last_wake_time;

    rmw_uros_sync_session(1000);

    last_wake_time = xTaskGetTickCount();
    for(;;){
        node->nodeRun();
        gpio_put(25, !gpio_get(25));
        xTaskDelayUntil(&last_wake_time,pdMS_TO_TICKS(20));
    }
}

MicroRosNode::MicroRosNode(MicroRos::Context *context,const char *node_name,const char *name_space):
    MicroRos::Node(context->getContext(),node_name,name_space){
    executor = new MicroRosExecutor(context,5);

    // Pub
    publisher = new MicroRosPublisher(this,"topic1",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));
    publisher2 = new MicroRosPublisher(this,"topic2",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));

    // // Sub
    subscriber = new MicroRosSubscriber(this,"topic3",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));
    subscriber->addExecutor(executor->getExecutor(),&subscriber->msg,subCallback);

    // TODO:LifeCycle
    // addStateServer(executor->getExecutor());
    // setConfigureCallback(&configureCallback);
    // setActivateCallback(&activateCallback);
    // setDeactivateCallback(&deactivateCallback);
    // setCleanupCallback(&cleanupCallback);

}

void MicroRosNode::nodeRun(){
    publisher->publishRun();
    publisher2->publishRun();
    executor->spinSome(1000000);
}


MicroRosPublisher::MicroRosPublisher(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Publisher(node->getNode(),topic_name,type_support){

}

void MicroRosPublisher::publishRun(){

    msg.data = rmw_uros_epoch_millis();
    publish(&msg);
}

MicroRosSubscriber::MicroRosSubscriber(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Subscriber(node->getNode(),topic_name,type_support){
}

MicroRosExecutor::MicroRosExecutor(MicroRos::Context *context,size_t num_handle):
    MicroRos::Executor(context->getContext(),num_handle){

}