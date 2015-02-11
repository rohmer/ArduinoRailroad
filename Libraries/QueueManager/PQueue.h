/*
 * PriorityQueue.h
 *
 *  Created on: Feb 2, 2015
 *      Author: rohmer
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <iterator>
#include <iostream>
#include <stdlib.h>
#include <utilities/TaskBase.h>

class PQueue		// Class Prioriry Queue
{
private:
	struct node			// Node of Priority Queue
	{
		long priority;
		TaskDefinition taskDef;
		TaskBase task;
		struct node *link;
	};
	node *front;
public:
	PQueue();
	void Insert(TaskDefinition taskDef, TaskBase task, long priority);
};

#endif
