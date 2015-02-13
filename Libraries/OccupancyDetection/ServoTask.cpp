// 
// 
// 

#include "ServoTask.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Constructor.</summary>
///
/// <remarks>Rohmer, 2/12/2015.
/// 		 Remember - Arduino is NOT multithreaded, so if you set the step size tiny and the Delay
/// 		 huge, everything on your controlled will be paused until this is done
/// 		 </remarks>
///
/// <param name="arguments">
/// 						Argument 0 - Pin Attachment
/// 						Argument 1 - Occupied Position 
/// 						Argument 2 - Unoccupied Position
/// 						Argument 3 - Delay (In MS between ticks)
/// 						Argument 4 - Step size (Degrees) </param>
/// <param name="log">		The log.</param>
////////////////////////////////////////////////////////////////////////////////////////////////////

ServoTask::ServoTask(std::vector<byte> arguments, Logger log) : BaseTask(arguments,log)
{
	logger = log;
	if (arguments.size() != 5)
	{
		char buf[40];
		sprintf(buf, "Expected 5 args, got: %d", arguments.size());
		logger.Log(ERROR, buf);
		return;
	}

	pin = arguments[0];
	occupiedPosition = arguments[1];
	unoccupiedPosition = arguments[2];
	delay = arguments[3];
	step = arguments[4];
	servo.attach(pin);
	char msg[40] = "ServoTask initalized";
	logger.Log(msg);
}

void ServoTask::Init()
{


}

String ServoTask::GetName()
{
	return "ServoTask";
}


