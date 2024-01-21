#include <Wire.h>
#include "TCA9548A.h"
#define SDA_PIN 17 // Must be adapted to your needs
#define SCL_PIN 18 // Must be adapted to your needs
#define PWR 3          // Mofset to activate and desactivate 3V
#define BUZZER 46      // Buzzer

// Creating the multiplexer object
TCA9548A multiplexer(0x70); // Replace 0x70 with the I2C address of your multiplexer
// Multiple multiplexers can be added in sequence!

void setup() {
  USBSerial.begin(115200);
  pinMode(PWR, OUTPUT);
  digitalWrite(PWR, HIGH);
  delay(500);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(BUZZER, LOW);
  Wire.begin(SDA_PIN, SCL_PIN); // Initialize I2C communication, don't forget to adjust the SDA or SCL pin according to your configuration
  delay(200);
  USBSerial.println("Testing the TCA9548A library");
  USBSerial.println("This code will query each channel of the multiplexer to search for connected devices and display their I2C numbers");
}

void loop() {
  for (int Channel = 0; Channel < 8; Channel++) {

      TCA9548A.selectChannel(Channel); // Change communication channel
      
      byte error, address;
      int nDevices;
      USBSerial.println("Scanning...please wait a moment");
      delay(100);
      nDevices = 0;
      for (address = 1; address < 127; address++) {
        Wire.beginTransmission(address);
        delay(50);
        error = Wire.endTransmission();
        if (error == 0) {
          USBSerial.print("I2C device found at address 0x");
          if (address < 16)
            USBSerial.print("0");
          USBSerial.print(address, HEX);
          USBSerial.print(" on channel ");
          USBSerial.print(Channel);
          USBSerial.println(" of the multiplexer TCA9548");
          nDevices++;
          delay(50);
        } else if (error == 4) {
          USBSerial.print("Unknown error at address 0x");
          if (address < 16)
            USBSerial.print("0");
          USBSerial.println(address, HEX);
        }
      }
      if (nDevices == 0)
        USBSerial.println("No I2C devices found");
      else
        USBSerial.println("You have found some addresses, everything seems to be working properly, let's move to the next channel!");

      delay(100);
  }
}
