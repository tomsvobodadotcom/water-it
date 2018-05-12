/**
 * @brief: Water-it: Software for automated flower watering
 * @file: GpioBase.cpp
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#include "GpioBase.h"
#include "../debug.h"
#include <fstream>

using namespace Gpio;

GpioBase::GpioBase(Pin pin, Direction direction) :
    pin(pin),
    direction(direction)
{
}

GpioBase::~GpioBase() {
    DEBUG("GpioBase", "Unexporting pin " << (unsigned) pin);
    std::ofstream unexportFile("/sys/class/gpio/unexport");
    unexportFile << (unsigned)pin << std::endl;
}

bool GpioBase::init() {
    bool good = true;
    /* Export GPIO pin */
    std::ofstream exportFile("/sys/class/gpio/export");

    if(!exportFile.is_open()) {
        throw std::runtime_error("Cant open gpio export file");
    }

    exportFile << (unsigned) pin << std::endl;

    good = !exportFile.bad();
    exportFile.close();

    DEBUG("GpioBase", "Exporting pin " << (unsigned)pin << " .. " << (good ? "OK" : "FAIL"));

    /* Set pin direction */
    std::ofstream directionFile(std::string("/sys/class/gpio/gpio") + std::to_string((unsigned)pin) + "/direction");

    if(!directionFile.is_open()) {
        throw std::runtime_error("Cant open gpio direction file");
    }

    if(direction == Direction::INPUT) {
        directionFile << "in" << std::endl;
    }
    else {
        directionFile << "out" << std::endl;
    }

    good = good && !directionFile.bad();
    directionFile.close();

    DEBUG("GpioBase", "Initializing pin " << (unsigned)pin << " .. " << (good ? "OK" : "FAIL"));

    return good;
}

bool GpioBase::value() {
    std::ifstream valueFile(std::string("/sys/class/gpio/gpio") + std::to_string((unsigned)pin) + "/value");
    int value;

    if(!valueFile.is_open()) {
        throw std::runtime_error("Can't open gpio value file");
    }

    valueFile >> value;
    return value != 0;
}

bool GpioBase::isLow() {
    return value() == false;
}

bool GpioBase::isHigh() {
    return value() == true;
}

GpioBase::operator bool() {
    return value();
}
