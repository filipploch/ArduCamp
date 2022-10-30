#ifndef VIEW_HPP
#define VIEW_HPP
#include <Arduino.h>

class View
{
protected:
  String name;
  String unit;
  String value;

public:
  View();
  virtual void setNames();
  virtual void setValues();
  virtual String *getNames();
  virtual String *getValues();
  virtual String *getUnits();
  virtual String *getWarnings();
  virtual void printValue();
  virtual String *getDescriptions();
  virtual uint8_t getNrOfSensors();
};

#endif
