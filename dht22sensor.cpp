
#include "dht22sensor.hpp"

DHT22Sensor::DHT22Sensor(String _name, uint8_t _pin)
    : Sensor::Sensor(), DHT::DHT(_pin, DHTTYPE)
{
  pin = _pin;
  name = _name;
  this->begin();
}

String DHT22Sensor::getName()
{
  return name;
}

String *DHT22Sensor::getValue()
{

  this->value[0] = String(this->readTemperature(), 1);
  this->value[1] = String(this->readHumidity(), 1);
  return this->value;
}

String *DHT22Sensor::getUnit()
{
  return this->unit;
}

String *DHT22Sensor::getDescription()
{
  return this->description;
}

uint8_t DHT22Sensor::getNrOfValues()
{
  return this->nrOfValues;
}
