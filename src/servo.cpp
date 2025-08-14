#include <Servo.h>

namespace STServo
{
    ServoWheel::ServoWheel() : _pin(-1) {}
    void ServoWheel::attach(int pin)
    {
        _pin = pin;
    }

    ServoJoint::ServoJoint() : _pin(-1) {}

    void ServoJoint::attach(int pin)
    {
        _pin = pin;
    }

}
