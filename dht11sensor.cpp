
#include "dht11sensor.hpp"

#define DHTTYPE DHT11

DHT11Sensor::DHT11Sensor(String _name, uint8_t _pin)
    : Sensor::Sensor(), DHT::DHT(_pin, DHTTYPE)
{
  pin = _pin;
  name = _name;
  this->begin();
}

String DHT11Sensor::getName()
{
  return name;
}

float *DHT11Sensor::getValue()
{
  this->value[0] = this->readTemperature();
  this->value[1] = this->readHumidity();
  return this->value;
}

String *DHT11Sensor::getUnit()
{
  return this->unit;
}

String *DHT11Sensor::getDescription()
{
  return this->description;
}

uint8_t DHT11Sensor::getNrOfValues()
{
  return this->nrOfValues;
}
