#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor=9;
int state= LOW;
int val=0;
int buzzer=7;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Durum");
}

void loop() {
  val= digitalRead(sensor);
  if(val==HIGH){
  	delay(100);
    if(state==LOW){
      lcd.setCursor(0,1);
      lcd.print("Hareket algilandi");
      digitalWrite(buzzer, HIGH);
      state=HIGH;
    }
  }
  else{
  	delay(100);
    if(state==HIGH){
      lcd.setCursor(0, 1);
      lcd.print("Hareket durdu");
      digitalWrite(buzzer, LOW);
      state=LOW;
    }
  }
}
 
