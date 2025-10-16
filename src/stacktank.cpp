#include "StackTank.h"
#include <Arduino.h>

StackTank::StackTank()
{
}

void StackTank::init()
{
    _leftWheelChannel = _leftWheel.attach(LEFT_WHEEL_PIN, 500, 2400);
    _rightWheelChannel = _rightWheel.attach(RIGHT_WHEEL_PIN, 500, 2400);
    _neckJoint.attach(NECK_JOINT_PIN, 500, 2400);
    lookNeutral(); // 首を中立位置に設定
}

void StackTank::lookDown()
{
    _neckJoint.write(80); // 首を下に向ける
}

void StackTank::lookUp()
{
    _neckJoint.write(30); // 首を上に向ける
}

void StackTank::lookNeutral()
{
    _neckJoint.write(45); // 首を中立位置に戻す
}

void StackTank::lookRandom(int lower, int upper)
{
    int angle = random(lower, upper); // 指定された範囲でランダムな角度を生成
    _neckJoint.write(angle);          // 首をランダムな角度に設定
}

void StackTank::stop()
{
    ledcWrite(_leftWheelChannel, 0);  // サーボを停止
    ledcWrite(_rightWheelChannel, 0); // サーボを停止
    _state = Stopped;
    _moveEndMillis = 0;
}

void StackTank::moveForward()
{
    _leftWheel.write(180); // 左車輪を前進方向に回転
    _rightWheel.write(0);  // 右車輪を前進方向に回転
}

void StackTank::moveBackward()
{
    _leftWheel.writeMicroseconds(0);    // 左車輪を後退方向に回転
    _rightWheel.writeMicroseconds(180); // 右車輪を後退方向に回転
}

void StackTank::turnLeft(int angle)
{
    // 非ブロッキング: 動かして終了時刻だけ設定する
    _leftWheel.write(0);  // 左車輪を後退方向に回転
    _rightWheel.write(0); // 右車輪を前進方向に回転
    delay(8 * angle);
    stop();
}

void StackTank::turnRight(int angle)
{
    _leftWheel.write(180);  // 左車輪を前進方向に回転
    _rightWheel.write(180); // 右車輪を後退方向に回転
    delay(8 * angle);
    stop();
}
