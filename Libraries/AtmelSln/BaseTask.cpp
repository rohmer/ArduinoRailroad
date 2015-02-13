// 
// 
// 

#include "BaseTask.h"

BaseTask::BaseTask(std::vector<byte> arguments, Logger log)
{
	std::vector<byte>::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++)
		taskArguments.push_back(*it);
	logger = log;
}
