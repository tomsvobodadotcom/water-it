/**
 * @brief: Water-it: Software for automated flower watering
 * @file: InputGpio.cpp
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */
#include "Input.h"

using namespace Gpio;

Input::Input(Pin pin) :
GpioBase(pin, GpioBase::Direction::INPUT)
{
}

Input::~Input() {
}
