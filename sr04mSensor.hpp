#include "sensor.hpp"
#include <Arduino.h>

class SR04MSensor : public Sensor
{
private:
    String name;
    uint8_t trigPin;
    uint8_t echoPin;
    uint8_t fuelBase;
    uint8_t fuelHeight;
    static const uint8_t nrOfValues = 1;
    String value[1];
    String unit[1] = {"L"};
    String description[1] = {"Woda"};

public:
    SR04MSensor(String _name, uint8_t _trigPin, uint8_t _echoPin, uint8_t _base, uint8_t _height);
    String getName();
    String *getValue();
    String *getUnit();
    String *getDescription();
    uint8_t getNrOfValues();
};
