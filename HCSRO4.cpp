/*
  HCSO4.cpp - Library for HCSO4 sensor.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HCSRO4.h"

HCSRO4::HCSRO4(int trigpin, int echopin) {

  _trigpin = trigpin;
  _echopin = echopin;

}

void HCSRO4::begin() {
  // PinModes setzen
  // die Pins selbst sind aus dem Konstruktor schon bekannt,
  // deshalb verwenden wir die privaten Membervariablen.
  pinMode(_trigpin, OUTPUT); // Sets the trigPin as an Output
  pinMode(_echopin, INPUT); // Sets the echoPin as an Input
}

float HCSRO4::GetDistInCm() {

  float _distincm;
  float _duration;

  digitalWrite(_trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(_trigpin,HIGH);
  delayMicroseconds(_delay_mics);
  digitalWrite(_trigpin,LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  _duration = pulseIn(_echopin,HIGH);
  _distincm = (_duration - _delay_mics)* 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  return _distincm;

}
