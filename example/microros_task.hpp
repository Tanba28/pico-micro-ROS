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

class MicroRosTask : public TaskBase{
    public:
        MicroRosTask(const char *_node_name, const char *_name_space);

        std_msgs__msg__Float32 msg;
        
        void publish();

    private:
        MicroRosContext *context;
        MicroRosNode *node;
        MicroRosPublisher *publisher;

        const char *node_name;
        const char *name_space;

        void task() override;
};
#endif