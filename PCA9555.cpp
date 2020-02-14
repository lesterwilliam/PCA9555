/*
  AD5627.h - Library for AD5627 DAC.
  Created by Adrian E. Schwizgebel, February 14, 2020.
*/

#include "AD5627.h"


AD5627::AD5627(byte address, float ref_voltage){
  _address = address;
  _ref_voltage = ref_voltage;
}

void AD5627::writeA(float v){
  Wire.beginTransmission(_address);
  Wire.write(_CA1);
  Wire.write(((int)(v*4096/_ref_voltage))>>4);
  Wire.write(((int)(v*4096/_ref_voltage))<<4 & 0xF0);
  Wire.endTransmission();
}

void AD5627::writeB(float v){
  Wire.beginTransmission(_address);
  Wire.write(_CB1);
  Wire.write(((int)(v*4096/_ref_voltage))>>4);
  Wire.write(((int)(v*4096/_ref_voltage))<<4 & 0xF0);
  Wire.endTransmission();
}
