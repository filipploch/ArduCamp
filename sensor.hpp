#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <Arduino.h>

// using namespace std;

class Sensor
{
 protected:
    String name;
  	String unit;
    float value;

  public:
    Sensor();
    virtual String getName();
    virtual float* getValue();
    virtual String* getUnit();
    virtual String* getDescription();
    virtual int getNrOfValues();


};

#endif
