
// #include "a02yyuwSensor.hpp"


// A02YYUWSensor::A02YYUWSensor(String _name, uint8_t _trigPin, uint8_t _echoPin, uint8_t _height)
//     : Sensor::Sensor()
// {
//   name = _name;
//   trigPin = _trigPin;
//   echoPin = _echoPin;
//   fuelHeight = _height;
//   mySerial = SoftwareSerial(trigPin, echoPin);
// }

// String A02YYUWSensor::getName()
// {
//   return name;
// }

// float *A02YYUWSensor::getValue()
// {
//   this->value[0] = this->calculateValue();
//   return this->value;
// }

// int A02YYUWSensor::calculateValue()
// {
//   mySerial.begin(9600);
//     if (mySerial.available() > 0) {

//     delay(4);

//     if (mySerial.read() == 0xff) {
//       data_buffer[0] = 0xff;
//       for (int i = 1; i < 4; i++) {
//         data_buffer[i] = mySerial.read();
//       }

//       CS = data_buffer[0] + data_buffer[1] + data_buffer[2];
//       if (data_buffer[3] == CS) {
//         distance = (data_buffer[1] << 8) + data_buffer[2];
//         return distance;

//       }

//     }

//   }


// }

// String *A02YYUWSensor::getUnit()
// {
//   return this->unit;
// }

// String *A02YYUWSensor::getDescription()
// {
//   return this->description;
// }

// uint8_t A02YYUWSensor::getNrOfValues()
// {
//   return this->nrOfValues;
// }
