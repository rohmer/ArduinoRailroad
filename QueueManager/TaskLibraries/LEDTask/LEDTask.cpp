/*
 * LEDTask.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Ron
 */

#include "LEDTask.h"

// taskDef:
// 		NumericArguments[0] = DataIn
//		NumericArguments[1] = CLK
//		NumericArguments[2] = LOAD
//		NumericArguments[3] = NumberOfDevices
//		NumericArguments[4] = Row of LED
//		NumericArguments[5] = Column of LED
//		NumericArguments[6] = 0=off, >1 On
//		NumericArguments[7] = (OPTIONAL) Device Controller

LEDTask::LEDTask(TaskDefinition taskDef, Logger* logger) : TaskBase(taskDef, this)
{
	TaskBase::task=this;
	TaskBase::log=logger;

	if(!taskDef.NumericArguments.size()>=7)
	{
		TaskBase::ValidTask=false;
		TaskBase::log->Log(ERROR,"Invalid number of arguments sent, expected 6 got: "+taskDef.NumericArguments.size());
		return;
	}

	row=taskDef.NumericArguments[4];
	column=taskDef.NumericArguments[5];
	if(taskDef.NumericArguments[6]>15)
	{
		powerMode=true;
	} else
	{
		powerMode=false;
	}

	if(taskDef.NumericArguments.size()>7)
	{
		deviceController=taskDef.NumericArguments[7];
	} else
	{
		deviceController=0;
	}

	if(!TaskBase::MaxControllerInitialized)
	{
		TaskBase::ledControl=LedControl(taskDef.NumericArguments[0],taskDef.NumericArguments[1],taskDef.NumericArguments[2],taskDef.NumericArguments[3]);
		/*
		   The MAX72XX is in power-saving mode on startup,
		   we have to do a wakeup call
		*/
		TaskBase::ledControl.shutdown(0,false);
		/* Set the brightness to a medium values */
		TaskBase::ledControl.setIntensity(0,15);
		/* and clear the display */
		TaskBase::ledControl.clearDisplay(0);
	}
}

void LEDTask::Run()
{
	TaskBase::log->Log("Entering LEDTask::Run()");
	TaskBase::ledControl.setLed(deviceController,row,column,powerMode);
	TaskBase::log->Log("Exiting LEDTask::Run()");
}

String LEDTask::TaskName()
{
	return ("LEDTask");
}

LEDTask::~LEDTask() {
	// TODO Auto-generated destructor stub
}

