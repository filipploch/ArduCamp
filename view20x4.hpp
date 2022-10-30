#include "view.hpp"
// #include <Arduino.h>
// #include <AceSorting.h>
// using ace_sorting::shellSortKnuth;
#include "sensor.hpp"

#define RREF 4700
#define VIN 5
#define RMAX 7000

class View20x4 : public View
{
private:
    uint8_t nrOfValues;
    String names[4];
    
    String values[4];
    String units[4];
    String descriptions[4];
    Sensor* sensors[4];

    
public:
    View20x4(Sensor * _sensors[], uint8_t _size);
    String *getNames();
    void setNames(Sensor **);
    void setSensors(Sensor **);
    void setValues();
    void setUnits(Sensor **);
    String *getValues();
    // String *getWarning();
    String *getUnits();
    String *getDescriptions();
    uint8_t getNrOfValues();
};
