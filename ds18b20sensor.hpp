#include "sensor.hpp"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

class DS18B20Sensor : public Sensor, public OneWire, public DallasTemperature
{
private:
    String name;
    uint8_t pin;
    uint8_t idx;
    static const uint8_t nrOfValues = 1;
    float value[1];
    String unit[1] = {"*C"};
    String description[1] = {"Temperatura"};
    OneWire oneWire;
    DallasTemperature ds18b20sensor;

public:
    DS18B20Sensor(String _name, uint8_t _pin, uint8_t _idx);
    String getName();
    float *getValue();
    String *getUnit();
    String *getDescription();
    uint8_t getNrOfValues();
    void begin();
};
