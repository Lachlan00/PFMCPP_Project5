// Wrapper classes

struct PrinterWrapper
{
    PrinterWrapper(Printer* pointerToPrinter) : printer(pointerToPrinter) { }
    ~PrinterWrapper() { delete printer; }
    Printer* printer = nullptr;
};

struct WheelWrapper
{
    WheelWrapper(Wheel* pointerToWheel) : wheel(pointerToWheel){}
    ~WheelWrapper(){ delete wheel; }
    Wheel* wheel = nullptr;
};

struct HeadlightWrapper
{
    HeadlightWrapper(Headlight* pointerToHeadlight) : headlight(pointerToHeadlight) { }
    ~HeadlightWrapper(){ delete headlight; }
    Headlight* headlight = nullptr;
};

struct PrinterRobotWrapper
{
    PrinterRobotWrapper(PrinterRobot* pointerToRobot) : printerRobot(pointerToRobot) { }
    ~PrinterRobotWrapper(){ delete printerRobot; }
    PrinterRobot* printerRobot = nullptr;
};

struct CarWrapper
{
    CarWrapper(Car* pointerToCar) : car(pointerToCar){ }
    ~CarWrapper(){ delete car; }
    Car* car = nullptr;
};
