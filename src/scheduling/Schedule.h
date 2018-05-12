/**
 * @brief: Water-it: Software for automated flower watering
 * @file: Schedule.h
 * @author: Tom Svoboda
 * @date: 8. 5. 2018
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <chrono>

namespace Scheduling {

/**
 * Schedule object
 */
class Schedule {
public:
    Schedule();

    /**
     * Set start of schedule
     * @param point Timepoint of start
     */
    void setStart(std::chrono::system_clock::time_point point);

    /**
     * Set duration in milliseconds
     * @param ms Millisecodns duration
     */
    void setDuration(unsigned ms);

    /**
     * Returns start of schedule
     * @return Start point
     */
    std::chrono::system_clock::time_point getStart();

    /**
     * Returns duration in milliseconds
     * @return Duration in milliseconds
     */
    unsigned getDuration();

protected:
    std::chrono::system_clock::time_point start;
    unsigned duration; /** < Duration in milliseconds */
};

}

#endif // SCHEDULE_H
