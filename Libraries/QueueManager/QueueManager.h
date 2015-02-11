/* 
* QueueManager.h
*
* Created: 1/28/2015 11:00:53 AM
* Author: rohmer
*/


#ifndef __QUEUEMANAGER_H__
#define __QUEUEMANAGER_H__
#include <Logger.h>
#include <utilities/TaskBase.h>
#include <utilities/PQueue.h>

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
	unsigned long GetTime();

protected:
private:
	PQueue taskQueue;
	Logger *logger;

}; //QueueManager

#endif //__QUEUEMANAGER_H__
