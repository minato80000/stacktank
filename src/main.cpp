#include <Arduino.h>
#include "Avatar.h"
#include "StackTank.h"
#include "STBLE.h"
#include "move_test.h"


m5avatar::Avatar avatar;
StackTank stacktank;

void lookRandomMode()
{
  avatar.setSpeechText("look random");
  for (;;)
  {
    M5.update();
    if (M5.BtnA.wasPressed())
    {
      avatar.setSpeechText("");//長押ししないと止まらないので要改善
      break;
    }
    int turnAngle = random(45);
    int delaytime = random(10);

    stacktank.lookRandom(30, 80);
    stacktank.turnLeft(turnAngle);
    delay(5000 + 500 * delaytime);

    stacktank.lookRandom(30, 80);
    stacktank.turnRight(turnAngle);
    delay(5000 + 500 * delaytime);
  }
}

void controlMode()
{
  avatar.setSpeechText("control mode");
  for (;;)
  {
    M5.update();
    if (M5.BtnB.wasPressed())
    {
      avatar.setSpeechText("");//長押ししないと止まらないので要改善
      break;
    }
    
  }
}

void setup()
{
  Serial.begin(115200);
  M5.begin();
  avatar.init(8);
  stacktank.init();
  setupBLE();
}

void loop()
{
  M5.update();
  if (M5.BtnA.wasPressed())
  {
    lookRandomMode();
  }
  if (M5.BtnB.wasPressed())
  {
    controlMode();
  }
  if (M5.BtnC.wasPressed())
  {
    stacktank.lookNeutral();
  }
}