#include "pico/stdlib.h"
#include "microros_base.hpp"

#include "FreeRTOS.h"
#include "task.h"

#include "rmw_microros/rmw_microros.h"

bool RCCHECK(rcl_ret_t ret){
    if (ret != RCL_RET_OK){
        printf("Failed status on %d: %d\n",__LINE__,(int)ret);
        vTaskDelay(1000);
        vTaskSuspend(NULL);
        return false;
    }
    return true;
}
MicroRosContext::MicroRosContext(){
    RCCHECK(rmw_uros_ping_agent(1000, 120));

    init_options = rcl_get_zero_initialized_init_options();
    RCCHECK(rcl_init_options_init(&init_options,rcutils_get_default_allocator()));

    context = rcl_get_zero_initialized_context();
    RCCHECK(rcl_init(0,NULL,&init_options,&context));
    RCCHECK(rcl_init_options_fini(&init_options));
}

MicroRosContext::~MicroRosContext(){
    RCCHECK(rcl_context_fini(&context));
}

rcl_context_t* MicroRosContext::getContext(){
    return &context;
}

MicroRosNode::MicroRosNode(MicroRosContext *context,const char *node_name,const char *name_space){
    node = rcl_get_zero_initialized_node();
    node_options = rcl_node_get_default_options();
    RCCHECK(rcl_node_init(&node,node_name,name_space,context->getContext(),&node_options));
}

MicroRosNode::~MicroRosNode(){
    RCCHECK(rcl_node_fini(&node));
}

rcl_node_t* MicroRosNode::getNode(){
    return &node;
}
MicroRosPublisher::MicroRosPublisher(MicroRosNode *_node,const char *topic_name,const rosidl_message_type_support_t *type_support)
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

    // rclc_publisher_init_default(
    //     &publisher,
    //     node,
    //     type_support,
    //     topic_name);
}

MicroRosPublisher::~MicroRosPublisher(){
    RCCHECK(rcl_publisher_fini(&publisher, node));
}

void MicroRosPublisher::publish(const void *ros_message){
    rcl_ret_t ret = rcl_publish(&publisher,ros_message,NULL);
    if (ret != RCL_RET_OK){
        printf("Failed publish on %d: %d\n",__LINE__,(int)ret);
        return;
    }
}