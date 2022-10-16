
#include "htrSensor.hpp"


HTRSensor::HTRSensor(String _name, uint8_t _pin, int _maxResist = 190, uint8_t _sensorLen = 25, uint8_t _fuelHeight = 30)

{
  name = _name;
  pin = _pin;
  maxResist = _maxResist;
  sensorLen = _sensorLen;
  fuelHeight = _fuelHeight;
  reserve = fuelHeight - sensorLen;
}

String HTRSensor::getName()
{
  return name;
}

String *HTRSensor::getValue()
{
  this->value[0] = String(this->readValue(), 1);
  if (this->value[0].toInt() < 20){
    this->value[0] = " <20";
    // return this->value;    
  }
  return this->value;
}

// void HTRSensor::printValue(){
  
// }

float HTRSensor::readValue()
{
  int sensorValue=analogRead(pin);
  float Vout=sensorValue*(5.0/1023.0);
  float actualResistance = RREF * (1 / ((VIN / Vout) - 1));
  float rFactor = actualResistance/this->maxResist;
  float vFactor = (this->sensorLen/this->fuelHeight);
  float vPercent = ((rFactor * this->sensorLen + this->reserve)/this->fuelHeight)*100;

  if (vPercent > 99.0)
  {
    return 100;
  }
  return vPercent;
}

// float HTRSensor::getAverage(uint8_t _nrOfElements)
// {
//   float elements[_nrOfElements] = {};
//   float elementsSum = 0;
//   int divider = 0;

//   for (uint8_t i = 0; i < _nrOfElements; i++)
//   {
//     elements[i] = this->readValue();
//     delay(3);
//   }
//   shellSortKnuth(elements, _nrOfElements);
//   for (uint8_t i = 0; i < _nrOfElements; i++)
//   {
//     if ( elements[i] >= elements[_nrOfElements/2 - 1] * 0.9 && 
//         elements[i] <= elements[_nrOfElements/2 - 1] * 1.1)
//     {
//       elementsSum += elements[i];
//       divider += 1; 
//     }
//   }
//   if (divider > 0){
//     return elementsSum / divider;
//   }
// }

// float sort_desc(const void *cmp1, const void *cmp2)
// {
//   int a = *((int *)cmp1);
//   int b = *((int *)cmp2);
//   return a > b ? -1 : (a < b ? 1 : 0);
// }


String *HTRSensor::getUnit()
{
  return this->unit;
}

String *HTRSensor::getWarning()
{
  return this->warning;
}

String *HTRSensor::getDescription()
{
  return this->description;
}

uint8_t HTRSensor::getNrOfValues()
{
  return this->nrOfValues;
}
