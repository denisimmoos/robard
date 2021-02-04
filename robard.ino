#include "HCSR04.h"

//#define BaudRate 9600
#define BaudRate 115200

#define CatTriggerPin 30
#define CatEchoPin 31

/*
#define FrontTriggerPin 32
#define FrontEchoPin 33

#define BackTriggerPin 34
#define BackEchoPin 35

#define LeftTriggerPin 36
#define LeftEchoPin 37

#define RightTriggerPin 38
#define RightEchoPin 39

#define BottomTriggerPin 40
#define BottomEchoPin 41
*/

/*
  Construct HCSR04 Sensors
*/

HCSR04 CatSensor(CatTriggerPin, CatEchoPin);
/*
HCSR04 FrontSensor(FrontTriggerPin, FrontEchoPin);
HCSR04 BackSensor(BackTriggerPin, BackEchoPin);
HCSR04 LeftSensor(LeftTriggerPin, LeftEchoPin);
HCSR04 RightSensor(RightTriggerPin, RightEchoPin);
HCSR04 BottomSensor(BottomTriggerPin, BottomEchoPin);
*/

void setup() {



  CatSensor.begin();
  /*
  FrontSensor.begin();
  BackSensor.begin();
  LeftSensor.begin();
  RightSensor.begin();
  */

  Serial.begin(BaudRate);

}

void loop() {

//  Serial.println(cat_sensor.getDelayInMs());
  Serial.println(CatSensor.GetDistInCm());

}
