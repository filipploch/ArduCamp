
#ifndef LCD20X4
#define LCD20X4

#include <LiquidCrystal_I2C.h>
#include "view.hpp"


class LCD20x4 : public LiquidCrystal_I2C
{
private:
    String actualValue;
public:
    LCD20x4(uint8_t lcd_Addr);
    void printHello();
    void printTemplate(View *_view);
    void printValue(View *_view);

};

#endif
