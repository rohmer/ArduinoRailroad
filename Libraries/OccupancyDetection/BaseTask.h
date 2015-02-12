// BaseTask.h

#ifndef _BASETASK_h
#define _BASETASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <iterator>
#include <vector>
#include "Logger.h"

class BaseTask
{
 protected:
	 std::vector<byte> taskArguments;
	 Logger logger;

 public:	
	 BaseTask(std::vector<byte> arguments, Logger log);
	 virtual void Run(bool occupied);
};


#endif

