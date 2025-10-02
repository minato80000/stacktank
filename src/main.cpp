#include <Arduino.h>
#include "Avatar.h"
#include "StackTank.h"
#include "STServo.h"
#include <ESP32Servo.h>

Servo fs90r;
const int SERVO_PIN = 7;

m5avatar::Avatar avatar;
StackTank stacktank;

void setup()
{
  Serial.begin(115200);
  M5.begin();
  avatar.init(8);
  stacktank.init();
}

void loop()
{
  stacktank.moveForward();
  delay(1000);
  stacktank.stop();
  delay(1000);
  stacktank.moveBackward();
  delay(1000);
  stacktank.stop();
  delay(1000);

  if (M5.BtnA.wasPressed())
  {
  }

  if (M5.BtnB.wasPressed())
  {
  }

  if (M5.BtnC.wasPressed())
  {
  }
  M5.update();
}