/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */





#include <iostream>
#include "LeakedObjectDetector.h"
#include <math.h> //for rounding
/*
 copied UDT 1:
 */
struct Printer
{
    int paperLevel, maxRes;
    float inkLevel, electrictyConsumption;
    std::string brandName;
    Printer();
    ~Printer();

    struct PrintJob 
    {
        int numCopies, numPages, resolution;
        std::string documentFilename, paperType;
        PrintJob();
        ~PrintJob();

        void cancelJob(std::string jobID);
        std::string checkJobStatus(std::string jobID);
        void addToQueue(std::string printerID, std::string proity = "low");
        
        JUCE_LEAK_DETECTOR(PrintJob)
    };

    void printDocument();
    void printDocument2();
    void loadJobs(int queueNumber);
    void scanDocument(int resolution = 300);
    void scanDocument2(int resolution = 300);
    void printCopies(int noCopies);
    void printCopies2(int noCopies);

    PrintJob printJob;
    
    JUCE_LEAK_DETECTOR(Printer)
};

Printer::Printer() :
paperLevel(124),
maxRes(300),
inkLevel(75.f),
electrictyConsumption(140.f),
brandName("Canon")
{}

Printer::~Printer()
{
    std::cout << "Printer is gone!" << std::endl;
}

struct PrinterWrapper
{
    PrinterWrapper(Printer* pointerToPrinter) : printer(pointerToPrinter) { }
    ~PrinterWrapper() { delete printer; }
    Printer* printer = nullptr;
};

Printer::PrintJob::PrintJob() :
numCopies(2),
numPages(12),
resolution(300),
documentFilename("myDoc.doc"),
paperType("A4")
{}

Printer::PrintJob::~PrintJob()
{
    std::cout << "Print job over." << std::endl;
}

void Printer::printDocument()
{
    std::cout << "Printing " << printJob.numCopies << " Copies of document " << printJob.documentFilename << std::endl;
    std::cout << "Current ink level: " << inkLevel << std::endl;
    std::cout << "Current paper level: "  << paperLevel << std::endl;
}

void Printer::printDocument2()
{
    std::cout << "Printing " << this->printJob.numCopies << " Copies of document " << this->printJob.documentFilename << std::endl;
    std::cout << "Current ink level: " << this->inkLevel << std::endl;
    std::cout << "Current paper level: "  << this->paperLevel << std::endl;
}

void Printer::loadJobs(int queueNumber)
{
    if (queueNumber > 1)
    {
        queueNumber -= 1;
    }
}

void Printer::scanDocument(int resolution)
{
    std::cout << "Scanning document at " << resolution << " dpi." << std::endl;
    std::cout << "Max resolution is " << maxRes << " dpi." << std::endl;
}

void Printer::scanDocument2(int resolution)
{
    std::cout << "Scanning document at " << resolution << " dpi." << std::endl;
    std::cout << "Max resolution is " << this->maxRes << " dpi." << std::endl;
}

void Printer::printCopies(int noCopies)
{
    printJob.numCopies = noCopies;
    printDocument();
    
    for (int i = 0; i < noCopies; ++i)
    {
        if (paperLevel == 0)
        {
            std::cout << "Error: no paper!" << std::endl;
            break;
        }
        
        std::cout << "Printing copy " << i + 1 << ".." << std::endl;
        paperLevel -= 1;
    }
}

void Printer::printCopies2(int noCopies)
{
    this->printJob.numCopies = noCopies;
    this->printDocument();
    
    for (int i = 0; i < noCopies; ++i)
    {
        if (this->paperLevel == 0)
        {
            std::cout << "Error: no paper!" << std::endl;
            break;
        }
        
        std::cout << "Printing copy " << i + 1 << ".." << std::endl;
        this->paperLevel -= 1;
    }
}

/*
 copied UDT 2:
 */
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

Wheel::Wheel() :
tradDepth(12.f),
maxLoad(3450.f),
maxPressure(35.f),
size(1.2f),
currentPressure(31.2f)
{}

Wheel::~Wheel()
{
    std::cout << "Wheel has reached the end of it's life.." << std::endl;
}

struct WheelWrapper
{
    WheelWrapper(Wheel* pointerToWheel) : wheel(pointerToWheel){}
    ~WheelWrapper(){ delete wheel; }
    Wheel* wheel = nullptr;
};

void Wheel::roateWheel(float amount, bool forward)
{
    std::string direction = "backward ";

    if (forward)
    {
        direction = "forward ";
    }

    std::cout << "Moving " << direction << "by " << amount << std::endl;
}

void Wheel::releaseAir(float pressureAmount)
{
    currentPressure -= pressureAmount;
    std::cout << pressureAmount << " PSI of air released!" << std::endl;
    std::cout << "Max pressure: " << maxPressure << " psi" << std::endl;
}

void Wheel::releaseAir2(float pressureAmount)
{
    this->currentPressure -= pressureAmount;
    std::cout << pressureAmount << " PSI of air released!" << std::endl;
    std::cout << "Max pressure: " << this->maxPressure << " psi" << std::endl;
}

void Wheel::turnWheel(float angle)
{
    std::cout << "Wheel turnign by " << angle << " radians" << std::endl;
    std::cout << "The wheel has " << tradDepth << " mm left of tread." << std::endl;
}

void Wheel::turnWheel2(float angle)
{
    std::cout << "Wheel turnign by " << angle << " radians" << std::endl;
    std::cout << "The wheel has " << this->tradDepth << " mm left of tread." << std::endl;
}

void Wheel::maximisePressure(float pressureIncrement)
{
    while (currentPressure < maxPressure)
    {
        std::cout << "Adding " << pressureIncrement << " psi.." << std::endl;
        currentPressure += pressureIncrement;
        std::cout << "Current pressure is " << currentPressure << std::endl;
    }
    
    if (currentPressure > maxPressure)
    {
        std::cout << "WARNING! Too much pressure. Releasing air.." << std::endl;
        releaseAir(currentPressure - maxPressure);
    }
}

void Wheel::maximisePressure2(float pressureIncrement)
{
    while (this->currentPressure < this->maxPressure)
    {
        std::cout << "Adding " << pressureIncrement << " psi.." << std::endl;
        this->currentPressure += pressureIncrement;
        std::cout << "Current pressure is " << this->currentPressure << std::endl;
    }
    
    if (this->currentPressure > this->maxPressure)
    {
        std::cout << "WARNING! Too much pressure. Releasing air.." << std::endl;
        this->releaseAir(this->currentPressure - this->maxPressure);
    }
}
/*
 copied UDT 3:
 */
struct Headlight
{
    int maxBeamPower;
    float wattage, beamAngle, candela;
    std::string houseingShape, bulbType;
    Headlight();
    ~Headlight();

    float illuminate(float illuminationAmount, bool highBeams = false);
    void changeIntensity(float intenstityAmount);
    void adjustBeamAngle(float newAngle);
    void lightBeamWeapon(float beamPower);
    void lightBeamWeapon2(float beamPower);

    JUCE_LEAK_DETECTOR(Headlight)
};

Headlight::Headlight() :
maxBeamPower(9000),
wattage(400.f),
beamAngle(20.f),
candela(1200.f),
houseingShape("round"),
bulbType("LED")
{}

Headlight::~Headlight()
{
    std::cout << "Headlight is be deconstructed.." << std::endl;
}

struct HeadlightWrapper
{
    HeadlightWrapper(Headlight* pointerToHeadlight) : headlight(pointerToHeadlight) { }
    ~HeadlightWrapper(){ delete headlight; }
    Headlight* headlight = nullptr;
};

float Headlight::illuminate(float illuminationAmount, bool highBeams)
{
    float illumination = illuminationAmount * 2;

    if (highBeams)
    {
        illumination += 20;
    }

    return illumination;
}

void Headlight::changeIntensity(float intenstityAmount)
{
    wattage += intenstityAmount;
}

void Headlight::adjustBeamAngle(float newAngle)
{
    beamAngle += newAngle;
}

void Headlight::lightBeamWeapon(float beamPower)
{   
    float progBarMaxLength = 50;
    float prog = 0;
    
    if (beamPower > maxBeamPower)
    {
        beamPower = maxBeamPower;
    }
    else if (beamPower <= 0)
    {
        beamPower = 1;
    }
    
    std::cout << "Charging light beam to " << beamPower <<"! Full power is " << maxBeamPower << " watts!" << std::endl;

    for (float power = 1; power <= beamPower; power++)
    {
        prog = (power/beamPower) * progBarMaxLength;
        std::cout << "Charging [" << round((power/beamPower)*100) << "%]\r" << std::flush;
    }
    
    std::cout << std::endl << std::endl << "FIRE!!!!" << std::endl << std::endl;
}

void Headlight::lightBeamWeapon2(float beamPower)
{   
    float progBarMaxLength = 50;
    float prog = 0;
    
    if (beamPower > this->maxBeamPower)
    {
        beamPower = this->maxBeamPower;
    }
    else if (beamPower <= 0)
    {
        beamPower = 1;
    }
    
    std::cout << "Charging light beam to " << beamPower <<"! Full power is " << this->maxBeamPower << " watts!" << std::endl;

    for (float power = 1; power <= beamPower; power++)
    {
        prog = (power/beamPower) * progBarMaxLength;
        std::cout << "Charging [" << round((power/beamPower)*100) << "%]\r" << std::flush;
    }
    
    std::cout << std::endl << std::endl << "FIRE!!!!" << std::endl << std::endl;
}

/*
 new UDT 4:
 with 2 member functions
 */
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

PrinterRobot::PrinterRobot()
{
    std::cout << "Robot has been constructed!" << std::endl;
    std::cout << "I am here to rule!" << std::endl;
    lightBeamBlast(9000);
    lightBeamBlast(9000);
    lightBeamBlast2(9000);
    lightBeamBlast2(9000);
    std::cout << "And to print!" << std::endl;
    printer.printDocument();
}

PrinterRobot::~PrinterRobot()
{
    selfDistruct(10);
}

struct PrinterRobotWrapper
{
    PrinterRobotWrapper(PrinterRobot* pointerToRobot) : printerRobot(pointerToRobot) { }
    ~PrinterRobotWrapper(){ delete printerRobot; }
    PrinterRobot* printerRobot = nullptr;
};

void PrinterRobot::selfDistruct(int countdown)
{
    std::cout << std::endl << "Warning! Self distruct sequence initiated!" << std::endl;
    for (int i = countdown; i > 0; --i)
    {
        std::cout << i << std::endl;
    }
    std::cout << "!!!((((BOOM))))!!!" << std::endl;
}

void PrinterRobot::lightBeamBlast(int power)
{
    lightBeam.lightBeamWeapon(power);
}

void PrinterRobot::lightBeamBlast2(int power)
{
    this->lightBeam.lightBeamWeapon2(power);
}

/*
 new UDT 5:
 with 2 member functions
 */
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

Car::Car()
{
    std::cout << "Car has been constructed!" << std::endl;
    std::cout << "Maximising all wheel air pressure" << std::endl;
    inflateWheels();
    std::cout << "Turning on left light:" << std::endl;
    leftLight.illuminate(100);
    std::cout << "Turning on right light:" << std::endl;
    rightLight.illuminate(100);
}

Car::~Car()
{
    std::cout << std::endl << "Car being deconstructed.." << std::endl;
    deflateWheels();
}

struct CarWrapper
{
    CarWrapper(Car* pointerToCar) : car(pointerToCar){ }
    ~CarWrapper(){ delete car; }
    Car* car = nullptr;
};

void Car::inflateWheels()
{
    std::cout << "Left front:" << std::endl;
    wheelLeftFront.maximisePressure(5);
    std::cout << "Right front:" << std::endl;
    wheelRightFront.maximisePressure(5);
    std::cout << "Left back:" << std::endl;
    wheelLeftBack.maximisePressure(5);
    std::cout << "Right back:" << std::endl;
    wheelRightBack.maximisePressure(5);
}

void Car::inflateWheels2()
{
    std::cout << "Left front:" << std::endl;
    this->wheelLeftFront.maximisePressure(5);
    std::cout << "Right front:" << std::endl;
    this->wheelRightFront.maximisePressure(5);
    std::cout << "Left back:" << std::endl;
    this->wheelLeftBack.maximisePressure(5);
    std::cout << "Right back:" << std::endl;
    this->wheelRightBack.maximisePressure(5);
}

void Car::deflateWheels()
{
    std::cout << "Releasing air form wheels" << std::endl;
    std::cout << "Left front:" << std::endl;
    wheelLeftFront.releaseAir(wheelLeftFront.currentPressure);
    std::cout << "Right front:" << std::endl;
    wheelRightFront.releaseAir(wheelRightFront.currentPressure);
    std::cout << "Left back:" << std::endl;
    wheelLeftBack.releaseAir(wheelLeftBack.currentPressure);
    std::cout << "Right back:" << std::endl;
    wheelRightBack.releaseAir(wheelRightBack.currentPressure);
}

void Car::deflateWheels2()
{
    std::cout << "Releasing air form wheels" << std::endl;
    std::cout << "Left front:" << std::endl;
    this->wheelLeftFront.releaseAir(this->wheelLeftFront.currentPressure);
    std::cout << "Right front:" << std::endl;
    this->wheelRightFront.releaseAir(this->wheelRightFront.currentPressure);
    std::cout << "Left back:" << std::endl;
    this->wheelLeftBack.releaseAir(this->wheelLeftBack.currentPressure);
    std::cout << "Right back:" << std::endl;
    this->wheelRightBack.releaseAir(this->wheelRightBack.currentPressure);
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    //Example::main();
    std::cout << std::endl;

    PrinterWrapper printer( new Printer() );
    printer.printer->printDocument();
    printer.printer->printDocument2();
    printer.printer->scanDocument(72);
    printer.printer->scanDocument2(72);
    printer.printer->printCopies(3);
    printer.printer->printCopies2(3);
    printer.printer->paperLevel = 2;
    printer.printer->printCopies(7);
    printer.printer->paperLevel = 2;
    printer.printer->printCopies2(7);

    std::cout << std::endl;

    WheelWrapper frontRightWheel( new Wheel() );
    WheelWrapper backLeftWheel( new Wheel() );
    frontRightWheel.wheel->roateWheel(360.f);
    std::cout << "Wheel pressure: " << frontRightWheel.wheel->currentPressure << std::endl;
    frontRightWheel.wheel->releaseAir(5.f);
    frontRightWheel.wheel->releaseAir2(5.f);
    std::cout << "Wheel pressure: " << frontRightWheel.wheel->currentPressure << std::endl;
    std::cout << "Wheel pressure: " << backLeftWheel.wheel->currentPressure << std::endl;
    backLeftWheel.wheel->releaseAir(7.2f);
    backLeftWheel.wheel->releaseAir2(7.2f);
    std::cout << "Wheel pressure: " << backLeftWheel.wheel->currentPressure << std::endl;
    backLeftWheel.wheel->turnWheel(20.f);
    backLeftWheel.wheel->turnWheel2(20.f);
    backLeftWheel.wheel->maximisePressure();
    backLeftWheel.wheel->maximisePressure2();
    frontRightWheel.wheel->maximisePressure();
    frontRightWheel.wheel->maximisePressure2();

    std::cout << std::endl;

    PrinterRobotWrapper printerRobot( new PrinterRobot() );
    printerRobot.printerRobot->lightBeamBlast(4000);
    printerRobot.printerRobot->lightBeamBlast2(4000);
    printerRobot.printerRobot->selfDistruct(5);

    std::cout << std::endl;

    CarWrapper car(new Car());
    car.car->deflateWheels();
    car.car->deflateWheels2();
    car.car->inflateWheels();
    car.car->inflateWheels2();

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
    std::cout << std::endl;
}
