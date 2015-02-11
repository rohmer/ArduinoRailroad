/* 
* Que	ueManager.cpp
*
* Created: 1/28/2015 11:00:53 AM
* Author: rohmer
*/


#include "QueueManager.h"

Logger *QueueManager::GetLogger()
{
	return logger;
}

// default constructor
QueueManager::QueueManager()
{
	taskQueue=PQueue();
	logger=new Logger(true,true,INFO);
	logger->Log("QueueManager Initalized");
} //QueueManager

// default destructor
QueueManager::~QueueManager()
{
} //~QueueManager

void QueueManager::AddTask(TaskDefinition td, TaskBase task)
{
	logger->Log("Adding task: "+task.TaskName()+" with interval: "+td.IntervalOfExecution);
	taskQueue.Insert(td,task,td.IntervalOfExecution);
	logger->Log("Task Added");
}

unsigned long QueueManager::GetTime()
{
	return now();
}
