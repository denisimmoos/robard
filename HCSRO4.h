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
