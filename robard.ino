#include "libraries/HCSRO4/HCSRO4.h"

#define CatTriggerPin 30
#define CatEchoPin 31


HCSRO4 cat_sensor(CatTriggerPin, CatEchoPin);

void setup() {

  Serial.begin(9600);

}

void loop() {

  float hoho = cat_sensor.distincm;
  Serial.println(hoho);

}
