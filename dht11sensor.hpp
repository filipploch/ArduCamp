#include "sensor.hpp"
#include "DHT.h"
#include <Arduino.h>

// using namespace std;

class DHT11Sensor : public Sensor
, public DHT
{
    private:
        String name;
        int pin;
        static const int nrOfValues = 2;
        float value[2];
        String unit[2] = {"*C", "%"};
        String description[2] = {"Temperatura", "Wilgotnosc"};

  	public:
	    DHT11Sensor(String _name, int _pin);
	    String getName();
	    float* getValue();
	    String* getUnit();
      String* getDescription();
      int getNrOfValues();
};
