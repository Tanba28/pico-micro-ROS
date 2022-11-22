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

class FloatTalkerTask : public TaskBase{
    public:
        FloatTalkerTask(const char *_node_name, const char *_name_space, const char *_topic_name,SemaphoreHandle_t *_initializing_semaphor,MicroRosContext *context);

        std_msgs__msg__Float32 msg;
        std_msgs__msg__Float32 msg2;
        
        void publish();

    private:
        MicroRosNode *node;
        MicroRosPublisher *publisher;
        MicroRosPublisher *publisher2;

        const char *node_name;
        const char *name_space;
        const char *topic_name;

        SemaphoreHandle_t *initializing_semaphor;

        void task() override;
};
#endif