#ifndef FLOAT_TALKER
#define FLOAT_TALKER

#include "pico/stdlib.h"

#include <rcl/rcl.h>
#include <std_msgs/msg/int64.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "microros_base.hpp"

#include "task_base.hpp"

class MicroRosController;
class MicroRosNode;
class MicroRosPublisher;
class MicroRosSubscriber;
class MicroRosExecutor;

class MicroRosController : public TaskBase{
    public:
        MicroRosController();

    private:
        MicroRos::Support *support;
        MicroRosNode *node;

        // microRos用スレッドはひとつだけ
        void task() override;
};

class MicroRosNode : public MicroRos::Node{
    public:
        MicroRosNode(MicroRos::Support *support,const char *node_name,const char *name_space);

        void process();

        static MicroRosNode* _node; 
    private:
        // 使う機能を列挙する
        // 機能数制限
        // node:2 pub:10 sub:10 service:5 client:5 history:4
        MicroRosPublisher * publisher;
        MicroRosPublisher * publisher2;

        MicroRosSubscriber * subscriber;

        MicroRos::Executor *executor;
        MicroRos::Timer *timer;
};

class MicroRosPublisher : public MicroRos::Publisher{
    public:
        MicroRosPublisher(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support);

        std_msgs__msg__Int64 msg;

        void process();
        
    private:

};

class MicroRosSubscriber : public MicroRos::Subscriber{
    public:
        MicroRosSubscriber(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support);

        std_msgs__msg__Int64 msg;
        
    private:
        void callback(const void* msg) override;
        uint16_t count = 0;

};


#endif