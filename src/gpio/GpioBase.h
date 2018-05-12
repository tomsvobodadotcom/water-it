/**
 * @brief: Water-it: Software for automated flower watering
 * @file: GpioBase.h
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#ifndef GPIO_BASE_H
#define GPIO_BASE_H

#include "Pin.h"

namespace Gpio {

/**
 * Abstract pin class
 */
class GpioBase {
public:
    /**
     * Pin direction enum
     */
    enum class Direction {
        INPUT,
        OUTPUT
    };
    
    /**
     * Pin constructor
     * @param Pin pin Pin number
     * @param Direction direction Pin direction
     */
    GpioBase(Pin pin, Direction);
    virtual ~GpioBase();
    
    /**
     * Initialize Gpio pin
     * @throws std::runtime_error When cant open some gpio sysfs file
     * @return Boolean value as result of initialization
     */
    bool init();
    
    /**
     * Return true if pin is high
     * @return bool
     */
    bool isHigh();
    /**
     * Return true if pin is low
     * @return bool
     */
    bool isLow();
    /**
     * Return value of pin
     * @return Value: True=high, False=low
     */
    bool value();
    
    operator bool();
    
protected:
    Pin pin;
private:
    Direction direction;
};

}

#endif /* GPIO_BASE_H */

