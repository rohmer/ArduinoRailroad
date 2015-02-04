/*
 * HelperFunctions.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: rohmer
 */

#include <TaskLibraries/LEDTask/HelperFunctions.h>

void HelperFunctions::CreateBlink(QueueManager* queueManager, bool isMega, int controller, int row, int column, long onTime, long offTime)
{
	CreateBlink(queueManager, isMega, controller, row, column, onTime, offTime, true);
}

void HelperFunctions::CreateBlink(QueueManager* queueManager, bool isMega, int controller, int row, int column, long onTime, long offTime, bool startsOn)
{
	TaskDefinition taskDefOn;
	taskDefOn.IntervalOfExecution=onTime;

	taskDefOn.NumericArguments.push_back(LEDTask::DefaultDataIn(isMega));
	taskDefOn.NumericArguments.push_back(LEDTask::DefaultCLK(isMega));
	taskDefOn.NumericArguments.push_back(LEDTask::DefaultLoad(isMega));
	taskDefOn.NumericArguments.push_back(1);
	taskDefOn.NumericArguments.push_back(row);
	taskDefOn.NumericArguments.push_back(column);
	taskDefOn.NumericArguments.push_back(1);
	taskDefOn.IntervalOfExecution=onTime;

	LEDTask ledTask(taskDefOn,queueManager->GetLogger());

	TaskDefinition taskDefOff;
	taskDefOff.IntervalOfExecution=offTime;

	taskDefOff.NumericArguments.push_back(LEDTask::DefaultDataIn(isMega));
	taskDefOff.NumericArguments.push_back(LEDTask::DefaultCLK(isMega));
	taskDefOff.NumericArguments.push_back(LEDTask::DefaultLoad(isMega));
	taskDefOff.NumericArguments.push_back(1);
	taskDefOff.NumericArguments.push_back(row);
	taskDefOff.NumericArguments.push_back(column);
	taskDefOff.NumericArguments.push_back(0);
	taskDefOff.IntervalOfExecution=offTime;

	if(startsOn)
	{
		queueManager->AddTask(taskDefOn,(TaskBase)ledTask);
		queueManager->AddTask(taskDefOff,(TaskBase)ledTask);
	} else
	{
		queueManager->AddTask(taskDefOff,(TaskBase)ledTask);
		queueManager->AddTask(taskDefOn,(TaskBase)ledTask);
	}

}
