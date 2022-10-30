// #include <Arduino.h>
#include "sensor.hpp"


class VoltageSensor : public Sensor
{
private:
    String name;
    uint8_t pin;
    uint8_t refVoltage;
    uint16_t res1;
    uint16_t res2;
    static const uint8_t nrOfValues = 1;
    String value;
    String unit = "V";
    String description = "Napiecie";

public:
    VoltageSensor(String _name, uint8_t _pin, uint8_t _refVoltage, uint16_t _res1, uint16_t _res2);
    String getName();
    String getValue();
    float readVoltage();
    String getUnit();
    String getDescription();
    uint8_t getNrOfValues();
};
