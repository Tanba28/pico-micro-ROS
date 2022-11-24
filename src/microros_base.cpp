#include "pico/stdlib.h"
#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"

#include "rmw_microros/rmw_microros.h"


namespace MicroRos{

bool RCCHECK(rcl_ret_t ret){
    if (ret != RCL_RET_OK){
        printf("Failed status on %d: %d\n",__LINE__,(int)ret);
        vTaskDelay(1000);
        vTaskSuspend(NULL);
        return false;
    }
    return true;
}

Context::Context(){
    RCCHECK(rmw_uros_ping_agent(1000, 120));

    init_options = rcl_get_zero_initialized_init_options();
    RCCHECK(rcl_init_options_init(&init_options,rcutils_get_default_allocator()));

    context = rcl_get_zero_initialized_context();
    RCCHECK(rcl_init(0,NULL,&init_options,&context));
    RCCHECK(rcl_init_options_fini(&init_options));
}

Context::~Context(){
    RCCHECK(rcl_context_fini(&context));
}

rcl_context_t* Context::getContext(){
    return &context;
}

Node::Node(Context *context,const char *node_name,const char *name_space){
    node = rcl_get_zero_initialized_node();
    node_options = rcl_node_get_default_options();
    RCCHECK(rcl_node_init(&node,node_name,name_space,context->getContext(),&node_options));
}

Node::~Node(){
    RCCHECK(rcl_node_fini(&node));
}

rcl_node_t* Node::getNode(){
    return &node;
}
Publisher::Publisher(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support)
    :node(_node->getNode()){
    publisher = rcl_get_zero_initialized_publisher();
    pub_options = rcl_publisher_get_default_options();
    
    RCCHECK(rcl_publisher_init(
        &publisher,
        node,
        type_support,
        topic_name,
        &pub_options
    ));
}

Publisher::~Publisher(){
    RCCHECK(rcl_publisher_fini(&publisher, node));
}

void Publisher::publish(const void *ros_message){
    rcl_ret_t ret = rcl_publish(&publisher,ros_message,NULL);
    if (ret != RCL_RET_OK){
        printf("Failed publish on %d: %d\n",__LINE__,(int)ret);
        return;
    }
}

Subscriber::Subscriber(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support)
    :node(_node->getNode()){
    subscriber = rcl_get_zero_initialized_subscription();
    sub_options = rcl_subscription_get_default_options();

    RCCHECK(rcl_subscription_init(
        &subscriber,
        node,
        type_support,
        topic_name,
        &sub_options
    ));
}

rcl_subscription_t* Subscriber::getSubscriber(){
    return &subscriber;
}

Executor::Executor(Context *_context,size_t num_hundle)
    :context(_context->getContext()){
    allocator = rcl_get_default_allocator();
    RCCHECK(rclc_executor_init(
        &executor,
        context,
        num_hundle,
        &allocator
    ));
}

void Executor::add_subscription(Subscriber *subscriber,void* msg,rclc_subscription_callback_t callback){
    RCCHECK(rclc_executor_add_subscription(
        &executor,
        subscriber->getSubscriber(),
        msg,
        callback,
        ON_NEW_DATA
    ));
}

void Executor::spin_some(uint64_t timeout_ms){
    rclc_executor_spin_some(&executor,timeout_ms);
}
}