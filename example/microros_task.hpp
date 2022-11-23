#ifndef FLOAT_TALKER
#define FLOAT_TALKER

#include "pico/stdlib.h"

#include <rcl/rcl.h>
#include <std_msgs/msg/float32.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "microros_base.hpp"

#include "task_base.hpp"

class MicroRosContoller;
class MicroRosNode;
class MicroRosPublisher;

class MicroRosController : public MicroRos::Context,TaskBase{
    public:
        MicroRosController();

    private:
        MicroRosNode *node;

        // microRos用スレッドはひとつだけ
        void task() override;
};

class MicroRosNode : public MicroRos::Node{
    public:
        MicroRosNode(MicroRos::Context *context,const char *node_name,const char *name_space);

        void nodeRun();

    private:
        MicroRosPublisher * publisher;
        MicroRosPublisher * publisher2;
};

class MicroRosPublisher : public MicroRos::Publisher{
    public:
        MicroRosPublisher(MicroRos::Node *node,const char *topic_name,const rosidl_message_type_support_t *type_support);

        std_msgs__msg__Float32 msg;

        void publishRun();
        
    private:

};
#endif