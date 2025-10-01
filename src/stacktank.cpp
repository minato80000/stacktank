#include "StackTank.h"

StackTank::StackTank()
{
}

void StackTank::init()
{
    _leftWheel.attach(LEFT_WHEEL_PIN);
    _rightWheel.attach(RIGHT_WHEEL_PIN);
    _neckJoint.attach(NECK_JOINT_PIN);
}
