
#include "voltageSensor.hpp"

VoltageSensor::VoltageSensor(String _name, uint8_t _pin, uint8_t _refVoltage, uint16_t _res1, uint16_t _res2)
{
  pin = _pin;
  name = _name;
  refVoltage = _refVoltage;
  res1 = _res1;
  res2 = _res2;
  //this->begin();
}

String VoltageSensor::getName()
{
  return name;
}

String VoltageSensor::getValue()
{
  this->value = String(this->readVoltage(), 1);

  return this->value;
}

float VoltageSensor::readVoltage(){
    // int value = analogRead(this->pin);
   
  //  // Determine voltage at ADC input
  //  float adc_voltage  = (value * this->refVoltage) / 1024.0; 
   
  float voltage = (((analogRead(this->pin)) * this->refVoltage) / 1024.0) / (float(this->res2)/(float(this->res1)+float(this->res2))) ;
  // Serial.print(this->pin);
  // Serial.print("# value: ");
  // Serial.print(value);
  // Serial.print(", adc_voltage: ");
  // Serial.print(adc_voltage);
  // Serial.print(", wsp: ");
  // Serial.print((float(7500)/float(37500)));
  // Serial.print(", voltage: ");
  // Serial.println(voltage);
  return voltage;
}

String VoltageSensor::getUnit()
{
  return this->unit;
}

String VoltageSensor::getDescription()
{
  return this->description;
}

uint8_t VoltageSensor::getNrOfValues()
{
  return this->nrOfValues;
}
