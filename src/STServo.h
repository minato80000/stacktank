#pragma once
#include <ESP32Servo.h>

namespace STServo
{

    class ServoWheel
    {
    private:
        int _pin;
        int _channel;

    public:
        ServoWheel();
        void attach(int pin, int channel);
        void detach();
        void driveCW();
        void driveCCW();
        void stop();
        
    };

    class ServoJoint
    {
    private:
        int _pin;
        int _channel;

    public:
        ServoJoint();
        void attach(int pin, int channel);
        void detach();
        void moveTo(int angle);
        void writeMicroseconds(int microseconds);
    };
}