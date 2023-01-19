#include "pico/stdlib.h"
#include "microros_base.hpp"

#include "FreeRTOS.h"

MicroRosNode::MicroRosNode(const char *node_name,const char *name_space){
    allocator = rcl_get_default_allocator();

    rcl_ret_t ret = rmw_uros_ping_agent(2000, 240);

    if (ret != RCL_RET_OK)
    {
        return;
    }

    rclc_support_init(&support,0,NULL,&allocator);

    rclc_node_init_default(&node,node_name,name_space,&support);
}
MicroRosNode::~MicroRosNode(){
    rcl_ret_t ret = rcl_node_fini(&node);
    if (ret != RCL_RET_OK)
    {
        return;
    }
}
rcl_allocator_t* MicroRosNode::get_allocator(){
    return &allocator;
}
rclc_support_t* MicroRosNode::get_support(){
    return &support;
}
rcl_context_t* MicroRosNode::get_support_context(){
    return &support.context;
}

MicroRosPublisher::MicroRosPublisher(const char *node_name,const char *name_space, const char *topic_name,const rosidl_message_type_support_t *type_support):MicroRosNode(node_name,name_space){
    rclc_publisher_init_default(
        &publisher,
        &node,
        type_support,
        topic_name);
}
MicroRosPublisher::~MicroRosPublisher(){
    rcl_ret_t ret = rcl_publisher_fini(&publisher, &node);

    if (ret != RCL_RET_OK)
    {
        return;
    }
}

void MicroRosPublisher::publish(const void *ros_message){
    rcl_ret_t ret = rcl_publish(&publisher,ros_message,NULL);
    if (ret != RCL_RET_OK)
    {
        return;
    }
}


rcl_publisher_t* MicroRosPublisher::get_publisher(){
    return &publisher;
}


MicroRosTimer::MicroRosTimer(MicroRosNode *node,uint64_t timeout_ns,void (*callback)(rcl_timer_t*,int64_t)){
    rclc_timer_init_default(
        &timer,
        node->get_support(),
        timeout_ns,
        callback);
}
rcl_timer_t* MicroRosTimer::get_timer(){
    return &timer;
}

MicroRosExecutor::MicroRosExecutor(MicroRosNode *node,uint8_t num_handles){
    rcl_ret_t ret = rclc_executor_init(&executor, node->get_support_context(), num_handles, node->get_allocator());
    
    if (ret != RCL_RET_OK)
    {
        return;
    }
}
MicroRosExecutor::~MicroRosExecutor(){
    rclc_executor_fini(&executor);
}
void MicroRosExecutor::add_timer(MicroRosTimer *timer){
    rcl_ret_t ret = rclc_executor_add_timer(&executor, timer->get_timer());
    if (ret != RCL_RET_OK)
    {
        return;
    }
}
void MicroRosExecutor::execute(){
    rclc_executor_spin(&executor);
}

