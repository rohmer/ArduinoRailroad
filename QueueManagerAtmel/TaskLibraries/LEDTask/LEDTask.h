/*
 * LEDTask.h
 *
 *  Created on: Jan 31, 2015
 *      Author: Ron
 */

#ifndef TASKLIBRARIES_LEDTASK_LEDTASK_H_
#define TASKLIBRARIES_LEDTASK_LEDTASK_H_

#include <TaskLibraries/TaskBase.h>
#include "Logger/Logger.h"

class LEDTask: public TaskBase {
public:
	LEDTask(TaskDefinition taskDef, Logger* logger);
	virtual ~LEDTask();
	void Run();
	String TaskName();
	static int DefaultDataIn(bool isMega);
	static int DefaultCLK(bool isMega);
	static int DefaultLoad(bool isMega);


private:
	short row;
	short column;
	bool powerMode;
	short deviceController;
};

#endif /* TASKLIBRARIES_LEDTASK_LEDTASK_H_ */
