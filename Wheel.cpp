#include <iostream>
#include "Wheel.h"

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

