
#include <Arduino.h>
#include <Servo.h>

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

//
void setup() {
  Serial.begin(9600); // for debugging

  // attach the servos from the left side of the robot
  lfe.attach(lfePin);
  lfs.attach(lfsPin);
  lbe.attach(lbePin);
  lbs.attach(lbsPin);

  // now attach the right...
  rfe.attach(rfePin);
  rfs.attach(rfsPin);
  rbe.attach(rbePin);
  rbs.attach(rbsPin);
}

//
void loop() {

}
