#include "StackTank.h"

StackTank::StackTank()
{
}

void StackTank::init()
{
    _leftWheelChannel = _leftWheel.attach(LEFT_WHEEL_PIN, 700, 2300);
    _rightWheelChannel = _rightWheel.attach(RIGHT_WHEEL_PIN, 700, 2300);
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

void StackTank::turnLeft(int angle)
{
    _leftWheel.writeMicroseconds(1000);  // 左車輪を後退方向に回転
    _rightWheel.writeMicroseconds(1000); // 右車輪を前進方向に回転
    delay(angle * 7);                    // 指定された角度に応じて回転時間を調整]
    this->stop();
}

void StackTank::turnRight(int angle)
{
    _leftWheel.writeMicroseconds(2000);  // 左車輪を前進方向に回転
    _rightWheel.writeMicroseconds(2000); // 右車輪を後退方向に回転
    delay(angle * 7);                    // 指定された角度に応じて回転時間を調整
    this->stop();
}
