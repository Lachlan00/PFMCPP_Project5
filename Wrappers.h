// Wrapper classes
#include "Printer.h"
#include "Wheel.h"
#include "Headlight.h"
#include "PrinterRobot.h"
#include "Car.h"

struct PrinterWrapper
{
    PrinterWrapper();
    ~Printer();
    Printer* printer = nullptr;
};

PrinterWrapper::PrinterWrapper(Printer* pointerToPrinter) : printer(pointerToPrinter) { }

PrinterWrapper::~PrinterWrapper() { delete printer; }

struct WheelWrapper
{
    WheelWrapper();
    ~WheelWrapper();
    Wheel* wheel = nullptr;
};

WheelWrapper::WheelWrapper(Wheel* pointerToWheel) : wheel(pointerToWheel){}

WheelWrapper::~WheelWrapper(){ delete wheel; }

struct HeadlightWrapper
{
    HeadlightWrapper();
    ~HeadlightWrapper();
    Headlight* headlight = nullptr;
};

HeadlightWrapper::HeadlightWrapper(Headlight* pointerToHeadlight) : headlight(pointerToHeadlight) { }

HeadlightWrapper::~HeadlightWrapper(){ delete headlight; }

struct PrinterRobotWrapper
{
    PrinterRobotWrapper();
    ~PrinterRobotWrapper();
    PrinterRobot* printerRobot = nullptr;
};

PrinterRobotWrapper::PrinterRobotWrapper(PrinterRobot* pointerToRobot) : printerRobot(pointerToRobot) { }

PrinterRobotWrapper::~PrinterRobotWrapper(){ delete printerRobot; }

struct CarWrapper
{
    CarWrapper();
    ~CarWrapper();
    Car* car = nullptr;
};

CarWrapper::CarWrapper(Car* pointerToCar) : car(pointerToCar){ }

CarWrapper::~CarWrapper(){ delete car; }
