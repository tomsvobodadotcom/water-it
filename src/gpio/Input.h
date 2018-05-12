/**
 * @brief: Water-it: Software for automated flower watering
 * @file: InputGpio.h
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */

#ifndef INPUTGPIO_H
#define INPUTGPIO_H

#include "GpioBase.h"


namespace Gpio  {

/**
 * Input pin class
 */
class Input : public GpioBase {
public:
    /**
     * Input pin constructor
     * @param Pin pin Pin number
     */
    Input(Pin pin);
    /**
     * Input pin destructor
     */
    virtual ~Input();

};

}

#endif /* INPUTGPIO_H */

