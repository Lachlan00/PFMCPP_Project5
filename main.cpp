/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


#include <iostream>
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
    };

    void printDocument();
    void loadJobs(int queueNumber);
    void scanDocument(int resolution = 300);
    void printCopies(int noCopies);

    PrintJob printJob;
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
    void turnWheel(float angle);
    void maximisePressure(float pressureIncrement = 2);
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

void Wheel::turnWheel(float angle)
{
    std::cout << "Wheel turnign by " << angle << " radians" << std::endl;
    std::cout << "The wheel has " << tradDepth << " mm left of tread." << std::endl;
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
};

PrinterRobot::PrinterRobot()
{
    std::cout << "Robot has been constructed!" << std::endl;
    std::cout << "I am here to rule!" << std::endl;
    lightBeamBlast(9000);
    lightBeamBlast(9000);
    std::cout << "And to print!" << std::endl;
    printer.printDocument();
}

PrinterRobot::~PrinterRobot()
{
    selfDistruct(10);
}

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
    void deflateWheels();

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

    Printer printer;
    printer.printDocument();
    printer.scanDocument(72);
    printer.printCopies(3);
    printer.paperLevel = 2;
    printer.printCopies(7);

    std::cout << std::endl;

    Wheel frontRightWheel;
    Wheel backLeftWheel;
    frontRightWheel.roateWheel(360.f);
    std::cout << "Wheel pressure: " << frontRightWheel.currentPressure << std::endl;
    frontRightWheel.releaseAir(5.f);
    std::cout << "Wheel pressure: " << frontRightWheel.currentPressure << std::endl;
    std::cout << "Wheel pressure: " << backLeftWheel.currentPressure << std::endl;
    backLeftWheel.releaseAir(7.2f);
    std::cout << "Wheel pressure: " << backLeftWheel.currentPressure << std::endl;
    backLeftWheel.turnWheel(20.f);
    backLeftWheel.maximisePressure();
    frontRightWheel.maximisePressure();

    std::cout << std::endl;

    PrinterRobot printerRobot;
    printerRobot.lightBeamBlast(4000);
    printerRobot.selfDistruct(5);

    std::cout << std::endl;

    Car car;
    car.deflateWheels();
    car.inflateWheels();

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
    std::cout << std::endl;
}
