#include "sensor.h";
#include "DHT.h";

using namespace std;

class DHT22Sensor : public Sensor
, public DHT
{
    public:
        String name;
        int pin;
        static const int nrOfValues = 2;
        float value[2];
        String unit[2] = {"*C", "%"};
        String description[2] = {"Temperatura", "Wilgotnosc"};

    public:
      DHT22Sensor(String _name, int _pin);
      String getName();
      float* getValue();
      String* getUnit();
      String* getDescription();
      int getNrOfValues();
};
