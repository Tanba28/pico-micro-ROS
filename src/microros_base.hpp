#ifndef __MICROROS_BASE__
#define __MICROROS_BASE__

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>

class MicroRosNode{
    public:
        MicroRosNode();
        MicroRosNode(const char *node_name,const char *name_space);
        ~MicroRosNode();

        rcl_allocator_t* get_allocator();
        rclc_support_t* get_support();
        rcl_context_t* get_support_context();

    protected:
        rcl_node_t node;
        rclc_support_t support;
        rcl_allocator_t allocator;
        rcl_timer_t timer;
        rclc_executor_t executor;
};


class MicroRosPublisher : public MicroRosNode{
    public:
        MicroRosPublisher();
        MicroRosPublisher(const char *node_name,const char *name_space, const char *topic_name,const rosidl_message_type_support_t *type_support);
        ~MicroRosPublisher();

        void publish(const void *ros_message);
        rcl_publisher_t* get_publisher(); 

    private:
        rcl_publisher_t publisher;
};

class MicroRosTimer{
    public:
        MicroRosTimer();
        MicroRosTimer(MicroRosNode *node,uint64_t timeout_ns,void (*callback)(rcl_timer_t*,int64_t));

        rcl_timer_t* get_timer();
    private:
        rcl_timer_t timer;
};

class MicroRosExecutor{
    public:
        MicroRosExecutor();
        MicroRosExecutor(MicroRosNode *node,uint8_t num_handles);
        ~MicroRosExecutor();

        void add_timer(MicroRosTimer *timer);
        void execute();
    private:
        rclc_executor_t executor;
};

#endif