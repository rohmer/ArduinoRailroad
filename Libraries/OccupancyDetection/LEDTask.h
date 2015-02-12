// LEDTask.h

#ifndef _LEDTASK_h
#define _LEDTASK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "BaseTask.h"
#include "LedControl.h"
#include "Logger.h"

class LEDTask:BaseTask
{
 private:
	 LedControl ledControl;
	 int dataPin, clkPin, loadPin, numMax, ledRow, ledCol, maxAddr;
	 bool occupiedTurnsOnLED;

 protected:


 public:
	 void Init();
	 void Run(bool occupied);
	 LEDTask(std::vector<byte> arguments, Logger log); 
};


#endif

