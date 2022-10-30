#include "lcd20x4.hpp"

LCD20x4::LCD20x4(uint8_t lcd_Addr)
    : LiquidCrystal_I2C(lcd_Addr, 20, 4)
{
}

void LCD20x4::printHello()
{
  this->setCursor(0, 1);
  this->print("  Hello AG-Camper   ");
  delay(2000);
  this->setCursor(0, 3);
  this->print("feat. Devs-Mentoring");
  delay(3000);
}

void LCD20x4::printTemplate(View *_view)
{
  this->clear();
  for (uint8_t i = 0; i < _view->getNrOfValues(); i++)
  {
    this->setCursor(0, i);
    this->print(_view->getNames()[i] + ":");
    this->setCursor(20 - _view->getUnits()[i].length(), i);
    this->print(_view->getUnits()[i]);
  }
}

void LCD20x4::printValue(View *_view)
{
  _view->setValues();
  for (int i = 0; i < _view->getNrOfValues(); i++)
  {
    this->actualValue = _view->getValues()[i];
    this->setCursor(_view->getNames()[i].length() + 1, i);
    String clearer = "";
    for (uint8_t i; i<_view->getNames()[i].length() - 1; i++)
    {
      clearer += ' ';
    }
    this->print(clearer);
    this->setCursor(18 - this->actualValue.length(), i);
    this->print(this->actualValue);
  }
}


