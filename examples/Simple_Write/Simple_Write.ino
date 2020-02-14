#include <Wire.h>
#include <AD5627.h>

#define ADDRESS 0x0C // I2C Address of the DAC

AD5627 DAC(ADDRESS, 3.3); // 3.3 is the reference voltage of the DAC

int i;

void setup(){
  Wire.begin();
}

// This loop generates a 3.3v saw-tooth wave on both outputs
void loop(){
  i++; 
  DAC.writeA((float)i / 100.0);
  DAC.writeB((float)i / 100.0);
  if (i > 329) i = -1;
}
