#include "lcd20x4.hpp"

LCD20x4::LCD20x4(uint8_t lcd_Addr)
    : LiquidCrystal_I2C(lcd_Addr, 20, 4)
{
}

void LCD20x4::printHello()
{
  this->setCursor(0, 1);
  this->print("    Hello Camper    ");
  delay(2000);
  this->setCursor(0, 3);
  this->print("feat. Devs-Mentoring");
  delay(3000);
}

void LCD20x4::printTemplate(Sensor* _sensor){
 this->clear();
 this->setCursor(0, 0);
 this->print(_sensor->getName());
  for (uint8_t i = 0; i < _sensor->getNrOfValues(); i++) {
    this->setCursor(0, i + 2);
    this->print(_sensor->getDescription()[i] + ":");
    this->setCursor(18, i + 2);
    this->print(_sensor->getUnit()[i]);
  }
}

void LCD20x4::printValue(Sensor* _sensor){

  for (uint8_t i = 0; i < _sensor->getNrOfValues(); i++) {
    this->setCursor(13, i + 2);
    this->print(_sensor->getValue()[i], 1);
  }
}

