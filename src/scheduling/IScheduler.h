#ifndef ISCHEDULER_H
#define ISCHEDULER_H

#include "Schedule.h"

namespace Scheduling {

/**
 * Interface for scheduler
 */
class IScheduler {
public:

    /**
     * Return current schedule
     * @param schedule Reference to schedule that will be settings
     * @return Success if schedule was set. If return FALSE, referenced schedule is untouched.
     */
    virtual bool getSchedule(Schedule &schedule) = 0;

    /**
     * Return boolean value if schedule is now performable
     * @param schedule Reference to schedule
     * @return Boolean value if gicen schedule is performable now
     */
    virtual bool isPerformable(Schedule &schedule) = 0;

    /**
     * Say scheduler that schedule was performed
     * @param schedule Reference to performed schedule
     * @param status Status of performed schedule. True = fine, False = error while performation
     */
    virtual void setPerformed(Schedule &schedule, bool status) = 0;

    /**
     * Virtual destructor
     */
    virtual ~IScheduler() {};
};

}
#endif //ISCHEDULER_H
