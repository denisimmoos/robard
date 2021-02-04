#include "MyHCSR04.h"

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
  Construct MyHCSR04 Sensors
*/

MyHCSR04 CatSensor(CatTriggerPin, CatEchoPin);
/*
MyHCSR04 FrontSensor(FrontTriggerPin, FrontEchoPin);
MyHCSR04 BackSensor(BackTriggerPin, BackEchoPin);
MyHCSR04 LeftSensor(LeftTriggerPin, LeftEchoPin);
MyHCSR04 RightSensor(RightTriggerPin, RightEchoPin);
MyHCSR04 BottomSensor(BottomTriggerPin, BottomEchoPin);
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
