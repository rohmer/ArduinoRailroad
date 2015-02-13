// ServoTask.h

#ifndef _SERVOTASK_h
#define _SERVOTASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>

class ServoTask 
{
 protected:
	 byte pin, occupiedPosition, unoccupiedPosition, delay, step;
	 Servo servo;

 public:
	ServoTask(std::vector<byte> arguments, Logger log);
	void Init();
	String GetName();
};

#endif

