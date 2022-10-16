#include "view.hpp"
// #include <Arduino.h>
// #include <AceSorting.h>
// using ace_sorting::shellSortKnuth;


#define RREF 4700
#define VIN 5
#define RMAX 7000

class View20x4 : public View
{
private:
    String name;
    uint8_t pin;
    uint8_t fuelHeight;
    float maxResist;
    uint8_t sensorLen;
    uint8_t reserve;
    static const uint8_t nrOfValues = 1;
    String value[1];
    String unit[1] = {"%"};
    String warning[1] = {" <20"};
    String description[1] = {"Pozostalo"};
    
public:
    View20x4(String _name);
    String getName();
    // String *getValue();
    // String *getWarning();
    // String *getUnit();
    // String *getDescription();
    // uint8_t getNrOfValues();
    // float readValue();
};
