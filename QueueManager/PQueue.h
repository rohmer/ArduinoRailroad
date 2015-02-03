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
#include <TaskLibraries/TaskBase.h>

class PQueue		// Class Prioriry Queue
{
private:
	struct Node			// Node of Priority Queue
	{
		struct Node *Previous;
		TaskBase *data;
		struct Node *Next;
	} Current;

	struct Node *head;	// Pointer to Head
	struct Node *ptr;
		// Pointer for travelling through Queue
	static int NumOfNodes;
		// Keeps track of Number of nodes
public:
	PQueue();
	PQueue(TaskBase* td);
	TaskBase Maximum(void);
	TaskBase Minimum(void);
	void Insert(TaskBase*);
	int Delete(TaskDefinition);
	~PQueue(void);
};

#endif /* PQUEUE_H_ */
