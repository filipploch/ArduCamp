

using namespace std;
#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
 public:
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
