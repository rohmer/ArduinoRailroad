// BaseTask.h

#ifndef _BASETASK_h
#define _BASETASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include<iterator>
#include<vector>

class BaseTask
{
 protected:
	 std::vector<int> taskArguments;

 public:	
	 BaseTask(std::vector<int> arguments);
	 virtual void Run();
};


#endif

