#pragma once

namespace STServo
{
    class ServoBase
    {
    protected:
        int _pin;

    public:
        ServoBase() : _pin(-1) {}
        void attach(int pin);
    };

    class ServoWheel : public ServoBase
    {
    public:
        ServoWheel();

    };

    class ServoJoint : public ServoBase
    {
    public:
        ServoJoint();

    };
}