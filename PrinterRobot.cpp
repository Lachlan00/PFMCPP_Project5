#include <iostream>
#include "PrinterRobot.h"

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

