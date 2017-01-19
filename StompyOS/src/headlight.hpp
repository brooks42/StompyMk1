#include <Arduino.h>

#ifndef __HEADLIGHT__
#define __HEADLIGHT__

typedef struct {
    int redPin, bluePin, greenPin; // pins for the different colors of the LED
} headlight_t;

// definition for a turned off lamp color
#define HEADLIGHT_OFF 0

/*
Defines the Headlight class which controls a single LED.
*/
class Headlight {
public:

  // LED this headlight controls
  headlight_t led;
  bool isOn;

  // constructor that takes the pin layout
  Headlight(int redPin, int bluePin, int greenPin) {
    led.redPin = redPin;
    led.bluePin = bluePin;
    led.greenPin = greenPin;
    pinMode(redPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    isOn = false;
  };

  // this kills the light
  void turnOff() {
    digitalWrite(led.redPin, HEADLIGHT_OFF);
    digitalWrite(led.bluePin, HEADLIGHT_OFF);
    digitalWrite(led.greenPin, HEADLIGHT_OFF);
    isOn = false;
  };

  // turns on the various colors of this light
  //
  void turnOn(uint8_t red, uint8_t blue, uint8_t green) {
    if (red == HEADLIGHT_OFF && blue == HEADLIGHT_OFF && green == HEADLIGHT_OFF) {
      turnOff();
      return;
    }
    digitalWrite(led.redPin, red);
    digitalWrite(led.bluePin, blue);
    digitalWrite(led.greenPin, green);
    isOn = true;
  };
};

#endif
