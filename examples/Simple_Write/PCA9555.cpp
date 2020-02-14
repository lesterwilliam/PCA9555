/*
  PCA9555.h - Library for PCA9555 16-bit port expander.
  Created by Adrian E. Schwizgebel, February 14, 2020.
*/

#include "PCA9555.h"

PCA9555::PCA9555(byte address, byte irq_pin){
  _address = address;
  _irq_pin = irq_pin;
}

void PCA9555::init(){
  Wire.beginTransmission(_address);  // setup out direction registers
  Wire.write(CONFIG_PORT_0_REG);  // pointer
  Wire.write(0x00);  // DDR Port0 all output 
  Wire.write(0x0F);  // DDR Port1 4-7 output
  Wire.endTransmission();
}

void PCA9555::toggle(byte _pin){
  Serial.print("Toggle pin:\t");
  Serial.println(_pin);
  Wire.beginTransmission(_address);
  if(_pin < 8){
    Wire.write(OUTPUT_PORT_0_REG);
    Wire.write(_value0 ^= 1UL << _pin);
  }else{
    Wire.write(OUTPUT_PORT_1_REG);
    Wire.write(_value1 ^= 1UL << (_pin - 8));
  }
  Wire.endTransmission();
}

void PCA9555::setOutput(byte _pin){
  Serial.print("Set pin:\t");
  Serial.println(_pin);
  Wire.beginTransmission(_address);
  if(_pin < 8){
    Wire.write(OUTPUT_PORT_0_REG); // begin here
    Wire.write(_value0 |= 1UL << _pin);
  }else{
    Wire.write(OUTPUT_PORT_1_REG); // begin here
    Wire.write(_value1 |= 1UL << (_pin - 8));
  }
  Wire.endTransmission();
}

void PCA9555::clearOutput(byte _pin){
  Serial.print("Clear pin:\t");
  Serial.println(_pin);
  Wire.beginTransmission(_address);
  if(_pin < 8){
    Wire.write(OUTPUT_PORT_0_REG); // begin here
    Wire.write(_value0 &= ~(1UL << _pin));
  }else{
    Wire.write(OUTPUT_PORT_1_REG); // begin here
    Wire.write(_value1 &= ~(1UL << (_pin - 8)));
  }
  Wire.endTransmission();
}
