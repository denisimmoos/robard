#!/usr/bin/python3

import os
import json
import serial

ser = serial.Serial('/dev/ttyACM0',9600)
ser.flushInput()

def is_json(myjson):
    try:
      json_object = json.loads(myjson)
    except ValueError as e:
      return False
    return True

while True:
    try:
        ser_bytes = ser.readline()
        utf8_msg = ser_bytes.decode('utf-8').rstrip("\n")
        print(utf8_msg)

        if is_json(utf8_msg):
	  # later on this will log to influxdb
          os.system("echo \"" + utf8_msg + "\" >/tmp/subprocess.log &")
          #pass

    except:
        print("Keyboard Interrupt")
        break
