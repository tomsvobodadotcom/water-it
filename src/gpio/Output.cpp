/**
 * @brief: Water-it: Software for automated flower watering
 * @file: pin.cpp
 * @author: Tom Svoboda
 * @date: 20. 4. 2018
 */

#include "Output.h"
#include "../debug.h"
#include <fstream>

using namespace Gpio;

Output::Output(Pin pin)
: GpioBase(pin, GpioBase::Direction::OUTPUT)
{
}

Output::~Output() {
}

bool Output::on() {
    std::ofstream valueFile(std::string("/sys/class/gpio/gpio") + std::to_string((unsigned)pin) + "/value");

    if(!valueFile.is_open()) {
        throw std::runtime_error("Can't open Gpio value file");
    }

    valueFile << "1" << std::endl;

    DEBUG("Output", "Setting pin " << (unsigned)pin << " to state ON .. " << (valueFile.good() ? "OK" : "FAIL"));
    return valueFile.good();
}

bool Output::off() {
    std::ofstream valueFile(std::string("/sys/class/gpio/gpio") + std::to_string((unsigned)pin) + "/value");

    if(!valueFile.is_open()) {
        throw std::runtime_error("Can't open Gpio value file");
    }

    valueFile << "0" << std::endl;

    DEBUG("Output", "Setting pin " << (unsigned)pin << " to state OFF .. " << (valueFile.good() ? "OK" : "FAIL"));
    return valueFile.good();
}
