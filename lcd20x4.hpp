
#ifndef LCD20X4
#define LCD20X4

// #include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "sensor.hpp"

// #define ROWS 4
// #define COLS 20

class LCD20x4 : public LiquidCrystal_I2C
{
private:
    // uint8_t rows = 4;
    // uint8_t cols = 20;
    String actualValue;
public:
    LCD20x4(uint8_t lcd_Addr);
    void printHello();
    void printTemplate(Sensor *_sensor);
    void printValue(Sensor *_sensor);
    // void printWarning(Sensor *_sensor);

};

#endif
