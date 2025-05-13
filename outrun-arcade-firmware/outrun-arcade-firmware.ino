/*
* Outrun Arcade Controller - Xbox Controller Emulation
* Emulates standard Xbox controller inputs for Unity games
*/
#include "src/Joystick.h"

// Create a gamepad that mimics Xbox controller layout
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_GAMEPAD,
  0,     // No buttons for now
  0,     // No hat switch
  true,  // X axis (Left Stick horizontal)
  true,  // Y axis (Left Stick vertical)
  true,  // Z axis (Left Trigger)
  true,  // Rx axis (Right Stick horizontal)
  true,  // Ry axis (Right Stick vertical)  
  true,  // Rz axis (Right Trigger)
  false, // No rudder
  false, // No throttle
  false, // No accelerator
  false, // No brake
  false  // No steering
);

// Pin Input Constants
const int throttlePin = A1;
const int brakePin = A2;
const int steeringPin = A3;

// Input Mapping Constants
const int ANALOG_MIN = 0;
const int ANALOG_MAX = 1023;

void setup() {
  Serial.begin(9600);
  pinMode(throttlePin, INPUT);
  pinMode(brakePin, INPUT);
  pinMode(steeringPin, INPUT);
  
  // Xbox controller style ranges
  Joystick.setXAxisRange(0, 255);    // Left Stick X (0 = full left, 128 = center, 255 = full right)
  Joystick.setYAxisRange(0, 255);    // Left Stick Y (0 = full up, 128 = center, 255 = full down)
  Joystick.setZAxisRange(0, 255);    // Left Trigger (0 = released, 255 = fully pressed)
  Joystick.setRxAxisRange(0, 255);   // Right Stick X
  Joystick.setRyAxisRange(0, 255);   // Right Stick Y
  Joystick.setRzAxisRange(0, 255);   // Right Trigger (0 = released, 255 = fully pressed)
  
  // Initialize centered positions for sticks
  Joystick.setYAxis(128);   // Center left stick Y
  Joystick.setRxAxis(128);  // Center right stick X
  Joystick.setRyAxis(128);  // Center right stick Y
  
  Joystick.begin();
  
  Serial.println("Xbox-style gamepad initialized");
}

void loop() {
  // Read analog inputs
  int throttleRaw = analogRead(throttlePin);
  int brakeRaw = analogRead(brakePin);
  int steeringRaw = analogRead(steeringPin);
  
  // Map to Xbox controller ranges
  // Steering: Left Stick X (0-255, 128 center)
  int steeringValue = map(steeringRaw, ANALOG_MIN, ANALOG_MAX, 255, 0);
  
  // Right Trigger: throttle (0-255)
  int throttleValue = map(throttleRaw, ANALOG_MIN, ANALOG_MAX, 0, 255);
  
  // Left Trigger: brake (0-255)
  int brakeValue = map(brakeRaw, ANALOG_MIN, ANALOG_MAX, 0, 255);
  
  // Set the axes
  Joystick.setXAxis(steeringValue);   // Left Stick X (LS horizontal)
  Joystick.setZAxis(brakeValue);      // Left Trigger (LT)
  Joystick.setRzAxis(throttleValue);  // Right Trigger (RT)
  
  // Debug output
  Serial.print("LS-X: ");
  Serial.print(steeringValue);
  Serial.print(" | RT: ");
  Serial.print(throttleValue);
  Serial.print(" | LT: ");
  Serial.println(brakeValue);
  
  delay(5);
}