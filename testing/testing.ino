
#include "MyTca9548aTsl2591.h"

MyTca9548aTsl2591 TcaTop(0);
MyTca9548aTsl2591 TcaLeft(1);

#define BaudRate 115200

void setup(void)
{
  Serial.begin(BaudRate);
  while(!Serial);

  TcaTop.begin();
  TcaLeft.begin();

  // Now we're ready to get readings ... move on to loop()!
}


void loop(void)
{


  Serial.println("");

  Serial.print("TcaTop.getFullSpectrum():");
  Serial.println(TcaTop.getFullSpectrum());

  Serial.print("TcaTop.getVisibleSpectrum():");
  Serial.println(TcaTop.getVisibleSpectrum());

  Serial.print("TcaTop.getIRSpectrum():");
  Serial.println(TcaTop.getIRSpectrum());

  Serial.print("TcaTop.getLux():");
  Serial.println(TcaTop.getLux());

  Serial.println("");

  Serial.print("TcaLeft.getFullSpectrum():");
  Serial.println(TcaLeft.getFullSpectrum());

  Serial.print("TcaLeft.getVisibleSpectrum():");
  Serial.println(TcaLeft.getVisibleSpectrum());

  Serial.print("TcaLeft.getIRSpectrum():");
  Serial.println(TcaLeft.getIRSpectrum());

  Serial.print("TcaLeft.getLux():");
  Serial.println(TcaLeft.getLux());


}
