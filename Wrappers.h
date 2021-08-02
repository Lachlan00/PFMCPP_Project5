// Wrapper classes
#pragma once

// Forward declarations
struct Printer;
struct Wheel;
struct Headlight;
struct PrinterRobot;
struct Car;

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

