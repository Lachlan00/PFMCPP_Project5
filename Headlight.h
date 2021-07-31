#include "LeakedObjectDetector.h"

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

