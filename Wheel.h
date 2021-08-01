#pragma once
#include "LeakedObjectDetector.h"

struct Wheel
{
    float tradDepth, maxLoad, maxPressure, size, currentPressure;
    Wheel();
    ~Wheel();

    void roateWheel(float amount, bool forward = true);
    void releaseAir(float pressureAmount);
    void releaseAir2(float pressureAmount);
    void turnWheel(float angle);
    void turnWheel2(float angle);
    void maximisePressure(float pressureIncrement = 2);
    void maximisePressure2(float pressureIncrement = 2);
    
    JUCE_LEAK_DETECTOR(Wheel)
};
