#include <LiquidCrystal.h>

int sensorPin = A0; 
int ledPin = 13; 
int sicaklik;

// int rs=12 ,en=11 ,d4=5 ,d5=4 ,d6=3 ,d7=2 ;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(ledPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("Sicaklik");
}

void loop() {
  sicaklik = ((analogRead(sensorPin)*4.88)-500)/10;
  if(sicaklik>100){
  	digitalWrite(ledPin, HIGH); 
    lcd.setCursor(0,1);
    lcd.print(" yuksek");
  }
  else{ 
    lcd.setCursor(0,1);
    lcd.print(" dusuk");
  } 
}
 
