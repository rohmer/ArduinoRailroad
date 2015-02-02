/*
 * LEDTask.h
 *
 *  Created on: Jan 31, 2015
 *      Author: Ron
 */

#ifndef TASKLIBRARIES_LEDTASK_LEDTASK_H_
#define TASKLIBRARIES_LEDTASK_LEDTASK_H_

#include "..\Task.h"

class LEDTask: public Task {
public:
	LEDTask(long intervalIntervalOfExecution);
	virtual ~LEDTask();
};

#endif /* TASKLIBRARIES_LEDTASK_LEDTASK_H_ */
