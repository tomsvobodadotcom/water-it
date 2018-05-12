/**
 * @brief: Water-it: Software for automated flower watering
 * @file: SimpleMotor.h
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#ifndef SIMPLEMOTOR_H
#define SIMPLEMOTOR_H

#include "../gpio/Output.h"
#include <chrono>

namespace Control {

class SimpleMotor {
public:
    /**
     * Simple motor constructor
     * @param Gpio::Output pin Pin object
     */
    SimpleMotor(Gpio::Output pin);
    /**
     * Simplemotor destructor
     */
    virtual ~SimpleMotor();
    
    /**
     * Turn motor on
     */
    void on();

    /**
     * Turn motor off
     */
    void off();
    
    /**
     * Returns boolean value if motor is running
     * @return bool
     */
    inline bool isRunning();
    
    /**
     * Returns runtime in milliseconds
     * @return Runtime of motor in milliseconds. If motor is not running, returns 0
     */
    unsigned getRuntime();
    
private:
    Gpio::Output pin;
    bool running;
    std::chrono::system_clock::time_point startTimePoint;
};

}

#endif /* SIMPLEMOTOR_H */

