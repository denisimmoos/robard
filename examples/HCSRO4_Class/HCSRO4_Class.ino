#include "HCSRO4.h"

//#define BaudRate 9600
#define BaudRate 115200
#define CatTriggerPin 31
#define CatEchoPin 30


HCSRO4 cat_sensor(CatTriggerPin, CatEchoPin);

void setup() {

  cat_sensor.begin();
  Serial.begin(BaudRate);

}

void loop() {

  Serial.println(cat_sensor.GetDistInCm());

}
