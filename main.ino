#include <LiquidCrystal.h>

#DEFINE rs = 9;
#DEFINE en = 8;
#DEFINE d4 = 5;
#DEFINE d5 = 4;
#DEFINE d6 = 3;
#DEFINE d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#DEFINE buttonPin = 10;  // PB2
#DEFINE outputPin = 12;  // PD6

bool buttonPressed = false;
unsigned long startTime = 0;
const int duration = 10000;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Estado: Desligado");
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    startTime = millis();
    digitalWrite(outputPin, HIGH);
    lcd.clear();
    lcd.print("Estado: Ligado");
  }
  
  if (buttonPressed) {
    unsigned long elapsedTime = millis() - startTime;
    unsigned long timeRemaining = (duration - elapsedTime) / 1000;

    lcd.setCursor(0, 1);
    lcd.print("Tempo: ");
    lcd.print(timeRemaining);
    lcd.print("s");

    if (elapsedTime >= duration) {
      digitalWrite(outputPin, LOW);
      buttonPressed = false;
      lcd.clear();
      lcd.print("Estado: Desligado");
    }
  }
}
