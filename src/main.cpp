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
      avatar.setSpeechText(""); // 長押ししないと止まらないので要改善
      break;
    }
    int turnAngle = random(45);
    int delaytime = random(10);

    // stacktank.lookRandom(30, 80);
    stacktank.turnLeft(turnAngle);
    stacktank.turnRight(turnAngle);
    delay(2000 + 500 * delaytime);
  }
}



void setup()
{
  Serial.begin(115200);
  M5.begin();
  avatar.init(8);
  avatar.setBatteryIcon(true);
  stacktank.init();
  setupBLE();
}

void loop()
{
  M5.update();
  


  static uint32_t last = 0;
  if (millis() - last > 2000) // バッテリの状態更新
  {
    last = millis();
    const bool charging = M5.Power.isCharging();
    const int lvl = M5.Power.getBatteryLevel(); // 0,25,50,75,100等の段階
    avatar.setBatteryStatus(charging, lvl);
  }
}