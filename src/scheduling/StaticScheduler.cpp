#include "StaticScheduler.h"
#include "../debug.h"

using namespace Scheduling;

/**
 * Static scheduler constructor
 * @param startHour Hour to start
 * @param startMinute Minute to start
 * @param startSecond Second to start
 * @param durationMs Duration in milliseconds
 */
StaticScheduler::StaticScheduler(unsigned startHour, unsigned startMinute, unsigned startSecond, unsigned durationMs) :
    startHour(startHour),
    startMinute(startMinute),
    startSecond(startSecond),
    durationMs(durationMs),
    lastPerformance( std::chrono::system_clock::now() )
{}

/**
 * Return current schedule
 * @param schedule Reference to schedule that will be settings
 * @return Success if schedule was set. If return FALSE, schedule is untouched.
 */
bool StaticScheduler::getSchedule(Schedule &schedule) {
    /* Get start date */
    std::time_t t = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
    std::tm tm = *std::localtime(&t);

    /* Set start time */
    tm.tm_hour = startHour;
    tm.tm_min  = startMinute;
    tm.tm_sec  = startSecond;

    std::chrono::system_clock::time_point startPoint = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    /* Set schedule */
    schedule.setStart(startPoint);
    schedule.setDuration(durationMs);

    return true;
}

/**
 * Return boolean value if schedule is now performable
 * @param schedule Reference to schedule
 * @return Boolean value if gicen schedule is performable now
 */
bool StaticScheduler::isPerformable(Schedule &schedule) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    if(schedule.getStart() >= now) {
        if(schedule.getStart() > lastPerformance) {
            DEBUG("StaticScheduler", "Schedule is ready to perform now");
            return true;
        }
    }

    return false;
}

/**
 * Say scheduler that schedule was performed
 * @param schedule Reference to performed schedule
 * @param status Status of performed schedule. True = fine, False = error while performation
 */
void StaticScheduler::setPerformed(Schedule &/*schedule*/, bool status) {
    lastPerformance = std::chrono::system_clock::now();
    DEBUG("StaticScheduler", "Schedule was performed with status " << (status ? "OK" : "FAIL"));
}

StaticScheduler::~StaticScheduler() {
}
