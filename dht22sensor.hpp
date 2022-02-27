

#define DHTTYPE DHT22
#include <Arduino.h>
#include "sensor.hpp"
#include "DHT.h"
// using namespace std;

class DHT22Sensor : public Sensor
, public DHT
{
    private:
        String name;
        uint8_t pin;
        static const uint8_t nrOfValues = 2;
        float value[2];
        String unit[2] = {"*C", "%"};
        String description[2] = {"Temperatura", "Wilgotnosc"};

    public:
      DHT22Sensor(String _name, uint8_t _pin);
      String getName();
      float* getValue();
      String* getUnit();
      String* getDescription();
      uint8_t getNrOfValues();
};
