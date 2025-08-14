#pragma once

namespace STServo
{
    class ServoBase
    {
    protected:
        int _pin;

    public:
        ServoBase() : _pin(-1) {}
        void attach(int pin){ _pin = pin; };
        void detach(){ _pin = -1; };
    };

    class ServoWheel : public ServoBase
    {
    public:
        ServoWheel();
        void driveCW();
        void driveCCW();

    };

    class ServoJoint : public ServoBase
    {
    public:
        ServoJoint();

    };
}