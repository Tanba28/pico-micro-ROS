#ifndef __MICROROS_BASE__
#define __MICROROS_BASE__

#include "rcl/rcl.h"
#include "rclc/executor.h"

bool RCCHECK(rcl_ret_t ret);

namespace MicroRos{

class Context{
    public:
        Context();
        ~Context();

        rcl_context_t* getContext();

    protected:
        rcl_init_options_t init_options;
        rcl_context_t context;
};

class Node{
    public:
        Node(Context *context,const char *node_name,const char *name_space);
        ~Node();

        rcl_node_t* getNode();

    protected:
        rcl_node_t node;
        rcl_node_options_t node_options;
};


class Publisher{
    public:
        Publisher(Node *_node,const char *_topic_name,const rosidl_message_type_support_t *type_support);
        ~Publisher();

        void publish(const void *ros_message);

    private:
        rcl_publisher_t publisher;
        rcl_publisher_options_s pub_options;

        rcl_node_t *node;
};

class Subscriber{
    public:
        Subscriber(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support);
        ~Subscriber();

        static void (*callback)(const void * ros_message);

        rcl_subscription_t* getSubscriber();
    private:
        rcl_subscription_t subscriber;
        rcl_subscription_options_s sub_options;

        rcl_node_t *node;
};

class Executor{
    public:
        Executor(Context *context,size_t num_hundle);
        ~Executor();
        
        void add_subscription(Subscriber *subscriber,void* msg,rclc_subscription_callback_t callback);
        void spin_some(uint64_t timeout_ms);

    private:
        rclc_executor_t executor;
        rcl_allocator_t allocator;
        rcl_subscription_options_s sub_options;

        rcl_context_t *context;
};

}


#endif