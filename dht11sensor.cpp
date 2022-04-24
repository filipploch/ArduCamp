
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

String *DHT11Sensor::getValue()
{
  this->value[0] = String(this->readTemperature(), 1);
  this->value[1] = String(this->readHumidity(), 1);
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
