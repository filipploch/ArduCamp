
#ifndef LCD20X4
#define LCD20X4

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "sensor.hpp"

class LCD20x4 : public LiquidCrystal_I2C
{
private:
public:
    LCD20x4(uint8_t lcd_Addr);
    void printHello();
    void printTemplate(Sensor *_sensor);
    void printValue(Sensor *_sensor);
};

#endif