/*
 * HelperFunctions.h
 *
 *  Created on: Feb 4, 2015
 *      Author: rohmer
 */

#ifndef TASKLIBRARIES_LEDTASK_HELPERFUNCTIONS_H_
#define TASKLIBRARIES_LEDTASK_HELPERFUNCTIONS_H_

#include "LEDTask.h"
#include "LedControl/LEDControl.h"
#include <QueueManager.h>

// Helper functions for creating various LED Tasks
class HelperFunctions {
	// Creates a blink sequence with the light starting with the on option
	static void CreateBlink(QueueManager* queueManager, bool isMega, int controller, int row, int column, long onTime, long offTime);
	static void CreateBlink(QueueManager* queueManager, bool isMega, int controller, int row, int column, long onTime, long offTime, bool startsOn);
};

#endif /* TASKLIBRARIES_LEDTASK_HELPERFUNCTIONS_H_ */
