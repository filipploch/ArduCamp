
#include "view20x4.hpp"


View20x4::View20x4(String _name)

{
  name = _name;

}

String View20x4::getName()
{
  return name;
}

// String *View20x4::getValue()
// {
//   this->value[0] = String(this->readValue(), 1);
//   if (this->value[0].toInt() < 20){
//     this->value[0] = " <20";
//     // return this->value;    
//   }
//   return this->value;
// }

// // void View20x4::printValue(){
  
// // }

// float View20x4::readValue()
// {
//   int sensorValue=analogRead(pin);
//   float Vout=sensorValue*(5.0/1023.0);
//   float actualResistance = RREF * (1 / ((VIN / Vout) - 1));
//   float rFactor = actualResistance/this->maxResist;
//   float vFactor = (this->sensorLen/this->fuelHeight);
//   float vPercent = ((rFactor * this->sensorLen + this->reserve)/this->fuelHeight)*100;

//   if (vPercent > 99.0)
//   {
//     return 100;
//   }
//   return vPercent;
// }

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


// String *View20x4::getUnit()
// {
//   return this->unit;
// }

// String *View20x4::getWarning()
// {
//   return this->warning;
// }

// String *View20x4::getDescription()
// {
//   return this->description;
// }

// uint8_t View20x4::getNrOfValues()
// {
//   return this->nrOfValues;
// }
