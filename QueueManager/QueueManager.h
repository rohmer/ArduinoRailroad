/* 
* QueueManager.h
*
* Created: 1/28/2015 11:00:53 AM
* Author: rohmer
*/


#ifndef __QUEUEMANAGER_H__
#define __QUEUEMANAGER_H__
#include <Logger/Logger.h>
#include <TaskLibraries/TaskBase.h>
#include "PQueue.h"

using namespace std;

class QueueManager
{
//variables
public:
protected:
private:
	bool initialized=false;

//functions
public:
	QueueManager();
	~QueueManager();
	void AddTask(TaskDefinition td, TaskBase task);
	Logger *GetLogger();

protected:
private:
	PQueue *taskQueue;
	Logger *logger;

}; //QueueManager

#endif //__QUEUEMANAGER_H__
