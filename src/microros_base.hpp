#ifndef __MICROROS_BASE__
#define __MICROROS_BASE__

#include "rcl/rcl.h"
#include "rclc/executor.h"
#include "rclc_lifecycle/rclc_lifecycle.h"

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
        Node(rcl_context_t *context,const char *node_name,const char *name_space);
        ~Node();

        rcl_node_t* getNode();

    protected:
        rcl_node_t node;
        rcl_node_options_t node_options;
};

class LifeCycleNode : public Node{
    public:
        LifeCycleNode(rcl_context_t *context,const char *node_name,const char *name_space);

        rclc_lifecycle_node_t* getLifeCycleNode();

        void addStateServer(rclc_executor_t *lifecycle_executor);

        void setConfigureCallback(int (* callback)(void));
        void setActivateCallback(int (* callback)(void));
        void setDeactivateCallback(int (* callback)(void));
        void setCleanupCallback(int (* callback)(void));
        
    private:
        rcl_lifecycle_state_machine_t state_macine;
        rclc_lifecycle_node_t lifecycle_node;
        rclc_lifecycle_service_context_t lifecycle_context;
};

class Publisher{
    public:
        Publisher(rcl_node_t *_node,const char *_topic_name,const rosidl_message_type_support_t *type_support);
        ~Publisher();

        void publish(const void *ros_message);

    private:
        rcl_publisher_t publisher;
        rcl_publisher_options_s pub_options;

        rcl_node_t *node;
};

class Subscriber{
    public:
        Subscriber(rcl_node_t *_node,const char *topic_name,const rosidl_message_type_support_t *type_support);
        ~Subscriber();

        void addExecutor(rclc_executor_t *executor,void *msg);
        void addExecutorStatic(rclc_executor_t *executor,void *msg,rclc_subscription_callback_t callback);

    private:
        virtual void callback(const void* msg) = 0;
        static void callbackEntryPoint(const void* msg, void* context);

        rcl_subscription_t subscriber;
        rcl_subscription_options_s sub_options;

        rcl_node_t *node;
};

class Executor{
    public:
        Executor(rcl_context_t *context,size_t num_hundle);
        ~Executor();

        rclc_executor_t* getExecutor();
        
        void spinSome(uint64_t timeout_ns);

    private:
        rclc_executor_t executor;
        rcl_allocator_t allocator;
        rcl_subscription_options_s sub_options;

        rcl_context_t *context;
};

}


#endif