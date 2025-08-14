#include <Arduino.h>
#include "Avatar.h"
#include "stacktank.h"

m5avatar::Avatar _avatar;
const m5avatar::Expression expressions[] = {m5avatar::Expression::Angry, m5avatar::Expression::Sleepy,
                                            m5avatar::Expression::Happy, m5avatar::Expression::Sad,
                                            m5avatar::Expression::Doubt, m5avatar::Expression::Neutral};

void setup()
{
  Serial.begin(115200);
  M5.begin();
  _avatar.init(8);
}

void loop()
{
  if(M5.BtnA.wasPressed()){

  }

  if(M5.BtnB.wasPressed()){

  }

  if(M5.BtnC.wasPressed()){

  }
}