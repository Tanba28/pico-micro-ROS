#ifndef __MICROROS_BASE__
#define __MICROROS_BASE__

#include "rcl/rcl.h"
#include "rclc/executor.h"
#include "rclc/timer.h"
#include "rclc_lifecycle/rclc_lifecycle.h"

namespace MicroRos{

class Support;
class Node;
class Publisher;
class Subscriber;
class Server;
class Client;
class Executor;
class Timer;

class Support{
    public:
        Support();
        virtual ~Support();

        rclc_support_t* getSupport();
        rcl_context_t* getContext();
        rcl_clock_t* getClock();

    protected:
        rclc_support_t support;
        rcl_allocator_t allocator;
};

class Node{
    public:
        Node(Support *support,const char *node_name,const char *name_space);
        virtual ~Node();

        rcl_node_t* getNode();

    protected:
        rcl_node_t node;
        rcl_node_options_t node_options;
};

class Publisher{
    public:
        Publisher(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support,bool besteffort = false);
        virtual ~Publisher();

        rcl_publisher_t* getPublisher();

        void publish(const void *ros_message);

    private:
        rcl_publisher_t publisher;
        rcl_publisher_options_s pub_options;

        rcl_node_t *node;
};

class Subscriber{
    public:
        Subscriber(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support,bool besteffort = false);
        virtual ~Subscriber();

        rcl_subscription_t* getSubscriber();
        static void callbackEntryPoint(const void* msg, void* context);
        
    private:
        virtual void callback(const void* msg) = 0;

        rcl_subscription_t subscriber;
        rcl_subscription_options_s sub_options;

        rcl_node_t *node;
};

class Server{
    public:
        Server(Node *_node,const char *service_name,const rosidl_service_type_support_t *type_support,bool besteffort = false);
        virtual ~Server();

        rcl_service_t* getService();
        static void callbackEntryPoint(const void *request,void *response, void* context);
        
    private:
        virtual void callback(const void *request,void *response) = 0;

        rcl_service_t service;
        rcl_service_options_t service_options;
        rcl_node_t *node;
};

class Client{
    public:
        Client(Node *_node,const char *service_name,const rosidl_service_type_support_t *type_support,bool besteffort = false);
        virtual ~Client();

        rcl_client_t* getClient();     
    private:
        rcl_client_t client;
        rcl_client_options_t options;
        rcl_node_t *node;
};

class Executor{
    public:
        Executor(Support *support,size_t num_hundle);
        virtual ~Executor();

        rclc_executor_t* getExecutor();
        
        void spinSome(uint64_t timeout_ns);
        void spin();

        void addSubscriber(Subscriber *subscriber,void *msg);
        void addServer(Server *server,void *request,void *response);
        void addClient(Client *client,void *response,void (*callback)(const void *));
        void addTimer(Timer *timer);

    private:
        rclc_executor_t executor;
        rcl_allocator_t allocator;
        rcl_context_t *context;
};

class Timer{
    public:
        Timer(Support *support,int64_t period,void (* callback)(rcl_timer_t *, int64_t));
        virtual ~Timer();

        rcl_timer_t* getTimer();
    private:
        rcl_timer_t timer;
};

}

#endif