#include "microros_task.hpp"

#include "microros_base.hpp"
#include "uart_dma_transports.hpp"

#include "hardware/watchdog.h"

#include <rcl/rcl.h>
#include <std_msgs/msg/int32.h>
#include <rmw_microros/rmw_microros.h>


#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

MicroRosNode *MicroRosNode::_node = NULL;

void callback(rcl_timer_t * timer, int64_t last_call_time){
    MicroRosNode::_node->process();
}

MicroRosController::MicroRosController():
TaskBase("microros_task",1,1024*8){
    UartDmaTransport::createInstance(uart0,460800,12,13);
    this->createTask();
}

void MicroRosController::task(){
    // uint64_t counter = 0;
    // TickType_t last_wake_time;

    support = new MicroRos::Support();
    node = new MicroRosNode(support,"float_talker","");

    // rmw_uros_sync_session(1000);

    // last_wake_time = xTaskGetTickCount();
    for(;;){
        // watchdog_update();
        
        // node->process();
        // if(counter%2==0){
        //     gpio_put(25, !gpio_get(25));
        // }
        // xTaskDelayUntil(&last_wake_time,pdMS_TO_TICKS(10));

        // counter++;
    }
}

MicroRosNode::MicroRosNode(MicroRos::Support *support,const char *node_name,const char *name_space):
    MicroRos::Node(support,node_name,name_space){
    _node = this;

    // executor
    executor = new MicroRos::Executor(support,2); // 2 = timer + subscription

    // timer
    timer = new MicroRos::Timer(support,RCL_MS_TO_NS(10),callback);
    executor->addTimer(timer);
    // Pub
    publisher = new MicroRosPublisher(this,"topic1",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));
    publisher2 = new MicroRosPublisher(this,"topic2",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));

    // Sub
    subscriber = new MicroRosSubscriber(this,"topic3",ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int64));
    executor->addSubscriber(subscriber,&subscriber->msg);

    rmw_uros_sync_session(1000);

    executor->spin();
}

void MicroRosNode::process(){
    publisher->process();
    publisher2->process();
    // executor->spinSome(1000*1000);
}


MicroRosPublisher::MicroRosPublisher(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Publisher(node,topic_name,type_support){

}

void MicroRosPublisher::process(){
    msg.data = rmw_uros_epoch_nanos();
    publish(&msg);
}

MicroRosSubscriber::MicroRosSubscriber(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support):
    MicroRos::Subscriber(node,topic_name,type_support){
}

void MicroRosSubscriber::callback(const void* msg){
    count++;
    const std_msgs__msg__Int64 *_msg = (const std_msgs__msg__Int64*)msg;
    printf("Hello World!%d data:%d\n",count,_msg->data);
}