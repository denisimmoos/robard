/*
  HCSO4.cpp - Library for HCSO4 sensor.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HCSRO4.h"

HCSRO4::HCSRO4(int trigpin, int echopin) {

  pinMode(trigpin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echopin, INPUT); // Sets the echoPin as an Input

  int _trigpin = trigpin;
  int _echopin = echopin;

}

HCSRO4::GetDistInCm() {

  digitalWrite(_trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(_trigpin,HIGH);
  delayMicroseconds(_delay_ms);
  digitalWrite(_trigpin,LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  _duration = pulseIn(_echopin,HIGH);
  _distincm = (_duration - _delay_ms)* 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  distincm = _distincm

}
