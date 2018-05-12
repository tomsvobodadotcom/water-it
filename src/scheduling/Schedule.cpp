/**
 * @brief: Water-it: Software for automated flower watering
 * @file: Schedule.cpp
 * @author: Tom Svoboda
 * @date: 8. 5. 2018
 */

#include "Schedule.h"

using namespace Scheduling;

Schedule::Schedule() :
    start( std::chrono::system_clock::now() ),
    duration(0u)
{}

/**
 * Set start of schedule
 * @param start Timepoint of start
 */
void Schedule::setStart(std::chrono::system_clock::time_point point) {
    start = point;
}

/**
 * Set duration in milliseconds
 * @param ms Millisecodns duration
 */
void Schedule::setDuration(unsigned ms) {
    duration = ms;
}

/**
 * Returns start of schedule
 * @return Start point
 */
std::chrono::system_clock::time_point Schedule::getStart() {
    return start;
}

/**
 * Returns duration in milliseconds
 * @return Duration in milliseconds
 */
unsigned Schedule::getDuration() {
    return duration;
}
