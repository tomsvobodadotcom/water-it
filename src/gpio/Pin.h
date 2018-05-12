/**
 * @brief: Water-it: Software for automated flower watering
 * @file: Pin.h
 * @author: Tom Svoboda
 * @date: 22. 4. 2018
 */

#ifndef PIN_H
#define PIN_H

namespace Gpio {

/**
 * Abstract pin class for assinging pins to different Raspberries
 */
class Pin {
public:
    Pin(unsigned pinN) : pinN(pinN) {};
    operator unsigned() {return pinN;};
    
protected:
    unsigned pinN;
};

/**
 * Raspberry Pi Zero pins
 */
class RpiZeroPin : Pin {
    public:
        static constexpr unsigned GPIO2 = 3;
        static constexpr unsigned GPIO3 = 5;
        static constexpr unsigned GPIO4 = 7;
        static constexpr unsigned GPIO5 = 29;
        static constexpr unsigned GPIO6 = 31;
        static constexpr unsigned GPIO7 = 26;
        static constexpr unsigned GPIO8 = 24;
        static constexpr unsigned GPIO9 = 21;
        static constexpr unsigned GPIO10 = 19;
        static constexpr unsigned GPIO11 = 23;
        static constexpr unsigned GPIO12 = 32;
        static constexpr unsigned GPIO13 = 33;
        static constexpr unsigned GPIO14 = 8;
        static constexpr unsigned GPIO15 = 10;
        static constexpr unsigned GPIO16 = 36;
        static constexpr unsigned GPIO17 = 11;
        static constexpr unsigned GPIO18 = 12;
        static constexpr unsigned GPIO19 = 35;
        static constexpr unsigned GPIO20 = 38;
        static constexpr unsigned GPIO21 = 40;
        static constexpr unsigned GPIO22 = 15;
        static constexpr unsigned GPIO23 = 16;
        static constexpr unsigned GPIO24 = 18;
        static constexpr unsigned GPIO25 = 22;
        static constexpr unsigned GPIO26 = 67;
        static constexpr unsigned GPIO27 = 13;
    };

}
    
#endif /* PIN_H */