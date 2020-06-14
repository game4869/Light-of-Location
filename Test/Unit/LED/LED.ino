int led = 13;
char key = '0' ;
void setup()
{
  Serial.begin(9600);
  Serial.println(" please Enter Number 0,1,2 ");
  pinMode(led, OUTPUT); // ตั้งขา led ให้เป็นโหมด OUTPUT
  //digitalWrite(led, 0); // สั่งให้ LED ดับ
}
void loop()
{
  if (Serial.available() > 0) { //เมื่อมีข้อมูลส่งมาทาง Serial ให้ทำ...
    key = Serial.read(); //อ่านค่ามาไว้ในตัวแปร key

    if (key == '0') { //ถ้าพิมพ์ค่า 0 ให้ทำ...
      digitalWrite(led, 0); // สั่งปิดไฟ led
      Serial.println("LED OFF");
    } else if (key == '1') { //ถ้าพิมพ์ 1 เข้ามา ให้ทำ...
      digitalWrite(led, 1); // เปิดไฟ LED
      Serial.println("LED ON");
    } else if (key == '2') { //ถ้าพิมพ์ 2 เข้ามา ให้ทำ...
      Serial.println(" END ");
    }
  }
}