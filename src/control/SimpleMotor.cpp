/**
 * @brief: Water-it: Software for automated flower watering
 * @file: SimpleMotor.cpp
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#include "SimpleMotor.h"

using namespace Control;

SimpleMotor::SimpleMotor(Gpio::Output pin) :
    pin(pin)
{
    running = false;
}

SimpleMotor::~SimpleMotor() {
}

bool SimpleMotor::isRunning() {
    return running;
}


void SimpleMotor::on() {
    pin.on();
    startTimePoint = std::chrono::system_clock::now();
}

void SimpleMotor::off() {
    pin.off();
}

unsigned SimpleMotor::getRuntime() {
    if(isRunning()) {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - startTimePoint).count();
    }
    else {
        return 0;
    }
}
