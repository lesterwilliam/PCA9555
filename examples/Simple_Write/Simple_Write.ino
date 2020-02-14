#include <Wire.h>
#include "PCA9555.h"

#define ADDRESS_IO 0x21 // I2C Address of the DAC

PCA9555 Expander(ADDRESS_IO, 2);

void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Setup");

  Expander.init();
}

void loop(){
  int pin = 14;
  //Expander.toggle(pin);
  Expander.setOutput(pin);
  delay(1000);
  Expander.clearOutput(pin);
  delay(1000);
}
