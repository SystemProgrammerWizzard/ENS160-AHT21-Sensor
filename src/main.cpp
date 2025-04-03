#include <Arduino.h>
#include <Wire.h>
#include <ens160.hpp>
#include <aht21.hpp>

AHT21 aht21;
ENS160 ens160;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Wire.begin( 21,22);

  aht21.init();
  ens160.init();
}

void loop() {
  // put your main code here, to run repeatedly:

  
  aht21.get_value();
  aht21.display();
  float temp = aht21.get_temperature();
  float humidity = aht21.get_humidity();

  delay(1000);

  ens160.init();
  ens160.get_value(temp, humidity);
  ens160.display();
  delay(4000);
}