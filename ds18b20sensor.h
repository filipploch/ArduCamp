#include "sensor.h";
#include <OneWire.h>
#include <DallasTemperature.h>


using namespace std;

class DS18B20Sensor : public Sensor
, public OneWire
, public DallasTemperature
{
    public:
        String name;
        int pin;
        int idx;
        static const int nrOfValues = 1;
        float value[1];
        String unit[1] = {"*C"};
        String description[1] = {"Temperatura"};
//        OneWire oneWire(ONE_WIRE_BUS);
        OneWire oneWire;
        DallasTemperature ds18b20sensor;

    public:
      DS18B20Sensor(String _name, int _pin, int _idx);
      String getName();
      float* getValue();
      String* getUnit();
      String* getDescription();
      int getNrOfValues();
};