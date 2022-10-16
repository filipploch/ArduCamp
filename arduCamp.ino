#include "lcd20x4.hpp"
#include "ds18b20sensor.hpp"
#include "htrSensor.hpp"
#include "voltageSensor.hpp"
#include "view20x4.hpp"

const uint8_t forwardButtonPin = 10;
const uint8_t backwardButtonPin = 12;

Sensor inTempSensor = DS18B20Sensor("W KAMPERZE", 7, 0);
Sensor outTempSensor = DS18B20Sensor("NA POLU", 6, 0);
Sensor coolTempSensor = DS18B20Sensor("LODOWKA", 11, 0);
Sensor refriTempSensor = DS18B20Sensor("ZAMRAZALNIK", 13, 0);
Sensor waterTankSensor = HTRSensor("ZBIORNIK WODY", A0, 190, 25, 30);
Sensor acu1VoltSensor = VoltageSensor("AKUMULATOR 1", A1, 5, 30000, 7500);
Sensor acu2VoltSensor = VoltageSensor("AKUMULATOR 2", A3, 5, 30000, 7500);

uint8_t forwardButtonState;
uint8_t backwardButtonState;
bool isToChange = true;
uint8_t viewNr;
unsigned long measureTime;
unsigned long bLightTime;

LCD20x4 lcd(0x27);

// String view1 = "VIEW1";
// String view2 = "VIEW2";
// String view3 = "VIEW3";
// String view4 = "VIEW4";

View *views[] = {
                    new View20x4("VIEW 1"),
                    new View20x4("VIEW 2"),
                     };

int8_t switchView(int8_t val)
{

  switch (val)
  {
    case 0:
      return 0;

    case 1:
      if (viewNr == sizeof(views) / sizeof(views[0]) - 1)
      {
        return 0;
      }
      else
      {
        return viewNr + val;
      }

    case -1:
      if (viewNr == 0)
      {
        return sizeof(views) / sizeof(views[0]) - 1;
      }
      else
        return viewNr + val;

    default:
      return 0;
  }
}

void changeProgram(int8_t val)
{
  if (isToChange == true)
  {
    viewNr = switchView(val);
    lcd.printTemplate(views[viewNr]);
    lcd.printValue(views[viewNr]);
    measureTime = millis();
    bLightTime = millis();
    isToChange = false;
  }
  else
  {
    lcd.backlight();
    bLightTime = millis();
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(forwardButtonPin, INPUT_PULLUP);
  pinMode(backwardButtonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.printHello();
  lcd.printTemplate(views[viewNr]);
  lcd.printValue(views[viewNr]);
  measureTime = millis();
  bLightTime = millis();
}

void loop()
{
  forwardButtonState = digitalRead(forwardButtonPin);
  backwardButtonState = digitalRead(backwardButtonPin);

  if (forwardButtonState == LOW && backwardButtonState == LOW)
  {
    changeProgram(0);
  }
  else if (forwardButtonState == LOW)
  {
    changeProgram(1);
  }
  else if (backwardButtonState == LOW)
  {
    changeProgram(-1);
  }
  else
  {
    isToChange = true;
  }

  if (millis() > (measureTime + 2500))
  {
    lcd.printValue(views[viewNr]); 
    measureTime = millis();
  }

  if (millis() > (bLightTime + 20000))
  {
    lcd.noBacklight();
    isToChange = false;
  }
  delay(200);
}
