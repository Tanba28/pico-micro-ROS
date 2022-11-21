#ifndef FLOAT_TALKER
#define FLOAT_TALKER

#include "pico/stdlib.h"

#include <rcl/rcl.h>
#include <std_msgs/msg/float32.h>

#include <FreeRTOS.h>
#include <task.h>

#include "microros_base.hpp"

#include "task_base.hpp"

class FloatTalkerTask : public TaskBase{
    public:
        FloatTalkerTask();

        std_msgs__msg__Float32 msg;
        
        void publish();

    private:
        MicroRosPublisher *publisher;
        MicroRosTimer *timer;
        MicroRosExecutor *executor;

        void task() override;
};
#endif