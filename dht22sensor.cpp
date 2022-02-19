using namespace std;

#include <Arduino.h>
#include "dht22sensor.h"
#define DHTTYPE DHT22

using namespace std;



DHT22Sensor::DHT22Sensor(String _name, int _pin)
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

int DHT22Sensor::getNrOfValues(){
  return this->nrOfValues;
}
