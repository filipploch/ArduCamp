
#include "dht11sensor.hpp"

#define DHTTYPE DHT11

// using namespace std;



DHT11Sensor::DHT11Sensor(String _name, int _pin)
  : Sensor::Sensor()
  , DHT::DHT(_pin, DHTTYPE)
{
  Sensor sensor = Sensor();
  pin = _pin;
  name = _name;
  this->begin();
//  DHT dht11sensor = DHT(pin, DHTTYPE);
//  dht11sensor.begin();

}

String DHT11Sensor::getName()
{
  return name;
}

float* DHT11Sensor::getValue()
{
  this->value[0] = this->readTemperature();
  this->value[1] = this->readHumidity();
  return this->value;
}

String* DHT11Sensor::getUnit()
{
  return this->unit;
}

String* DHT11Sensor::getDescription(){
  return this->description;
}

int DHT11Sensor::getNrOfValues(){
  return this->nrOfValues;
}
