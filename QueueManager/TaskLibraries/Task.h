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


using namespace std;

struct TaskDefinition
{
	long IntervalOfExecution;
	std::vector<String> StringArguments;
	std::vector<int> NumericArguments;
};
	
class Task
{	
//functions
public:	
	Task(long IntervalOfExecution);
	virtual ~Task();
	virtual void Run();
	
	// Called by task manager on the first task of this type run
	virtual void Init();
}; //Task

#endif //__TASK_H__
