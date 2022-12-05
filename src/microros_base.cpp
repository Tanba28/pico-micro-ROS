#include "microros_base.hpp"

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

#include "rmw_microros/rmw_microros.h"

#define RCCHECK(ret) if(ret!=RCL_RET_OK){printf("Failed status on %d: %d\n",__LINE__,(int)ret);while(1);}
namespace MicroRos{

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

Node::Node(rcl_context_t *context,const char *node_name,const char *name_space){
    node = rcl_get_zero_initialized_node();
    node_options = rcl_node_get_default_options();
    RCCHECK(rcl_node_init(&node,node_name,name_space,context,&node_options));
}

Node::~Node(){
    RCCHECK(rcl_node_fini(&node));
}

rcl_node_t* Node::getNode(){
    return &node;
}

LifeCycleNode::LifeCycleNode(rcl_context_t *context,const char *node_name,const char *name_space):
    Node(context,node_name,name_space){
    state_macine = rcl_lifecycle_get_zero_initialized_state_machine();
    rcl_allocator_t allocator = rcutils_get_default_allocator();

    RCCHECK(rclc_make_node_a_lifecycle_node(
        &lifecycle_node,
        &node,
        &state_macine,
        &allocator,
        true
    ));
}

rclc_lifecycle_node_t* LifeCycleNode::getLifeCycleNode(){
    return &lifecycle_node;
}

void LifeCycleNode::addStateServer(rclc_executor_t *lifecycle_executor){
    lifecycle_context.lifecycle_node = &lifecycle_node;
    RCCHECK(rclc_lifecycle_init_get_state_server(&lifecycle_context,lifecycle_executor));
    RCCHECK(rclc_lifecycle_init_get_available_states_server(&lifecycle_context,lifecycle_executor));
    RCCHECK(rclc_lifecycle_init_change_state_server(&lifecycle_context,lifecycle_executor));
}

void LifeCycleNode::setConfigureCallback(int (* callback)(void)){
    rclc_lifecycle_register_on_configure(&lifecycle_node,callback);
}
void LifeCycleNode::setActivateCallback(int (* callback)(void)){
    rclc_lifecycle_register_on_activate(&lifecycle_node,callback);
}
void LifeCycleNode::setDeactivateCallback(int (* callback)(void)){
    rclc_lifecycle_register_on_deactivate(&lifecycle_node,callback);
}
void LifeCycleNode::setCleanupCallback(int (* callback)(void)){
    rclc_lifecycle_register_on_cleanup(&lifecycle_node,callback);
}


Publisher::Publisher(rcl_node_t *_node,const char *topic_name,const rosidl_message_type_support_t *type_support)
    :node(_node){
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

Subscriber::Subscriber(rcl_node_t *_node,const char *topic_name,const rosidl_message_type_support_t *type_support)
    :node(_node){
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
void Subscriber::addExecutor(rclc_executor_t *executor,void *msg){
    RCCHECK(rclc_executor_add_subscription_with_context(
        executor,
        &subscriber,
        msg,
        callbackEntryPoint,
        this,
        ON_NEW_DATA
    ));
}
void Subscriber::addExecutorStatic(rclc_executor_t *executor,void *msg,rclc_subscription_callback_t callback){
    RCCHECK(rclc_executor_add_subscription(
        executor,
        &subscriber,
        msg,
        callback,
        ON_NEW_DATA
    ));
}
void Subscriber::callbackEntryPoint(const void* msg, void* context){
    static_cast<Subscriber*>(context)->callback(msg);
}


Executor::Executor(rcl_context_t *_context,size_t num_hundle)
    :context(_context){
    allocator = rcl_get_default_allocator();
    RCCHECK(rclc_executor_init(
        &executor,
        context,
        num_hundle,
        &allocator
    ));
}

rclc_executor_t* Executor::getExecutor(){
    return &executor;
}

void Executor::spinSome(uint64_t timeout_ns){
    rclc_executor_spin_some(&executor,timeout_ns);
}
}