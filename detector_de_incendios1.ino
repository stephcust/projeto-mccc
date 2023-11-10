#include <LiquidCrystal.h>
LiquidCrystal lcd (12,11,5,4,3,2);

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.begin (16,2);
  //Serial.begin(9600);
}

void loop()
{
  //deteccao de temperatura
  float tensao = analogRead(A1)*5.0/1023;
  int temp = round((tensao - 0.5)*100);
  
  //deteccao de fumaca
  float fumaca = analogRead(A0);
  if(fumaca > 600) {
	digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(1000);
  } else {
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  lcd.clear();
  lcd.print("Temperatura:");
  lcd.setCursor (0,1);
  lcd.print (temp);
  lcd.write(B10110010);
  lcd.write("C");
  delay(500);
  
  //Serial.println(fumaca);
  //Serial.println(temp);
  delay(10); 
}