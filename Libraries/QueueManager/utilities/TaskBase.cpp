/* 
* Task.cpp
*
* Created: 1/27/2015 9:49:14 PM
* Author: Ron
*/


#include <TaskLibraries/TaskBase.h>

TaskBase::TaskBase(TaskDefinition taskDef, TaskBase *taskClass)
{
	TaskDef=taskDef;
	task=taskClass;
	IntervalOfExecution=taskDef.IntervalOfExecution;
}

// virtual destructor
TaskBase::~TaskBase()
{
} //~Task

void TaskBase::Run()
{
		
}

void TaskBase::Init()
{
	
}
