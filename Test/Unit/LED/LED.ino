int ledPin13 = 13;

void setup() {
  pinMode(ledPin13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  for (int x = 0; x < 255; x++) {
    analogWrite(ledPin13, x);
    delay(10);
    Serial.println(x);
  }
  delay(500);
  for (int x = 255; x > 0; x--) {
    analogWrite(ledPin13, x);
    delay(10);
    Serial.println(x);
  }
  delay(500);

}
