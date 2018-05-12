/**
 * @brief: Water-it: Software for automated flower watering
 * @file: main.cpp
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#include "config.h"
#include "debug.h"
#include "scheduling/StaticScheduler.h"
#include "gpio/Pin.h"
#include "gpio/Output.h"

#include <chrono>
#include <thread>

void run() {
    /* Initialize scheduler */
    Scheduling::StaticScheduler scheduler(SSCHED_START_H, SSCHED_START_M, SSCHED_START_S, SSCHED_DURATION_MS);
    Scheduling::Schedule schedule;

    /* Initialize motor */
    Gpio::Output motor(PIN_MOTOR);
    motor.init();
    motor.off();

    /* Main control loop */
    for(;;) {
        bool haveSchedule = scheduler.getSchedule(schedule);

        if(haveSchedule) {
            if(scheduler.isPerformable(schedule)) {
                /* Perform */
                motor.on();
                std::this_thread::sleep_for(std::chrono::milliseconds( schedule.getDuration() ));
                motor.off();

                /* Set perform status */
                scheduler.setPerformed(schedule, true);
            }
        }

        /* Wait for next window */
        std::this_thread::sleep_for(std::chrono::seconds(LOOP_SLEEP_SEC));
    }
}

int main(/*int argc, char **argv*/) {
    DEBUG("main", "start");
    run();
    DEBUG("main", "exit");
    return 0;
}
