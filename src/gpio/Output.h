/**
 * @brief: Water-it: Software for automated flower watering
 * @file: pin.h
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#ifndef OUTPUTGPIO_H
#define OUTPUTGPIO_H

#include "GpioBase.h"

namespace Gpio {

/**
 * Output GPIO pin class
 */
class Output : public GpioBase {
public:
    /**
     * Output gpio constructor
     * @param pin Pin object
     */
    Output(Pin pin);
    /**
     * Pin destructor
     */
    virtual ~Output();
    
    /**
     * Turn pin on
     * @return bool Result of operation
     */
    bool on();
    
    /**
     * Turn pin off
     * @return bool Result of operation
     */
    bool off();
    
private:
    /** Pin number*/
    unsigned pinN;
};

}

#endif /* OUTPUTGPIO_H */