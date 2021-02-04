# robard

Ardurion code for a robot project I'm working on ...

## HCSR04 Sensor Library

- [HCSR04.h](HCSR04.h)
- [HCSR04.cpp](HCSR04.cpp)
- [HCSR04.ino.example](HCSR04.ino.example)

### Information:

The HC-SR04 Ultrasonic Range Sensor uses non-contact ultrasound sonar to measure the distance to an object - they're great for any obstacle avoiding systems on Raspberry Pi robots or rovers! The HC-SR04 consists of two ultrasonic transmitters (basically speakers), a receiver, and a control circuit. The transmitters emit a high frequency ultrasonic sound, which bounce off any nearby solid objects, and the reciever listens for any return echo. That echo is then processed by the control circuit to calculate the time difference between the signal being transmitted and received. This time can subsequently be used, along with some clever math, to calculate the distance between the sensor and the reflecting object!


### Usage: 

Have a look at [HCSR04.ino.example](HCSR04.ino.example)



