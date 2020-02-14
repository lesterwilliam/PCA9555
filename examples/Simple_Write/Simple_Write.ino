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
  
  Expander.setOutput(0);
  Expander.setOutput(1);
  Expander.setOutput(2);
  Expander.setOutput(3);
  Expander.setOutput(7);
  Expander.setOutput(8);
  Expander.setOutput(13);
  Expander.setOutput(14);
  Expander.setOutput(15);
  delay(1000);
  Expander.readAll();
  delay(1000);

  Expander.clearOutput(0);
  Expander.clearOutput(1);
  Expander.clearOutput(2);
  Expander.clearOutput(3);
  Expander.clearOutput(7);
  Expander.clearOutput(8);
  Expander.clearOutput(13);
  Expander.clearOutput(14);
  Expander.clearOutput(15);
  delay(1000);
  //Expander.setOutput(pin);
  Expander.readAll();
  //delay(3000);
  //Expander.clearOutput(pin);
  //Expander.readAll();
  delay(1000);
}
