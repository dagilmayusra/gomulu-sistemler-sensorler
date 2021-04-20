
// include the library code:
#include <LiquidCrystal.h>

int trigPin=7;
int echoPin=6;
int sure;
int uzaklik;

// int rs=12 ,en=11 ,d4=5 ,d5=4 ,d6=3 ,d7=2 ;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);       
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  sure = pulseIn(echoPin, HIGH, 11000);
  //ses hızı 345.2 m/s
  uzaklik = sure*0.0345/2;  //gidiş geliş hızından dolayı 2 ye bölünür.
  
  lcd.clear();
  lcd.setCursor(0,0); //ekranın sol üstünden başlatır.
  lcd.print("Uzaklik: ");
  lcd.setCursor(0,1);
  lcd.print(uzaklik);
  lcd.print(" cm");
}
 
