const int redPin = 11;
const int yellowPin = 10;
const int greenPin = 9;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);




void setup() {
  Serial.begin(9600);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {

  

  if (Serial.available() > 0){
   String msg = Serial.readString();
   

   if (msg == "on"){
   
    lcd.setCursor(1, 0);
    lcd.clear();
    lcd.print("Yellow led is: " + msg);

    for (int i = 0; i <15; i++){
      digitalWrite(yellowPin, HIGH);
      delay(100);
      digitalWrite(yellowPin, LOW);
      delay(100);
      digitalWrite(yellowPin, HIGH);
      

     } }

   else if (msg == "off"){
    digitalWrite(yellowPin, LOW);
    lcd.setCursor(1, 0);
    lcd.clear();
    lcd.print("Yellow led is: " + msg);

   }
   
   else if (msg == "super"){
    lcd.setCursor(1, 0);
    lcd.clear();
    lcd.print(("Engaged ") + msg + (" mode!"));

    for (int i = 0; i <20; i++){
      digitalWrite(greenPin, HIGH);
      delay(100);
      digitalWrite(greenPin, LOW);
      delay(100);
    }

    }
  

   else if (msg == "exit"){
   lcd.setCursor(1, 0);
   lcd.clear();
   lcd.print("Exiting");

   }

   else {
    lcd.setCursor(1, 0);
    lcd.clear();
    lcd.print("Wrong Input");

    for (int i = 0; i <5; i++){
      digitalWrite(redPin, HIGH);
      delay(100);
      digitalWrite(redPin, LOW);
      delay(100);
      }
    }
  }
}
  
