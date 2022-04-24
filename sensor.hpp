#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <Arduino.h>

class Sensor
{
protected:
  String name;
  String unit;
  String value;

public:
  Sensor();
  virtual String getName();
  virtual String *getValue();
  virtual String *getUnit();
  virtual String *getWarning();
  virtual void printValue();
  virtual String *getDescription();
  virtual uint8_t getNrOfValues();
};

#endif
