#include "LiquidCrystal.h"
LiquidCrystal lcd(9,8,7,6,5,4);

int GAS_VAL = 0;

void setup()
{
  pinMode(A0, INPUT); // MQ-6 A0 Pin
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(11,OUTPUT); // LED Green
  pinMode(12,OUTPUT); // LED Red
  
  lcd.setCursor(0,0);
  lcd.print("   GAS SENSOR  ");
 
}

void loop()
{
  GAS_VAL = analogRead(A0);
  Serial.println(GAS_VAL);


 if (GAS_VAL > 500)
 {
    lcd.setCursor(0,1);
    lcd.print("  LPG Detected    ");
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  
  else
 {
     lcd.setCursor(0,1);
     lcd.print("LPG Not Detected    ");
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
  }
  
  delay(10); 
}