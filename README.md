# TCA9548A I2C Multiplexer Library

## Overview

The TCA9548A from Texas Instruments is a versatile I2C multiplexer that allows up to 8 I2C devices with the same address to be interconnected and managed. This library provides an easy and efficient way to integrate the TCA9548A multiplexer into your Arduino projects.

For more information about the TCA9548A, visit the Texas Instruments product page: [TCA9548A Multiplexer](https://www.ti.com/product/TCA9548A)

## Key Features

- **Multi-Channel Support**: Manages up to 8 I2C devices through a single multiplexer.
- **Easy Integration**: Simplifies the use of multiple I2C devices with identical addresses in one project.
- **I2C Communication**: Leverages the I2C protocol for communication, using the Arduino's Wire library.
- **Address Flexibility**: Supports the standard I2C address (0x70) for the TCA9548A, with options to change if needed.

## Usage

1. **Initialization**: Create a `TCA9548A` object by specifying its I2C address. For example, `TCA9548A multiplexer(0x70);`.
2. **Selecting a Channel**: Use `multiplexer.selectChannel(channelNumber);` to switch communication to the desired channel (0-7).
3. **Communicating with Devices**: After selecting a channel, communicate with the connected I2C device as usual using the Wire library.

## Example

```cpp
#include <Wire.h>
#include "TCA9548A.h"

TCA9548A multiplexer(0x70); // Initialize the multiplexer at address 0x70

void setup() {
    Wire.begin();
    multiplexer.selectChannel(0); // Select channel 0
    // Communicate with the device connected to channel 0
}

void loop() {
    // Your loop code here
}
```

## Future Development

Future updates may include enhanced features like automatic channel scanning and improved error handling.

## Important Note

Ensure that the TCA9548A multiplexer is properly connected to your Arduino's I2C bus, and that the power supply and logic levels are compatible.


