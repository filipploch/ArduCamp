
#include "sr04mSensor.hpp"

#define DHTTYPE DHT11

SR04MSensor::SR04MSensor(String _name, uint8_t _trigPin, uint8_t _echoPin, uint8_t _base, uint8_t _height)
    : Sensor::Sensor()
{
  name = _name;
  trigPin = _trigPin;
  echoPin = _echoPin;
  fuelBase = _base;
  fuelHeight = _height;
}

String SR04MSensor::getName()
{
  return name;
}

String *SR04MSensor::getValue()
{
  this->value[0] = "23";
  return this->value;
}

String *SR04MSensor::getUnit()
{
  return this->unit;
}

String *SR04MSensor::getDescription()
{
  return this->description;
}

uint8_t SR04MSensor::getNrOfValues()
{
  return this->nrOfValues;
}
