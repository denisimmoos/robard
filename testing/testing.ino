
using namespace std;

#include "MyTca9548aTsl2591.h"
MyTca9548aTsl2591 TopSpectrum(0);  //# <--- i2cBus
MyTca9548aTsl2591 LeftSpectrum(1);
MyTca9548aTsl2591 RightSpectrum(2);
MyTca9548aTsl2591 BackSpectrum(3);

#include "MyHCSR04.h"
MyHCSR04 TopDistance(30,31);
MyHCSR04 LeftDistance(32,33);
MyHCSR04 RightDistance(34,35);
MyHCSR04 BackDistance(36,37);


#define BaudRate 115200

// 
/* an example of struct */ 
struct Sensors{ 
  char name[10];
  float value;
};

/* qsort struct comparision function (value float field) */ 
int CompareSensorsByValue(const void *a, const void *b) 
{ 
    struct Sensors *ia = (struct Sensors *)a;
    struct Sensors *ib = (struct Sensors *)b;
    return (int)(100.f*ia->value - 100.f*ib->value);
	/* float comparison: returns negative if b > a 
	and positive if a > b. We multiplied result by 100.0
	to preserve decimal fraction */ 
 
} 

char *GetSensorNameByPosition(struct Sensors *array, int pos) 
{ 
    return array[pos].name;
} 

float GetSensorValueByPosition(struct Sensors *array, int pos) 
{ 
    return array[pos].value;
} 



void setup(void)
{

  Serial.begin(BaudRate);
  while(!Serial);

  TopDistance.begin();
  LeftDistance.begin();
  RightDistance.begin();
  BackDistance.begin();

  TopSpectrum.begin();
  LeftSpectrum.begin();
  RightSpectrum.begin();
  SepctrumBack.begin();

  // Now we're ready to get readings ... move on to loop()!
}

:
void loop(void)
{

struct Sensors sensors[] = {
	{"TopSpectrum", 	TopSpectrum.getFullSpectrum()}, 
	{"LeftSpectrum", 	LeftSpectrum.getFullSpectrum()}, 
	{"RightSpectrum", 	RightSpectrum.getFullSpectrum()}, 
	{"BackSpectrum", 	BackSpectrum.getFullSpectrum()}
};

size_t sensors_len = sizeof(sensors) / sizeof(struct Sensors);
qsort(sensors, sensors_len, sizeof(struct Sensors), CompareSensorsByValue);

int check_next = 0;

while (check_next <= 3) {

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"TopSpectrum") == 0 ) { 
  if (TopDistance.GetDistInCm() < 10) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Top");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO Top");
	break;
 } 

} 

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"LeftSpectrum") == 0 ) { 
  if (LeftDistance.GetDistInCm() < 10) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Leeft");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO LEEEEFT");
	break;
 } 
} 

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"RightSpectrum") == 0 ) { 
  if (RightDistance.GetDistInCm() < 10) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Right");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO Right");
	break;
 } 
} 

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"BackSpectrum") == 0 ) { 
  if (BackDistance.GetDistInCm() < 10) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Back");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO BACK");
	break;
 } 

} 

}

}

