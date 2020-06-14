#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes); // กำหนดเซนเซอร์
void setup()
{
Serial.begin(9600);
LightSensor.begin(); // สั่งให้เซนเซอร์ทำงาน
}
void loop()
{
uint16_t lux = LightSensor.GetLightIntensity();
Serial.print(" Light:  ");
Serial.print(lux);
Serial.println("  lux ");
delay(250);
}