/*
  AD5627.h - Library for AD5627 DAC.
  Created by Adrian E. Schwizgebel, February 14, 2020.
*/

#ifndef AD5627_H
#define AD5627_H

#include <Arduino.h>
#include <Wire.h>

class AD5627{
  private:
    byte _address;
    float _ref_voltage;
    const int _CA1 = 0x18; // Command: DAC A one block write
    const int _CB1 = 0x19; // Command: DAC B one block write
    const int _CA2 = 0x58; // Command: DAC A multiple block write
    const int _CB2 = 0x59; // Command: DAC B multiple block write
    const int _CA3 = 0x00; // Command: DAC A using LDAC to update.
    const int _CB3 = 0x01; // Command: DAC B using LDAC to update.
  public:
    AD5627(byte address, float ref_voltage);
    void writeA(float v);
    void writeB(float v);
};

#endif
