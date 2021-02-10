/*
  MyTca9548aTsl2591.h
  Released into the public domain.
*/

#ifndef MyTca9548aTsl2591_h
#define MyTca9548aTsl2591_h

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"

class MyTca9548aTsl2591
{
  private:
 	int _i2cBus;

  public:

  MyTca9548aTsl2591(int i2cBus){
 		_i2cBus = i2cBus;
	};

	Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

	void tcaselect(uint8_t i) {
	  if (i > 7) return;
	  Wire.begin();
	  Wire.beginTransmission(0x70);
	  Wire.write(1 << i);
	  Wire.endTransmission();
	}

	void configureSensor(void)
	{
	  	  tcaselect(_i2cBus);

		  Serial.print(F("i2cBus:         "));
		  Serial.println(_i2cBus);

		  if (tsl.begin())
		  {
 		   Serial.println(F("Found a TSL2591 sensor ..."));
		  }
		  else
		  {
		    Serial.println(F("No sensor found ... check your wiring?"));
		    while (1);
		 }

		// You can change the gain on the fly, to adapt to brighter/dimmer light situations
		//tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
		tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
		//tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain

		// Changing the integration time gives you a longer time over which to sense light
		// longer timelines are slower, but are good in very low light situtations!
		tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
		// tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
		//tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
		// tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
		// tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
		// tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)

		/* Display the gain and integration time for reference sake */
		Serial.print  (F("Gain:         "));
		tsl2591Gain_t gain = tsl.getGain();
		switch(gain)
		{
		case TSL2591_GAIN_LOW:
		Serial.println(F("1x (Low)"));
		break;
		case TSL2591_GAIN_MED:
		Serial.println(F("25x (Medium)"));
		break;
		case TSL2591_GAIN_HIGH:
		Serial.println(F("428x (High)"));
		break;
		case TSL2591_GAIN_MAX:
		Serial.println(F("9876x (Max)"));
		break;
		}
		Serial.print  (F("Timing:       "));
		Serial.print((tsl.getTiming() + 1) * 100, DEC);
		Serial.println(F(" ms"));
		Serial.println(F("------------------------------------"));
		Serial.println(F(""));
	}

	void begin() {
  		Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591); // pass in a number for the sensor identifier (for your use later)
  		configureSensor();
	}

	float getLux()
	{
	  tcaselect(_i2cBus);
	  uint32_t lum = tsl.getFullLuminosity();
	  uint16_t ir, full;
	  ir = lum >> 16;
	  full = lum & 0xFFFF;
	  return tsl.calculateLux(full, ir);
	}

	int getFullSpectrum()
	{
	  tcaselect(_i2cBus);
	  uint16_t full = tsl.getLuminosity(TSL2591_FULLSPECTRUM);
	  return full;
	}

	int getVisibleSpectrum()
	{
	  tcaselect(_i2cBus);
	  uint16_t visible = tsl.getLuminosity(TSL2591_VISIBLE);
	  return visible;
	}

	int getIRSpectrum()
	{
	  tcaselect(_i2cBus);
	  uint16_t ir = tsl.getLuminosity(TSL2591_INFRARED);
	  return ir;
	}


};

#endif
