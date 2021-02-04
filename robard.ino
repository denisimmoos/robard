#include "HCSRO4.h"

//#define BaudRate 9600
#define BaudRate 115200

#define CatTriggerPin 30
#define CatEchoPin 31

// oder sogar
//constexpr byte  CatTriggerPin {30};
//constexpr byte  CatEchoPin    {31};

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
  Construct HCSRO4 Sensors
*/

HCSRO4 CatSensor(CatTriggerPin, CatEchoPin);
/*
HCSRO4 FrontSensor(FrontTriggerPin, FrontEchoPin);
HCSRO4 BackSensor(BackTriggerPin, BackEchoPin);
HCSRO4 LeftSensor(LeftTriggerPin, LeftEchoPin);
HCSRO4 RightSensor(RightTriggerPin, RightEchoPin);
HCSRO4 BottomSensor(BottomTriggerPin, BottomEchoPin);
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
