#pragma once
#include <ESP32Servo.h>

#define LEFT_WHEEL_PIN 7
#define RIGHT_WHEEL_PIN 1
#define NECK_JOINT_PIN 8

class StackTank
{
private:
    Servo _leftWheel;
    Servo _rightWheel;
    Servo _neckJoint;
    int _leftWheelChannel;
    int _rightWheelChannel;

public:
    StackTank();
    void init();
    void lookUp();
    void lookDown();
    void lookNeutral();
    void lookRandom(int lower=30, int upper=80);
    void moveForward();
    void moveBackward();
    void turnLeft(int angle);
    void turnRight(int angle);
    void stop();
};  