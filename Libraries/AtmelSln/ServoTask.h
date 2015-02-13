// ServoTask.h

#ifndef _SERVOTASK_h
#define _SERVOTASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <iterator>
#include <vector>
#include <Logger.h>
#include "BaseTask.h"
#include <Servo.h>

class ServoTask:BaseTask
{
 private:
	 byte pin, occupiedPosition, unoccupiedPosition, delayMS, step;
	 Servo servo;

 protected:

 public:
	ServoTask(std::vector<byte> arguments, Logger log);
	void Init();
	String GetName();
	void Run(bool occupied);
};

#endif

