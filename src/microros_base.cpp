#include "microros_base.hpp"

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"

#include "rmw_microros/rmw_microros.h"

#define RCCHECK(ret) if(ret!=RCL_RET_OK){printf("Failed status on %d: %d\n",__LINE__,(int)ret);while(1);}
namespace MicroRos{

/* Support --------------------------------------------------------------------------------- */
Support::Support(){
    RCCHECK(rmw_uros_ping_agent(2000, 240));
    allocator = rcl_get_default_allocator();
    RCCHECK(rclc_support_init(&support,0,NULL,&allocator));
}

Support::~Support(){
    RCCHECK(rclc_support_fini(&support));
}
rclc_support_t* Support::getSupport(){
    return &support;
}
rcl_context_t* Support::getContext(){
    return &support.context;
}
rcl_clock_t* Support::getClock(){
    return &support.clock;
}

/* Node --------------------------------------------------------------------------------- */
Node::Node(Support *support,const char *node_name,const char *name_space){
    node = rcl_get_zero_initialized_node();
    node_options = rcl_node_get_default_options();
    RCCHECK(rcl_node_init(&node,node_name,name_space,support->getContext(),&node_options));
}

Node::~Node(){
    RCCHECK(rcl_node_fini(&node));
}

rcl_node_t* Node::getNode(){
    return &node;
}

/* Publisher --------------------------------------------------------------------------------- */
Publisher::Publisher(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support,bool besteffort)
    :node(_node->getNode()){
    publisher = rcl_get_zero_initialized_publisher();
    pub_options = rcl_publisher_get_default_options();
    if(besteffort==true){
        pub_options.qos = rmw_qos_profile_sensor_data;
    }
    
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

rcl_publisher_t* Publisher::getPublisher(){
    return &publisher;
}

void Publisher::publish(const void *ros_message){
    rcl_ret_t ret = rcl_publish(&publisher,ros_message,NULL);
    if (ret != RCL_RET_OK){
        printf("Failed publish on %d: %d\n",__LINE__,(int)ret);
        return;
    }
}

/* Subscriber --------------------------------------------------------------------------------- */
Subscriber::Subscriber(Node *_node,const char *topic_name,const rosidl_message_type_support_t *type_support,bool besteffort)
    :node(_node->getNode()){
    subscriber = rcl_get_zero_initialized_subscription();
    sub_options = rcl_subscription_get_default_options();
    if(besteffort==true){
        sub_options.qos = rmw_qos_profile_sensor_data;
    }
    RCCHECK(rcl_subscription_init(
        &subscriber,
        node,
        type_support,
        topic_name,
        &sub_options
    ));
}

Subscriber::~Subscriber(){
    RCCHECK(rcl_subscription_fini(&subscriber,node));
}

rcl_subscription_t* Subscriber::getSubscriber(){
    return &subscriber;
}

void Subscriber::callbackEntryPoint(const void* msg, void* context){
    static_cast<Subscriber*>(context)->callback(msg);
}

/* Service --------------------------------------------------------------------------------- */
Server::Server(Node *_node,const char *service_name,const rosidl_service_type_support_t *type_support,bool besteffort)
    :node(_node->getNode()){
    service = rcl_get_zero_initialized_service();
    service_options = rcl_service_get_default_options();
    if(besteffort==true){
        service_options.qos = rmw_qos_profile_sensor_data;
    }
    RCCHECK(rcl_service_init(
        &service,
        node,
        type_support,
        service_name,
        &service_options
    ));
}
Server::~Server(){
    RCCHECK(rcl_service_fini(&service,node));
}
rcl_service_t* Server::getService(){
    return &service;
}
void Server::callbackEntryPoint(const void *request,void *response, void* context){
    static_cast<Server*>(context)->callback(request,response);
}

/* Client --------------------------------------------------------------------------------- */
Client::Client(Node *_node,const char *service_name,const rosidl_service_type_support_t *type_support,bool besteffort)
    :node(_node->getNode()){
    client = rcl_get_zero_initialized_client();
    options = rcl_client_get_default_options();
    if(besteffort==true){
        options.qos = rmw_qos_profile_sensor_data;
    }
    RCCHECK(rcl_client_init(
        &client,
        node,
        type_support,
        service_name,
        &options
    ));
}
Client::~Client(){
    RCCHECK(rcl_client_fini(&client,node));
}
rcl_client_t* Client::getClient(){
    return &client;
}

/* Executor --------------------------------------------------------------------------------- */
Executor::Executor(Support *support,size_t num_hundle)
    :context(support->getContext()){
    allocator = rcl_get_default_allocator();
    RCCHECK(rclc_executor_init(
        &executor,
        context,
        num_hundle,
        &allocator
    ));
}

Executor::~Executor(){
    RCCHECK(rclc_executor_fini(&executor));
}

rclc_executor_t* Executor::getExecutor(){
    return &executor;
}

void Executor::spinSome(uint64_t timeout_ns){
    rclc_executor_spin_some(&executor,timeout_ns);
}

void Executor::spin(){
    rclc_executor_spin(&executor);
}

void Executor::addSubscriber(Subscriber *subscriber,void* msg){
    RCCHECK(rclc_executor_add_subscription_with_context(
        &executor,
        subscriber->getSubscriber(),
        msg,
        Subscriber::callbackEntryPoint,
        subscriber,
        ON_NEW_DATA
    ));
}

void Executor::addServer(Server *server,void *request,void *response){
    RCCHECK(rclc_executor_add_service_with_context(
        &executor,
        server->getService(),
        request,
        response,
        Server::callbackEntryPoint,
        server
    ));
}

void Executor::addClient(Client *client,void *response,void (*callback)(const void *)){
    RCCHECK(rclc_executor_add_client(
        &executor,
        client->getClient(),
        response,
        callback
    ));
}

void Executor::addTimer(Timer *timer){
    RCCHECK(rclc_executor_add_timer(&executor,timer->getTimer()));
}

/* Timer --------------------------------------------------------------------------------- */
Timer::Timer(Support *support,int64_t period,void (* callback)(rcl_timer_t *, int64_t)){
    timer = rcl_get_zero_initialized_timer();
    RCCHECK(rclc_timer_init_default(
        &timer,
        support->getSupport(),
        period,
        callback
    ));
}

Timer::~Timer(){
    RCCHECK(rcl_timer_fini(&timer));
}

rcl_timer_t* Timer::getTimer(){
    return &timer;
}
}