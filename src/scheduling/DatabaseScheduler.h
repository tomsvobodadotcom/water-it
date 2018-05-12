#ifndef DATABASE_SCHEDULER_H
#define DATABASE_SCHEDULER_H

namespace Scheduling {

/**
 * Scheduler that fetch current values from MySql database
 */
class DatabaseScheduler : public IScheduler {
public:
    /**
     * Database scheduler constructor
     */
    DatabaseScheduler();

    /**
     * Return current schedule
     * @param schedule Reference to schedule that will be settings
     * @return Success if schedule was set. If return FALSE, schedule is untouched.
     */
    bool getSchedule(Schedule &schedule) override;

    /**
     * Scheduler destructor
     */
    ~DatabaseScheduler();

    /*
     * @TODO more!
     */
};

}

#endif // DATABASE_SCHEDULER_H
