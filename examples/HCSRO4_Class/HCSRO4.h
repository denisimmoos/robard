/*
  HCSRO4.h - Library HCSRO4 sensor.
  Released into the public domain.
*/

#ifndef HCSRO4_h
#define HCSRO4_h

#include "Arduino.h"

class HCSRO4
{

  public:

    HCSRO4(int trigpin, int echopin);
    float GetDistInCm();

  private:

    float _distincm;
    float _duration;
    int _delay_ms = 10;
    int _trigpin;
    int _echopin;

};

#endif
