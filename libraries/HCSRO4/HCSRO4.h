/*
  HCSRO4.h - Library HCSRO4 sensor.
  Created by Denis Immoos <denisimmoos@gmail.com>.
  Released into the public domain.
*/

#ifndef HCSRO4_h
#define HCSRO4_h

#include "Arduino.h"

class HCSRO4
{

  public:

    HCSRO4(int trigpin, int echopin);
    void GetDistInCm();
    float distincm;

  private:

    float _distincm;
    float _duration;
    int _delay_ms = 10;
    int _trigpin;
    int _echopin;

};

#endif
