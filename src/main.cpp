#include <Arduino.h>
#include "Avatar.h"
#include "StackTank.h"

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
  M5.update();
}