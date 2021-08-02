#pragma once
#include "LeakedObjectDetector.h"
#include "Headlight.h"
#include "Wheel.h"

struct Car
{
    Wheel wheelLeftFront, wheelRightFront, wheelLeftBack, wheelRightBack;
    Headlight leftLight, rightLight;
    Car();
    ~Car();

    void inflateWheels();
    void inflateWheels2();
    void deflateWheels();
    void deflateWheels2();

    JUCE_LEAK_DETECTOR(Car)
};
