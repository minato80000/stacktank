#pragma once
#include "Servo.h"

#define LEFT_WHEEL_PIN 22
#define RIGHT_WHEEL_PIN 20
#define NECK_JOINT_PIN 4

class StackTank
{
private:
    STServo::ServoWheel _leftWheel;
    STServo::ServoWheel _rightWheel;
    STServo::ServoJoint _neckJoint;

public:
};