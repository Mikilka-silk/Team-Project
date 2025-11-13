#include <Arduino.h>

// Define LED and BUTTON pins numbers
#define LED_PIN 12
#define BUTTON_PIN 26

// Global variables to track state and time
int buttonState;
int lastButtonState = HIGH;  
unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;


void setup() {
  // Set the LED pin as an output pin
  pinMode(LED_PIN, OUTPUT);
  // Set the button pin as an input pin
  pinMode(BUTTON_PIN, INPUT);
}


void loop() {
  // Read the state of the button
  int reading = digitalRead(BUTTON_PIN);

  // Check if the button state has changed
  if (reading != lastButtonState) {
    // Reset the debounce timer
    lastDebounceTime = millis();
  }

  // Check if the debounce delay has passed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Check if the button state has stabilized
    if (reading != buttonState) {
      buttonState = reading;
      // If the button has been pressed, toggle the LED
      if (buttonState == LOW) {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      }
    }
  }

  // Update the last button state
  lastButtonState = reading;
}
