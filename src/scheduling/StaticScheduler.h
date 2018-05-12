#ifndef STATIC_SCHEDULER_H
#define STATIC_SCHEDULER_H

#include "IScheduler.h"

#include <string>
#include <chrono>

namespace Scheduling {

/**
 * Static scheduler returning one same schedule
 */
class StaticScheduler : public IScheduler {
public:
    /**
     * Static scheduler constructor
     * @param startHour Hour to start
     * @param startMinute Minute to start
     * @param startSecond Second to start
     * @param durationMs Duration in milliseconds
     */
    StaticScheduler(unsigned startHour, unsigned startMinute, unsigned startSecond, unsigned durationMs);

    /**
     * Return current schedule
     * @param schedule Reference to schedule that will be settings
     * @return Success if schedule was set. If return FALSE, schedule is untouched.
     */
    bool getSchedule(Schedule &schedule) override;

    /**
     * Return boolean value if schedule is now performable
     * @param schedule Reference to schedule
     * @return Boolean value if gicen schedule is performable now
     */
    bool isPerformable(Schedule &schedule) override;

    /**
     * Say scheduler that schedule was performed
     * @param schedule Reference to performed schedule
     * @param status Status of performed schedule. True = fine, False = error while performation
     */
    void setPerformed(Schedule &schedule, bool status) override;

    /**
     * Scheduler destructor
     */
    ~StaticScheduler();

protected:
    unsigned startHour;
    unsigned startMinute;
    unsigned startSecond;
    unsigned durationMs;

    std::chrono::system_clock::time_point lastPerformance;
};

}

#endif //STATIC_SCHEDULER_H
