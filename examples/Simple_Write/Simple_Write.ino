#include <Wire.h>
#include <PCA9555.h>

#define ADDRESS_IO 0x21 // I2C Address of the DAC

PCA9555 Expander(ADDRESS_IO, 2);

void setup(){
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Setup");

  Expander.init();
}

void loop(){
  for(int i = 0; i < 16; i++){
    Expander.toggle(i);
    Serial.print("\nRead expander:\t");
    Serial.println(Expander.readAll(), HEX);
    delay(1000);
  }
}
