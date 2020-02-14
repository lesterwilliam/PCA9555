/*
  PCA9555.h - Library for PCA9555 16-bit port expander.
  Created by Adrian E. Schwizgebel, February 14, 2020.
*/

#ifndef PCA9555_H
#define PCA9555_H

#include <Arduino.h>
#include <Wire.h>

class PCA9555{
  private:
    byte _address;
    byte _value0;
    byte _value1;
    byte _irq_pin;
    const int INPUT_PORT_0_REG = 0x00;
    const int INPUT_PORT_1_REG = 0x01;
    const int OUTPUT_PORT_0_REG = 0x02; //0 = LOW, 1 = HIGH
    const int OUTPUT_PORT_1_REG = 0x03; //0 = LOW, 1 = HIGH
    const int POLARITY_INVERSION_PORT_0_REG = 0x04; //0 = no inversion, 1 = input inversion
    const int POLARITY_INVERSION_PORT_1_REG = 0x05; //0 = no inversion, 1 = input inversion
    const int CONFIG_PORT_0_REG = 0x06; //0 = ouput, 1 = input (default at reset is input)
    const int CONFIG_PORT_1_REG = 0x07; //0 = ouput, 1 = input (default at reset is input)
    
  public:
    PCA9555(byte address, byte irq_pin);
    void init();
    void toggle(byte pin);
    void setOutput(byte pin);
    void clearOutput(byte pin);
};

#endif
