
using namespace std;

#include "MyTca9548aTsl2591.h"
MyTca9548aTsl2591 TopSpect(0);  //# <--- i2cBus
MyTca9548aTsl2591 LeftSpect(1);
MyTca9548aTsl2591 RightSpect(2);
MyTca9548aTsl2591 BackSpect(3);

#include "MyHCSR04.h"
MyHCSR04 TopDist(30,31);
//MyHCSR04 LeftDist(32,33);
//MyHCSR04 RightDist(34,35);
//MyHCSR04 BackDist(36,37);


#define BaudRate 9600
#define KeepDist 10.0

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

  TopDist.begin();
 // LeftDist.begin();
//  RightDist.begin();
 // BackDist.begin();

  TopSpect.begin();
  LeftSpect.begin();
  RightSpect.begin();
  BackSpect.begin();

  // Now we're ready to get readings ... move on to loop()!
}

void loop(void)
{

struct Sensors sensors[] = {
	{"TopSpect", 	TopSpect.getFullSpectrum()},
	{"LeftSpect", 	LeftSpect.getFullSpectrum()},
	{"RightSpect", RightSpect.getFullSpectrum()},
	{"BackSpect", 	BackSpect.getFullSpectrum()}
};

size_t sensors_len = sizeof(sensors) / sizeof(struct Sensors);

qsort(sensors, sensors_len, sizeof(struct Sensors), CompareSensorsByValue);

int check_next = 0;

while (check_next < sensors_len) {

  	Serial.println("HUUUU Top");
  	Serial.println(GetSensorNameByPosition(sensors, check_next));


if ( strcmp(GetSensorNameByPosition(sensors, check_next),"TopSpect") == 0 ) {
  if (TopDist.GetDistInCm() < KeepDist) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Top");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO Top");
	break;
 }

}

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"LeftSpect") == 0 ) {
  if (TopDist.GetDistInCm() < KeepDist) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Leeft");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO LEEEEFT");
	break;
 }
}

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"RightSpect") == 0 ) {
  if (TopDist.GetDistInCm() < KeepDist) {
	check_next += 1;
  	Serial.println("STOOOOOOOP Right");
  	Serial.println(check_next);
  } else {
  	Serial.println("GOOOOO Right");
	break;
 }
}

if ( strcmp(GetSensorNameByPosition(sensors, check_next),"BackSpect") == 0 ) {
  if (TopDist.GetDistInCm() < KeepDist) {
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
