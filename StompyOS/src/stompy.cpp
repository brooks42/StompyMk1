
#include <Arduino.h>
#include <Servo.h>
#include "ik.h"

// servo pins (lfe = Left Front Elbow, rbs = Right Back Shoulder, etc)
const int lfePin = 1;
const int lfsPin = 2;
const int lbePin = 3;
const int lbsPin = 4;
const int rfePin = 5;
const int rfsPin = 6;
const int rbePin = 7;
const int rbsPin = 8;

// all 8 servos...
Servo lfe, lfs, lbe, lbs, rfe, rfs, rbe, rbs;

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

// a quick test we can run on init to center our servos for maintenant
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

}
