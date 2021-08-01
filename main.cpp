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
// #include "Printer.h"
// #include "Wheel.h"
// #include "Headlight.h"
// #include "PrinterRobot.h"
// #include "Car.h"
#include "Wrappers.h"

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
