/*
  MyHCSR04.h - Library for MyHCSR04 sensor.
  Written by Denis Immoos 
  Released into the public domain.
*/

#ifndef MyHCSR04_h
#define MyHCSR04_h

#include "Arduino.h"

class MyHCSR04
{

  public:

    MyHCSR04(int trigpin, int echopin);

    // Zum einmaligen Aufruf in setup()
    void begin();

    float GetDistInCm();


    // Setter
    // Use this to change the delay
    void setDelayInMics(int d) {
      _delay_mics = d;
    }

    // Getter
    int getDelayInMics() {
      return _delay_mics;
    }

  private:

    int _trigpin;
    int _echopin;
    int _delay_mics = 10;

};

#endif
