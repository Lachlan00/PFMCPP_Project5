// Wrapper classes
#pragma once
#include "Printer.h"
#include "Wheel.h"
#include "Headlight.h"
#include "PrinterRobot.h"
#include "Car.h"

struct PrinterWrapper
{
    PrinterWrapper(Printer* pointerToPrinter);
    ~PrinterWrapper();
    Printer* printer = nullptr;
};

struct WheelWrapper
{
    WheelWrapper(Wheel* pointerToWheel);
    ~WheelWrapper();
    Wheel* wheel = nullptr;
};

struct HeadlightWrapper
{
    HeadlightWrapper(Headlight* pointerToHeadlight);
    ~HeadlightWrapper();
    Headlight* headlight = nullptr;
};

struct PrinterRobotWrapper
{
    PrinterRobotWrapper(PrinterRobot* pointerToRobot);
    ~PrinterRobotWrapper();
    PrinterRobot* printerRobot = nullptr;
};

struct CarWrapper
{
    CarWrapper(Car* pointerToCar);
    ~CarWrapper();
    Car* car = nullptr;
};

