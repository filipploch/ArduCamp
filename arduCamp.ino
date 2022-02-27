#include "lcd20x4.hpp"
#include "dht22sensor.hpp"
#include "dht11sensor.hpp"
#include "ds18b20sensor.hpp"



const uint8_t forwardButtonPin = 10;
const uint8_t backwardButtonPin = 11;
const uint8_t ledPin =  13;
// const uint8_t nrOfSensors = 5;

// DHT22Sensor inTemp("W KAMPERZE", 7);
// DHT11Sensor outTemp("NA POLU", 8);
// DS18B20Sensor refrig1Temp("LODOWKA 1", 12, 0);
// DS18B20Sensor refrig2Temp("LODOWKA 2", 12, 1);
// DHT22Sensor waterLvl("ZBIORNIK WODY", 13);

// Sensor* sensors[nrOfSensors] = {&inTemp, &outTemp, &refrig1Temp, &refrig2Temp, &waterLvl};
Sensor *sensors[] = {new DHT22Sensor("W KAMPERZE", 7),
                     new DHT11Sensor("NA POLU", 8),
                     new DS18B20Sensor("LODOWKA 1", 12, 0),
                     new DS18B20Sensor("LODOWKA 2", 12, 1),
                     new DHT22Sensor("ZBIORNIK WODY", 13)
                     };

uint8_t forwardButtonState;
uint8_t backwardButtonState;
bool isToChange = true;
uint8_t sensorNr = 0;
unsigned long measureTime = 0;
unsigned long bLightTime = 0;

LCD20x4 lcd(0x27);


void setup() {
  Serial.begin(9600);
  pinMode(forwardButtonPin, INPUT_PULLUP);
  pinMode(backwardButtonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  lcd.printHello();
  lcd.printTemplate(sensors[0]);
  lcd.printValue(sensors[0]);
  measureTime = millis();
  bLightTime = millis();

}

int8_t switchSensor(int8_t val){

  switch (val)
  {
  case 0:
    return 0;

  case 1:
    if (sensorNr == sizeof(sensors)/sizeof(sensors[0]) - 1) {
        return 0;
      }
    else {
        return sensorNr + val;
      }

  case -1:
    if (sensorNr == 0) {
      return sizeof(sensors)/sizeof(sensors[0]) - 1;
    }
    else return sensorNr + val;

  
  default:
    return 0;
  }
}

void changeProgram(int8_t val){
    if (isToChange == true) {
      sensorNr = switchSensor(val);
      lcd.printTemplate(sensors[sensorNr]);
      lcd.printValue(sensors[sensorNr]);
      measureTime = millis();
      bLightTime = millis();
      isToChange = false;
    }
    else {
      lcd.backlight();
      bLightTime = millis();
    }
}

void loop() {
  forwardButtonState = digitalRead(forwardButtonPin);
  backwardButtonState = digitalRead(backwardButtonPin);

  if (forwardButtonState == LOW && backwardButtonState == LOW){
    changeProgram(0);
  }
  else if (forwardButtonState == LOW) {
    changeProgram(1);
  }
  else if (backwardButtonState == LOW){
    changeProgram(-1);
  }
  else {
    digitalWrite(ledPin, LOW);
    isToChange = true;
  }
 
  if (millis() > (measureTime + 2500)) {
    lcd.printValue(sensors[sensorNr]);
    measureTime = millis();
  }

  if (millis() > (bLightTime + 10000)) {
    lcd.noBacklight();
    isToChange = false;
  }
  delay(100);
}
