#include <PQueue.h>


PQueue::PQueue()
{
	front = NULL;
}

PQueue::~PQueue()
{
	// Need to actually clean up
}

/*
* Insert into Priority Queue
*/
void PQueue::Insert(TaskDefinition taskDef, TaskBase task, long priority)
{
	node *tmp, *q;
	tmp = new node;
	tmp->task = task;
	tmp->taskDef=taskDef;

	tmp->priority = priority;

	if (front == NULL || priority < front->priority)
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while (q->link != NULL && q->link->priority <= priority)
			q=q->link;
		tmp->link = q->link;
		q->link = tmp;
	}
}
