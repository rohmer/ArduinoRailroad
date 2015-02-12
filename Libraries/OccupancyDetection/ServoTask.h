// ServoTask.h

#ifndef _SERVOTASK_h
#define _SERVOTASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>

class ServoTask : BaseTask
{
 protected:


 public:
	ServoTask(std::vector<byte> arguments, Logger log);
	void Init();
};

#endif

