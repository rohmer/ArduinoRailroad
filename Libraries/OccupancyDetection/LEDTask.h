// LEDTask.h

#ifndef _LEDTASK_h
#define _LEDTASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "BaseTask.h"


class LEDTask:BaseTask
{
 protected:


 public:
	 void Init();
	 void Run();
	 LEDTask(std::vector<int> arguments); 
};


#endif

