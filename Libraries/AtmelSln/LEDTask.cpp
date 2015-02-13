// 
// 
// 

#include "LEDTask.h"

////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor for LEDTask </summary>
///
/// <remarks>	Rohmer, 2/12/2015. </remarks>
///
/// <param name="arguments"> Vector of byte
/// 						 0 - Data IN of the first Max 72**
/// 						 1 - CLK Pin of the first Max 72**  
/// 						 2 - Load(/CS) pin of the first Max 72**  
/// 						 3 - Number of Max 72** attached      
/// 						 4 - Max Address of the LED to control
/// 						 5 - Row number of LED  
/// 						 6 - Column number of LED 	  
/// 						 7 - Occupied turns on LED if this is 1, turns it off if its zero  
/// 						     Example: 1
/// 						        Entering turns on LED, exiting turns off
/// 						     Example: 0
/// 						        Entering turns off LED, exiting turns on  
/// 						 </param>
////////////////////////////////////////////////////////////////////////////////////////////////

LEDTask::LEDTask(std::vector<byte> arguments, Logger log) : BaseTask(arguments, log)
{
	if (arguments.size() != 8)
		return;
	logger = log;
	dataPin = arguments[0];
	clkPin = arguments[1];
	loadPin = arguments[2];
	numMax = arguments[3];
	maxAddr = arguments[4];
	ledRow = arguments[5];
	ledCol = arguments[6];
	if (arguments[7] == 0)
	{
		occupiedTurnsOnLED = false;
	}
	else
	{
		occupiedTurnsOnLED = true;
	}
	ledControl = LedControl(dataPin, clkPin, loadPin, numMax);
}

////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Runs the task, turning on and off LEDs based on the definition </summary>
///
/// <remarks>	Rohmer, 2/12/2015. 
/// 			May change this eventually to only build with logging in </remarks>
///
////////////////////////////////////////////////////////////////////////////////////////////////
void LEDTask::Run(bool occupied)
{
	if (occupied)
	{
		if (occupiedTurnsOnLED)
		{						
			ledControl.setLed(maxAddr, ledRow, ledCol, true);
			ledLog(ledRow, ledCol, true);
		}
		else
		{
			ledControl.setLed(maxAddr, ledRow, ledCol, false);
			ledLog(ledRow, ledCol, false);
		}
	}
	else
	{
		if (occupiedTurnsOnLED)
		{
			ledControl.setLed(maxAddr, ledRow, ledCol, false);
			ledLog(ledRow, ledCol, false);
		}
		else
		{
			ledControl.setLed(maxAddr, ledRow, ledCol, true);
			ledLog(ledRow, ledCol, true);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Run only on the first LEDTask </summary>
///
/// <remarks>	Rohmer, 2/12/2015. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////

void LEDTask::Init()
{
	int numDevices = ledControl.getDeviceCount();
	for (int address = 0; address < numDevices; address++)
	{
		// Turn off powersaving mode
		ledControl.shutdown(address, false);
		// Set brightness to high
		ledControl.setIntensity(address, 15);
		// Clear
		ledControl.clearDisplay(address);
		logger.Log("LEDTask init");
	}
}

void LEDTask::ledLog(int row, int col, bool state)
{
	char buf[25];
	if (state)
	{
		sprintf(buf, "LED: %d,%d is ON", row, col);
		logger.Log(buf);
	}
	else
	{
		sprintf(buf, "LED: %d,%d is ON", row, col);
		logger.Log(buf);
	}
}

String LEDTask::GetName()
{
	return "LEDTask";
}

LEDTask::~LEDTask()
{
	ledControl.shutdown(maxAddr,true);
}