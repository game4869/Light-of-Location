#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define I2C_ADDR 0x27
#define BACKLIGHT_PIN 3

#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);


int writeLedPin = 13 ;
int lightSensorPin = 0;
int num = 0 ;

int RECV_PIN = 12 ;
#define code1 0xFF30CF
#define code2 0xFF18E7
#define code3 0xFF7A85 
#define code0 0XFF6897
decode_results results;
IRrecv irrecv(RECV_PIN);


void setup() {
  Serial.begin(9600);
  LightSensor.begin();   
  irrecv.enableIRIn();
  pinMode(writeLedPin, OUTPUT);
 
  
}
void loop(){
  int analogvalue = analogRead(lightSensorPin);
  Serial.println(analogvalue);
  uint16_t lux = LightSensor.GetLightIntensity();
switch (num)
{
case 1 :

if(analogvalue < 50){            
    digitalWrite(writeLedPin, HIGH);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;
  } else if (analogvalue >= 50 && analogvalue <= 500) {
    digitalWrite(writeLedPin, HIGH);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;
  } else {
    digitalWrite(writeLedPin, HIGH);
  }
  delay(500);
  digitalWrite(writeLedPin, LOW);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;

case 2 :
if(analogvalue < 20){            
    digitalWrite(writeLedPin, LOW);
  } else if (analogvalue >= 20 && analogvalue <= 500) {
    digitalWrite(writeLedPin, HIGH);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;
  } else {
    digitalWrite(writeLedPin, HIGH);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;
  }
  delay(500);
  digitalWrite(writeLedPin, LOW);
    lcd.setCursor(2,0);
    lcd.print("Light Intensity");
    lcd.setCursor(0,1);
    lcd.print("............");
    delay(1000);
    lcd.clear();
    delay(500);
    break;
}
}
