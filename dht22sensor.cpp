
#include "dht22sensor.hpp"


DHT22Sensor::DHT22Sensor(String _name, uint8_t _pin)
  : Sensor::Sensor()
  , DHT::DHT(_pin, DHTTYPE)
{
//  Sensor sensor = Sensor();
  pin = _pin;
  name = _name;
  this->begin();

}

String DHT22Sensor::getName()
{
  return name;
}

float* DHT22Sensor::getValue()
{

  this->value[0] = this->readTemperature();
  this->value[1] = this->readHumidity();
  return this->value;}

String* DHT22Sensor::getUnit(){
  return this->unit;
}

String* DHT22Sensor::getDescription(){
  return this->description;
}

uint8_t DHT22Sensor::getNrOfValues(){
  return this->nrOfValues;
}
