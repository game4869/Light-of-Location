#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27

#define BACKLIGHT_PIN 3


LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7);

void setup()
{
// lcd.begin (20,4); 
lcd.begin (16,2);

/* byte customChar0[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000
  };
  byte customChar1[8] = {
    0b11100,
    0b11100,
    0b11100,
    0b11111,
    0b11111,
    0b11111,
    0b11110,
    0b00000
  };
  lcd.createChar(1, customChar0);
  lcd.createChar(2, customChar1);*/
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // ไปที่ตัวอักษรที่ 0 แถวที่ 1

lcd.setCursor(1,0); // ไปทตัวอักษรที่ 1 แถวที่ 1
lcd.print("Light Intensity");

lcd.setCursor(3,1); // ไปที่ตัวอักษรที่ 5 แถวที่ 2
lcd.print("?????.?? LUX");
// lcd.write(1);
// lcd.write(2);

}

void loop()
{

}
