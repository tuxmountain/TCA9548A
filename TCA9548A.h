// TCA9548A.h

#ifndef TCA9548A_h
#define TCA9548A_h

#include "Arduino.h"
#include <Wire.h>

class TCA9548A {
public:
    TCA9548A(uint8_t address); // Select the right I2C address for the multiplexer
    void selectChannel(uint8_t channel); // Create a public function to change channel

private:
    uint8_t _address; // Adresse I2C 
};

#endif


