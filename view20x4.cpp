
#include "view20x4.hpp"


View20x4::View20x4(Sensor * _sensors[], uint8_t _size)
{
  this->setSensors(_sensors);
  this->nrOfValues = _size;
  this->setNames(_sensors);
  this->setUnits(_sensors);


}
void View20x4::setSensors(Sensor* _sensors[])
{
    for (int i = 0; i<this->getNrOfSensors(); i++){
      this->sensors[i] = _sensors[i];
    }
}


void View20x4::setNames(Sensor* _sensors[])
{
    for (int i = 0; i<this->getNrOfSensors(); i++){
      this->names[i] = _sensors[i]->getName();
    }
}

void View20x4::setUnits(Sensor* _sensors[])
{
    for (int i = 0; i<this->getNrOfSensors(); i++){
      this->units[i] = _sensors[i]->getUnit();
    }
}

// void View20x4::setValues(Sensor* _sensors[])
void View20x4::setValues()
{
    for (int i = 0; i<this->getNrOfSensors(); i++){
      this->values[i] = sensors[i]->getValue();
    }
}

String* View20x4::getNames()
{
  return this->names;
}

String *View20x4::getValues()
{
  // this->value[0] = String(this->readValue(), 1);
  // if (this->value[0].toInt() < 20){
  //   this->value[0] = " <20";
  //   // return this->value;    
  // }
  return this->values;
}


// // float View20x4::getAverage(uint8_t _nrOfElements)
// // {
// //   float elements[_nrOfElements] = {};
// //   float elementsSum = 0;
// //   int divider = 0;

// //   for (uint8_t i = 0; i < _nrOfElements; i++)
// //   {
// //     elements[i] = this->readValue();
// //     delay(3);
// //   }
// //   shellSortKnuth(elements, _nrOfElements);
// //   for (uint8_t i = 0; i < _nrOfElements; i++)
// //   {
// //     if ( elements[i] >= elements[_nrOfElements/2 - 1] * 0.9 && 
// //         elements[i] <= elements[_nrOfElements/2 - 1] * 1.1)
// //     {
// //       elementsSum += elements[i];
// //       divider += 1; 
// //     }
// //   }
// //   if (divider > 0){
// //     return elementsSum / divider;
// //   }
// // }

// // float sort_desc(const void *cmp1, const void *cmp2)
// // {
// //   int a = *((int *)cmp1);
// //   int b = *((int *)cmp2);
// //   return a > b ? -1 : (a < b ? 1 : 0);
// // }


String *View20x4::getUnits()
{
  return this->units;
}

// String *View20x4::getWarning()
// {
//   return this->warning;
// }

String *View20x4::getDescriptions()
{
  return this->descriptions;
}

uint8_t View20x4::getNrOfSensors()
{
  return this->nrOfValues;
}
