#include "StackTank.h"

StackTank::StackTank()
{
}

void StackTank::init()
{
    _leftWheel.attach(LEFT_WHEEL_PIN, 700, 2300);
    _rightWheel.attach(RIGHT_WHEEL_PIN, 700, 2300);
    //_neckJoint.attach(NECK_JOINT_PIN, 500, 2400);
}

void StackTank::moveForward()
{
    _leftWheel.writeMicroseconds(2000);  // 左車輪を前進方向に回転
    _rightWheel.writeMicroseconds(1000); // 右車輪を前進方向に回転
}

void StackTank::moveBackward()
{
    _leftWheel.writeMicroseconds(1000);  // 左車輪を後退方向に回転
    _rightWheel.writeMicroseconds(2000); // 右車輪を後退方向に回転
}

void StackTank::turnLeft()
{
    _leftWheel.writeMicroseconds(1000);  // 左車輪を後退方向に回転
    _rightWheel.writeMicroseconds(1000); // 右車輪を前進方向に回転
}

void StackTank::turnRight()
{
    _leftWheel.writeMicroseconds(2000);  // 左車輪を前進方向に回転
    _rightWheel.writeMicroseconds(2000); // 右車輪を後退方向に回転
}

void StackTank::stop()
{
    _leftWheel.writeMicroseconds(1500);  // 左車輪を停止
    _rightWheel.writeMicroseconds(1500); // 右車輪を停止
}

