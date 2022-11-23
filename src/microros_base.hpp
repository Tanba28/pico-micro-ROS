#ifndef __MICROROS_BASE__
#define __MICROROS_BASE__

#include <rcl/rcl.h>

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
        Publisher(Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support);
        ~Publisher();

        void publish(const void *ros_message);

    private:
        rcl_publisher_t publisher;
        rcl_publisher_options_s pub_options;

        rcl_node_t *node;
};

}


#endif