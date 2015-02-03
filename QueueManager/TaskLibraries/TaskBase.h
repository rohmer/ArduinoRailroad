/* 
* Task.h
*
* Created: 1/27/2015 9:49:14 PM
* Author: Ron
*/


#ifndef __TASK_H__
#define __TASK_H__

#include <WString.h>
#include <iterator>
#include <vector>
#include "TaskLibraries/LEDTask/LedControl/LedControl.h"
#include "Logger/Logger.h"

struct TaskDefinition
{
	long IntervalOfExecution;
	std::vector<String> StringArguments;
	std::vector<int> NumericArguments;
};
	
class TaskBase
{	
//functions
public:	
	TaskBase(TaskDefinition taskDef, TaskBase *taskClass);
	TaskBase();
	TaskDefinition TaskDef;
	virtual ~TaskBase();
	virtual void Run();
	virtual String TaskName();
	
	// Called by task manager on the first task of this type run
	virtual void Init();
	bool ValidTask=true;

	long IntervalOfExecution;

	// Added to keep from initializing the LED controller more than once
	// Eventually may want to keep this sort of thing in a dictionary in the base class (Here)
	// to avoid having to code it in
	bool MaxControllerInitialized=false;

	LedControl ledControl;


protected:
	TaskBase *task;
	Logger* log;

}; //Task

#endif //__TASK_H__
