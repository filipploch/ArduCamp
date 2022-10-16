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
  virtual String getName();
  virtual String *getValue();
  virtual String *getUnit();
  virtual String *getWarning();
  virtual void printValue();
  virtual String *getDescription();
  virtual uint8_t getNrOfValues();
};

#endif
