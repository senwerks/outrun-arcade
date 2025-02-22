/*
* Outrun Arcade Controller Firmware by Obsolete Nerd
* https://github.com/senwerks/outrun-arcade
*
* Throttle: 3-pin, VCC to Yellow/Black wire, GND to White/Blue wire, DATA to Blue wire. Wired to A1 on Pro Micro.
* Brake: 3-pin, VCC to Yellow/Green wire, GND to White/Green wire, DATA to Green wire. Wired to A2 on Pro Micro.
* Steering: 3-pin, VCC to Yellow/Red wire, GND to White/Red wire, DATA is Red wire. Wired to A3 on Pro Micro.
* Shifter: 2-pin, White and Blue. Not wired to Pro Micro yet.
*/

#include "src/Joystick.h";
/* Joystick library example code: https://github.com/MHeironimus/ArduinoJoystickLibrary/tree/master/examples */

Joystick_ Joystick;

const int throttlePin = A1;
const int brakePin = A2;
const int steeringPin = A3;
const int shifterPin = 15; // Not connected or tested yet

int throttleVal;
int brakeVal;
int steeringVal;
int shifterVal;

int lastShifterState = 0;

void setup() {
    Serial.begin(9600);
    pinMode(throttlePin, INPUT);
    pinMode(brakePin, INPUT);
    pinMode(steeringPin, INPUT);
    pinMode(shifterPin, INPUT_PULLUP);

    // Change these if we want, instead of mapping them
    // Joystick.setAcceleratorRange(0, 260);
    // Joystick.setBrakeRange(0, 260);
    // Joystick.setSteeringRange(0, 300);

    Joystick.begin();
}

void loop() {
    /* Throttle */
    int throttleVal = analogRead(throttlePin);
    Serial.print("Throttle Raw: ");
    Serial.print(throttleVal);
    Serial.print(", ");
    int throttleMapped = map(throttleVal,0,1023,0,255);
    Serial.print("Throttle Mapped: ");
    Serial.print(throttleMapped);
    Serial.print(", ");
    Joystick.setThrottle(throttleMapped);

    /* Brakes */
    int brakeVal = analogRead(brakePin);
    Serial.print("Brake Raw: ");
    Serial.print(brakeVal);
    Serial.print(", ");
    int brakeMapped = map(brakeVal,0,1023,0,255);
    Serial.print("Brake Mapped: ");
    Serial.print(brakeMapped);
    Serial.print(", ");
    Joystick.setBrake(brakeMapped);
    //Joystick.setBrake(brakeVal);

    /* Steering */
    int steeringVal = analogRead(steeringPin);
    Serial.print("Steering Raw: ");
    Serial.print(steeringVal);
    Serial.print(", ");
    int steeringMapped = map(steeringVal,0,1023,0,255);
    Serial.print("Steering Mapped: ");
    Serial.print(steeringMapped);
    Serial.print(", ");
    Joystick.setSteering(steeringMapped);
    //Joystick.setSteering(steeringVal);

    /* Shifter, untested on unit yet so not sure what values we need or what we're going to do with this bit */
    int currentShifterState = !digitalRead(shifterPin);
	if (currentShifterState != lastShifterState) {
        Joystick.setButton(0, currentShifterState);
        lastShifterState = currentShifterState;
    }
    Serial.print("Shifter Value: ");
    Serial.println(currentShifterState);
}
