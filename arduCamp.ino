#include "lcd20x4.hpp"
#include "ds18b20sensor.hpp"
#include "htrSensor.hpp"
#include "voltageSensor.hpp"

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
uint8_t sensorNr;
unsigned long measureTime;
unsigned long bLightTime;

LCD20x4 lcd(0x27);

int8_t switchSensor(int8_t val)
{

  switch (val)
  {
    case 0:
      return 0;

    case 1:
      if (sensorNr == sizeof(sensors) / sizeof(sensors[0]) - 1)
      {
        return 0;
      }
      else
      {
        return sensorNr + val;
      }

    case -1:
      if (sensorNr == 0)
      {
        return sizeof(sensors) / sizeof(sensors[0]) - 1;
      }
      else
        return sensorNr + val;

    default:
      return 0;
  }
}

void changeProgram(int8_t val)
{
  if (isToChange == true)
  {
    sensorNr = switchSensor(val);
    lcd.printTemplate(sensors[sensorNr]);
    lcd.printValue(sensors[sensorNr]);
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
  lcd.printTemplate(sensors[sensorNr]);
  lcd.printValue(sensors[sensorNr]);
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
    lcd.printValue(sensors[sensorNr]); 
    measureTime = millis();
  }

  if (millis() > (bLightTime + 20000))
  {
    lcd.noBacklight();
    isToChange = false;
  }
  delay(200);
}
