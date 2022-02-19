
#ifndef LCD20X4
#define LCD20X4

#include <LiquidCrystal_I2C.h>
#include "sensor.h"

class LCD20x4 : public LiquidCrystal_I2C {
    private:

    public:
        // declare the full-fat constructor with default arguments
        LCD20x4(uint8_t lcd_Addr);
        void printHello();
        void printTemplate(Sensor* _sensor);
        void printValue(Sensor* _sensor);
};

#endif