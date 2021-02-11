# robard

- [robard.ino](robard.ino)

Ardurion code for a robot project I'm working on ...

All libraries written by myself are prefixed with **My***

## MyHCSR04 Sensor Library

- [MyHCSR04.h](MyHCSR04.h)
- [MyHCSR04.cpp](MyHCSR04.cpp)
- [MyHCSR04.ino.example](MyHCSR04.ino.example)

This was my first try to write an ardurion class, I did not know that a class could also remain in a single .h file.

### Information:

The HC-SR04 Ultrasonic Range Sensor uses non-contact ultrasound sonar to measure the distance to an object - they're great for any obstacle avoiding systems on Raspberry Pi robots or rovers! The HC-SR04 consists of two ultrasonic transmitters (basically speakers), a receiver, and a control circuit. The transmitters emit a high frequency ultrasonic sound, which bounce off any nearby solid objects, and the reciever listens for any return echo. That echo is then processed by the control circuit to calculate the time difference between the signal being transmitted and received. This time can subsequently be used, along with some clever math, to calculate the distance between the sensor and the reflecting object!


### Usage:

Have a look at [MyHCSR04.ino.example](MyHCSR04.ino.example)

## MyTca9548aTsl2591 Combined Sensor Library

- [MyTca9548aTsl2591.h](MyTca9548aTsl2591.h)
- [MyTca9548aTsl2591.ino.example](MyTca9548aTsl2591.ino.example)

Basically it makes the Tsl2591 work on the Tca9548a multiplexer by choosing the Tca9548a's i2c-Bus on which the Tsl2591 sensor is connected before performing any operations on the Tsl2591 sensors.

### Tca9548a Information:

You just found the perfect I2C sensor, and you want to wire up two or three or more of them to your Arduino when you realize "Uh oh, this chip has a fixed I2C address, and from what I know about I2C, you cannot have two devices with the same address on the same SDA/SCL pins!" Are you out of luck? You would be, if you didn't have this ultra-cool TCA9548A 1-to-8 I2C multiplexer!

Finally, a way to get up to 8 same-address I2C devices hooked up to one microcontroller - this multiplexer acts as a gatekeeper, shuttling the commands to the selected set of I2C pins with your command.

Using it is fairly straight-forward: the multiplexer itself is on I2C address 0x70 (but can be adjusted from 0x70 to 0x77) and you simply write a single byte with the desired multiplexed output number to that port, and bam - any future I2C packets will get sent to that port. In theory, you could have 8 of these multiplexers on each of 0x70-0x77 addresses in order to control 64 of the same-I2C-addressed-part.

Like all Adafruit breakouts, this nice chip has a breakout for you so you can use it on a breadboard with capacitors, and pullups and pulldowns to make usage a snap. Some header is required and once soldered in you can plug it into a solderless-breadboard. The chip itself is 3V and 5V compliant so you can use it with any logic level.

#### Technical Details

- Weight: 1.8g
- Selectable I2C address 0x70-0x77


### Tsl2591 Information:

When the future is dazzlingly-bright, this ultra-high-range luminosity sensor will help you measure it. The TSL2591 luminosity sensor is an advanced digital light sensor, ideal for use in a wide range of light situations. Compared to low cost CdS cells, this sensor is more precise, allowing for exact lux calculations and can be configured for different gain/timing ranges to detect light ranges from 188 uLux up to 88,000 Lux on the fly.

The best part of this sensor is that it contains both infrared and full spectrum diodes! That means you can separately measure infrared, full-spectrum or human-visible light. Most sensors can only detect one or the other, which does not accurately represent what human eyes see (since we cannot perceive the IR light that is detected by most photo diodes) This sensor is much like the TSL2561 but with a wider range (and the interface code is different). This sensor has a massive 600,000,000:1 dynamic range! Unlike the TSL2561 you cannot change the I2C address, so keep that in mind.

The built in ADC means you can use this with any microcontroller, even if it doesn't have analog inputs. The current draw is extremely low, so its great for low power data-logging systems. about 0.4mA when actively sensing, and less than 5 uA when in power-down mode.

#### Technical Details

- Approximates Human eye Response
- Extremely wide dynamic range 1 to 600,000,000 Counts
- Lux Range: 188 uLux sensitivity, up to 88,000 Lux input measurements.
- Temperature range: -30 to 80 *C
- Voltage range: 3.3-5V into onboard regulator
- Interface: I2C
- This board/chip uses I2C 7-bit address 0x29 (fixed)
- Dimensions: 19mm x 16mm x 1mm / .75" x .63" x .04"
- Weight: 1.1g


### Usage:

Have a look at [MyTca9548aTsl2591.ino.example](MyTca9548aTsl2591.ino.example)
