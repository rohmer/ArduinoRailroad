// 
// 
// 

#include "BaseTask.h"

BaseTask::BaseTask(std::vector<int> arguments)
{
	std::vector<int>::const_iterator it;
	for (it = arguments.begin(); it != arguments.end(); it++)
		taskArguments.push_back(*it);
}


