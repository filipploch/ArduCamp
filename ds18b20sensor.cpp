
#include "ds18b20sensor.hpp"

// using namespace std;



DS18B20Sensor::DS18B20Sensor(String _name, uint8_t _pin, uint8_t _idx)
  : Sensor::Sensor()
  , oneWire(_pin)
  , DallasTemperature::DallasTemperature(&this->oneWire)
{
  pin = _pin;
  name = _name;
  idx = _idx;
  this->DallasTemperature::begin();

}

String DS18B20Sensor::getName()
{
  return name;
}

float* DS18B20Sensor::getValue()
{
  this->requestTemperatures();
  this->value[0] = this->getTempCByIndex(this->idx);
  return this->value;
}

String* DS18B20Sensor::getUnit(){
  return this->unit;
}

String* DS18B20Sensor::getDescription(){
  return this->description;
}

uint8_t DS18B20Sensor::getNrOfValues(){
  return this->nrOfValues;
}
