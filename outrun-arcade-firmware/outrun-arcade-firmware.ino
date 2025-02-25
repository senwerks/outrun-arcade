/*
* Outrun Arcade Controller Firmware by Obsolete Nerd
* https://github.com/senwerks/outrun-arcade
*
* Throttle: 3-pin, VCC to Yellow/Black wire, GND to White/Blue wire, DATA to Blue wire. Wired to A1 on Pro Micro.
* Brake: 3-pin, VCC to Yellow/Green wire, GND to White/Green wire, DATA to Green wire. Wired to A2 on Pro Micro.
* Steering: 3-pin, VCC to Yellow/Red wire, GND to White/Red wire, DATA is Red wire. Wired to A3 on Pro Micro.
* Shifter: 2-pin, White and Blue. Not wired to Pro Micro yet.
*/

#include "src/Joystick.h"
/* Joystick library example code: https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/master/examples */

// Example constructor that enables throttle, brake, and steering
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID,
  JOYSTICK_TYPE_JOYSTICK,
  2,  // Button count (change as needed)
  0,  // Hat switch count
  false, // include X axis?
  false, // include Y axis?
  false, // include Z axis?
  false, // include Rx axis?
  false, // include Ry axis?
  false, // include Rz axis?
  false, // include rudder?
  true,  // include throttle?
  false, // include accelerator? (distinct from throttle)
  true,  // include brake?
  true   // include steering?
);

// Pin Input Constants
const int throttlePin = A1;
const int brakePin = A2;
const int steeringPin = A3;
const int shifterPin = 15; // Not connected or tested yet

// Input Mapping Constants
const int ANALOG_MIN = 0;
const int ANALOG_MAX = 1023;
const int MAPPED_MIN = 255;
const int MAPPED_MAX = 0;

int lastShifterState = 0;

// Helper function for reading, mapping, and updating a control
updateControl("Throttle", throttlePin, [](int value){ Joystick.setThrottle(value); });
    int rawValue = analogRead(pin);
    int mappedValue = map(rawValue, ANALOG_MIN, ANALOG_MAX, MAPPED_MIN, MAPPED_MAX);
    if (DEBUG) {
        Serial.print(label);
        Serial.print(" Raw: ");
        Serial.print(rawValue);
        Serial.print(", ");
        Serial.print("Mapped: ");
        Serial.println(mappedValue);
        Serial.print(", ");
    }
    updateFunc(mappedValue);
}

void setup() {
    Serial.begin(9600);
    pinMode(throttlePin, INPUT);
    pinMode(brakePin, INPUT);
    pinMode(steeringPin, INPUT);
    pinMode(shifterPin, INPUT_PULLUP);

    // Test with these functions instead of mapping
    // Joystick.setAcceleratorRange(0, 260);
    // Joystick.setBrakeRange(0, 260);
    // Joystick.setSteeringRange(0, 300);

    Joystick.begin();
}

void loop() {

    updateControl("Throttle", throttlePin, Joystick.setThrottle);
    updateControl("Brake", brakePin, Joystick.setBrake);
    updateControl("Steering", steeringPin, Joystick.setSteering);

    /* Shifter, untested on unit yet so not sure what values we need or what we're going to do with this bit */
    int switchState = digitalRead(shifterPin);
  
  // If switch is pressed => forward
  // If switch is not pressed => reverse
  if (switchState == LOW) {
    Joystick.setYAxis(255); // forward
  } else {
    Joystick.setYAxis(0);   // reverse
  }
    Serial.print("Shifter Value: ");
    Serial.println(switchState);
  
    delay(5); // small delay for switch stability
}
