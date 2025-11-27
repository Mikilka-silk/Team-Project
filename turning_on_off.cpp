#include <Arduino.h>

#define LED_PIN 12
#define BUTTON_PIN 26

int buttonState;
int lastButtonState = HIGH;  
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;


bool checkButton();


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(115200);
  Serial.println("System is ready. Press the button");
}


void loop() {
  if (checkButton()) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    Serial.println("The button is pressed");
  }
}


bool checkButton() {
    int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
      
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        lastButtonState = reading;
        return true;
      }
    }
  }

  lastButtonState = reading;

  return false;
}