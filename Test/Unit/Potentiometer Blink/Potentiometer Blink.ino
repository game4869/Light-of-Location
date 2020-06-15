#include <Wire.h>
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd (0x3f,16,2);
void setup() {
    lcd.init();
    lcd.backlight();
}

void loop() {
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
}