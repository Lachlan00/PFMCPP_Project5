#include "LeakedObjectDetector.h"
#include "Printer.h"
#include "Wheel.h"
#include "Headlight.h"

struct PrinterRobot
{
    Printer printer;
    Wheel leftWheel, rightWheel;
    Headlight lightBeam;
    PrinterRobot();
    ~PrinterRobot();

    void selfDistruct(int countdown = 10);
    void lightBeamBlast(int power);
    void lightBeamBlast2(int power);

    JUCE_LEAK_DETECTOR(PrinterRobot)
};
