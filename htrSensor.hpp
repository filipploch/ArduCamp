#include "sensor.hpp"
// #include <Arduino.h>
// #include <AceSorting.h>
// using ace_sorting::shellSortKnuth;

#define RREF 4700
#define VIN 5
#define RMAX 7000

class HTRSensor : public Sensor
{
private:
    String name;
    uint8_t pin;
    uint8_t fuelHeight;
    float maxResist;
    uint8_t sensorLen;
    uint8_t reserve;
    static const uint8_t nrOfValues = 1;
    String value;
    String unit = "%";
    String warning = " <20";
    String description = "Pozostalo";
    
public:
    HTRSensor(String _name, uint8_t _pin, int _maxResist, uint8_t _sensorLen, uint8_t _fuelHeight);
    String getName();
    String getValue();
    String getWarning();
    // void printValue();
    String getUnit();
    String getDescription();
    uint8_t getNrOfValues();
    float readValue();
    // float getAverage(uint8_t _nrOfElements);
};
