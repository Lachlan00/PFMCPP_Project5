#include "Wrappers.h"

PrinterWrapper::PrinterWrapper(Printer* pointerToPrinter) : printer(pointerToPrinter) { }

PrinterWrapper::~PrinterWrapper() { delete printer; }

WheelWrapper::WheelWrapper(Wheel* pointerToWheel) : wheel(pointerToWheel){}

WheelWrapper::~WheelWrapper(){ delete wheel; }

HeadlightWrapper::HeadlightWrapper(Headlight* pointerToHeadlight) : headlight(pointerToHeadlight) { }

HeadlightWrapper::~HeadlightWrapper(){ delete headlight; }

PrinterRobotWrapper::PrinterRobotWrapper(PrinterRobot* pointerToRobot) : printerRobot(pointerToRobot) { }

PrinterRobotWrapper::~PrinterRobotWrapper(){ delete printerRobot; }

CarWrapper::CarWrapper(Car* pointerToCar) : car(pointerToCar){ }

CarWrapper::~CarWrapper(){ delete car; }
