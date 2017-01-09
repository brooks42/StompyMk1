
#include <Arduino.h>
#include <Servo.h>
#include "headlight.h"
#include "ik.h"

// servo pins (lfe = Left Front Elbow, rbs = Right Back Shoulder, etc)
const int lfePin = 30;
const int lfsPin = 31;
const int lbePin = 32;
const int lbsPin = 33;
const int rfePin = 34;
const int rfsPin = 35;
const int rbePin = 36;
const int rbsPin = 37;

// headlight pins -- these are not the final values!
const int lRed = 38;
const int lBlue = 39;
const int lGreen = 40;
const int rRed = 41;
const int rBlue = 42;
const int rGreen = 43;

// all 8 servos...
Servo lfe, lfs, lbe, lbs, rfe, rfs, rbe, rbs;
Headlight leftHeadlight(lRed, lBlue, lGreen);
Headlight rightHeadlight(rRed, rBlue, rGreen);

void initTest();

//
void setup() {
  Serial.begin(9600); // for debugging

  // attach the servos from the left side of the robot
  lfe.attach(lfePin, MIN_ELBOW_ROTATION, MAX_ELBOW_ROTATION);
  lfs.attach(lfsPin, MIN_SHOULDER_ROTATION, MAX_SHOULDER_ROTATION);
  lbe.attach(lbePin, MIN_ELBOW_ROTATION, MAX_ELBOW_ROTATION);
  lbs.attach(lbsPin, MIN_SHOULDER_ROTATION, MAX_SHOULDER_ROTATION);

  // now attach the right...
  rfe.attach(rfePin, MIN_ELBOW_ROTATION, MAX_ELBOW_ROTATION);
  rfs.attach(rfsPin, MIN_SHOULDER_ROTATION, MAX_SHOULDER_ROTATION);
  rbe.attach(rbePin, MIN_ELBOW_ROTATION, MAX_ELBOW_ROTATION);
  rbs.attach(rbsPin, MIN_SHOULDER_ROTATION, MAX_SHOULDER_ROTATION);

  initTest();
}

// a quick test we can run on init to center our servos for maintenance
void initTest() {
  lfe.write(90);
  lfs.write(90);
  lbe.write(90);
  lbs.write(90);
  rfe.write(90);
  rfs.write(90);
  rbe.write(90);
  rbs.write(90);
}

//
void loop() {
  // the rough idea would be:
  // doInput()
  // makeServoDecisions()
  // moveServos()

  // blink headlights for testing
  if (rightHeadlight.isOn) {
    rightHeadlight.turnOff();
  } else {
    rightHeadlight.turnOn(HIGH, HIGH, HIGH);
  }

  if (leftHeadlight.isOn) {
    leftHeadlight.turnOff();
  } else {
    leftHeadlight.turnOn(HIGH, HIGH, HIGH);
  }
}
