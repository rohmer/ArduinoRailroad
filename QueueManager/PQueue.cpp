/*
 * PriorityQueue.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: rohmer
 */

#include <PQueue.h>

// First Nodes Created With Constructor
	int PQueue::NumOfNodes=1;

	PQueue::PQueue()
	{
		Current.Previous=NULL;
		Current.Next=NULL;
		head=NULL;
		ptr=NULL;
	}

	// Constructor
	PQueue::PQueue(TaskBase *td)
	{
		Current.Previous=NULL;
		Current.data=td;
		Current.Next=NULL;
		head=&Current;
		ptr=head;
	}
	// Function Finding Maximum Priority Element
	TaskBase PQueue::Maximum(void)
	{
		TaskBase *Temp;
		ptr=head;
		Temp=ptr->data;

		while(ptr->Next!=NULL)
		{
			if(ptr->data->IntervalOfExecution>Temp->IntervalOfExecution)
				Temp=ptr->data;
			ptr=ptr->Next;
		}
		if(ptr->Next==NULL && ptr->data->IntervalOfExecution>Temp->IntervalOfExecution)
			Temp=ptr->data;
		return(*Temp);
	}
	// Function Finding Minimum Priority Element
	TaskBase PQueue::Minimum(void)
	{
		TaskBase *Temp;
		ptr=head;
		Temp=ptr->data;

		while(ptr->Next!=NULL)
		{
			if(ptr->data->IntervalOfExecution<Temp->IntervalOfExecution)
				Temp=ptr->data;
			ptr=ptr->Next;
		}
		if(ptr->Next==NULL && ptr->data->IntervalOfExecution<Temp->IntervalOfExecution)
			Temp=ptr->data;
		return(*Temp);
	}
	// Function inserting element in Priority Queue
	void PQueue::Insert(TaskBase *td)
	{
		if(head==NULL)
		{
			Current.Previous=NULL;
			Current.data=td;
			Current.Next=NULL;
			head=&Current;
			ptr=head;
			return;
		}

		struct Node *newnode;

		newnode=new Node;

		newnode->data=td;

		while(ptr->Next!=NULL)
			ptr=ptr->Next;
		if(ptr->Next==NULL)
		{
			newnode->Next=ptr->Next;
			ptr->Next=newnode;
		}
		NumOfNodes++;
	}

	// Destructor of Priority Queue
	PQueue::~PQueue(void)
	{
		struct Node *temp;                      /* Temporary variable */
		while(head->Next!=NULL)
		{
			temp=head->Next;
	//		delete head;
			head=temp;
		}
		if(head->Next==NULL)
			delete head;
	}
