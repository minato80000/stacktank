#include <Arduino.h>
#include <STServo.h>

namespace STServo
{
   ServoWheel::ServoWheel()
   {
   }
   void ServoWheel::attach(int pin, int channel)
   {
      _pin = pin;
      _channel = channel;
      ledcSetup(_channel, 50, 16); // 50Hz (20ms周期) で16bitの分解能でPWMを設定
      ledcAttachPin(_pin, _channel);
   }

   void ServoWheel::detach()
   {
      ledcDetachPin(_pin);
   }

   void ServoWheel::driveCW()
   {
      ledcWrite(_channel, 255);
   }

   void ServoWheel::driveCCW()
   {
      ledcWrite(_channel, 10);
   }

   void ServoWheel::stop()
   {
      ledcWrite(_channel, 0);
   }

   ServoJoint::ServoJoint()
   {
      _pin = -1;
      _channel = -1;
   }

   void ServoJoint::attach(int pin, int channel)
   {
      _pin = pin;
      _channel = channel;
      // 50Hz (20ms周期) で16bitの分解能でPWMを設定
      ledcSetup(_channel, 50, 16);
      ledcAttachPin(_pin, _channel);
   }

   void ServoJoint::detach()
   {
      if (_pin >= 0)
      {
         ledcDetachPin(_pin);
      }
   }

   void ServoJoint::moveTo(int angle)
   {
      // 角度を500μs～2500μsのパルス幅に変換
      // 0度: 500μs, 180度: 2500μs
      int pulseWidth = map(angle, 0, 180, 500, 2500);
      writeMicroseconds(pulseWidth);
   }

   void ServoJoint::writeMicroseconds(int microseconds)
   {
      if (_channel >= 0)
      {
         // 20ms (20000μs) 周期での duty cycle を計算
         // 16bit分解能 (65536) での値に変換
         int dutyCycle = map(microseconds, 0, 20000, 0, 65535);
         ledcWrite(_channel, dutyCycle);
      }
   }

}
