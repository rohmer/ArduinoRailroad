/* 
* QueueManager.cpp
*
* Created: 1/28/2015 11:00:53 AM
* Author: rohmer
*/


#include "QueueManager.h"

// default constructor
QueueManager::QueueManager()
{
	taskQueue=new PQueue();
	logger=new Logger(true,true,INFO);
	logger->Log("QueueManager Initalized");
} //QueueManager

// default destructor
QueueManager::~QueueManager()
{
} //~QueueManager

void QueueManager::AddTask(TaskDefinition td, TaskBase *task)
{
	logger->Log("Adding task: "+task->TaskName()+" with interval: "+td.IntervalOfExecution);
	taskQueue->Insert(task);
	logger->Log("Task Added");
}
