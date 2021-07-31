#include <iostream>
#include "Car.h"

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

