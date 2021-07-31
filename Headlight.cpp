#include "Headlight.h"
#include <math.h> //for rounding

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

