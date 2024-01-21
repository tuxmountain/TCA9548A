// TCA9548A.cpp

#include "TCA9548A.h"

TCA9548A::TCA9548A(uint8_t address) {
    _address = address;
    // Initialisation supplémentaire si nécessaire
}

void TCA9548A::selectChannel(uint8_t channel) {
    Wire.beginTransmission(_address); // TCA9548A address is 0x70 but can be changed
    Wire.write(1 << channel); // send byte to select bus
    Wire.endTransmission();
}
