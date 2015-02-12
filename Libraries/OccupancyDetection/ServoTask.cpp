// 
// 
// 

#include "ServoTask.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Constructor.</summary>
///
/// <remarks>Rohmer, 2/12/2015.</remarks>
///
/// <param name="arguments">
/// 						Argument 0 - Pin Attachment
/// 						Argument 1 - Open Position
/// 						Argument 2 - Close Position
/// 						Argument 3 - Delay (In MS between ticks)
/// 						Argument 4 - Tick size (Degrees) </param>
/// <param name="log">		The log.</param>
////////////////////////////////////////////////////////////////////////////////////////////////////

ServoTask::ServoTask(std::vector<byte> arguments, Logger log)
{
	logger = log;
	if (arguments.size() != 5)
	{
		char buf[40];
		sprintf(buf, "Expected 5 args, got: %d", arguments.size());
		logger.Log(ERROR, buf);
		return;
	}


}

void ServoTask::Init()
{


}


