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

class LEDTask: public BaseTask
{
 private:
	 LedControl ledControl;
	 int dataPin, clkPin, loadPin, numMax, ledRow, ledCol, maxAddr;
	 bool occupiedTurnsOnLED;
	 void ledLog(int row, int col, bool state);

 protected:


 public:
	 void Init();
	 void Run(bool occupied);
	 LEDTask(std::vector<byte> arguments, Logger log); 
	 String GetName();
	 ~LEDTask();
};


#endif

