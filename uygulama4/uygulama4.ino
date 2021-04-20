#include <LiquidCrystal.h>

int led = 13; 

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(led, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("ISIK");
}

void loop() {
  int sensor = analogRead(A0);
  if(sensor>350){
  	digitalWrite(led, LOW); 
    lcd.setCursor(0,1);
    lcd.print(" sondu");
  }
  else{ 
    digitalWrite(led, HIGH); 
    lcd.setCursor(0,1);
    lcd.print(" yandi");
  } 
}
