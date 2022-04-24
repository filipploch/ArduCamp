// #include "sensor.hpp"
// #include <DistanceSensor_A02YYUW.h>
// #include <SoftwareSerial.h>
// // #include <Arduino.h>

// class A02YYUWSensor : public Sensor
// {
// private:
//     String name;
//     uint8_t trigPin;
//     uint8_t echoPin;
//     uint8_t fuelHeight;
//     static const uint8_t nrOfValues = 1;
//     float value[1];
//     String unit[1] = {"%"};
//     String description[1] = {"Woda"};
//     int data_buffer[4] = {0};
//     int distance;
//     int CS;
//     SoftwareSerial mySerial;
    
// public:
//     A02YYUWSensor(String _name, uint8_t _trigPin, uint8_t _echoPin, uint8_t _height)
//         :
//         mySerial(_trigPin, _echoPin){};
//     String getName();
//     float *getValue();
//     String *getUnit();
//     String *getDescription();
//     uint8_t getNrOfValues();
//     int calculateValue();
// };
