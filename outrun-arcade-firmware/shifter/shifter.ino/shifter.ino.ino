#include <Keyboard.h>

// Pin definitions
const int buttonPinB = 7;  // Maps to XBOX B
const int buttonPinX = 4;  // Maps to XBOX X

// Button states
bool lastButtonStateB = HIGH;
bool lastButtonStateX = HIGH;

void setup() {
  pinMode(buttonPinB, INPUT_PULLUP);  // Using internal pull-up resistor
  pinMode(buttonPinX, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  // Read button states
  bool buttonStateB = digitalRead(buttonPinB);
  bool buttonStateX = digitalRead(buttonPinX);

  // Handle Button B (pin 4)
  if (buttonStateB == LOW && lastButtonStateB == HIGH) {
    Keyboard.press('b');
  } else if (buttonStateB == HIGH && lastButtonStateB == LOW) {
    Keyboard.release('b');
  }
  lastButtonStateB = buttonStateB;

  // Handle Button X (pin 7)
  if (buttonStateX == LOW && lastButtonStateX == HIGH) {
    Keyboard.press('x');
  } else if (buttonStateX == HIGH && lastButtonStateX == LOW) {
    Keyboard.release('x');
  }
  lastButtonStateX = buttonStateX;

  delay(10);  // Debounce delay
}
