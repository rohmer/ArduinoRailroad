// OccupancyBlock.h

#ifndef _OCCUPANCYBLOCK_h
#define _OCCUPANCYBLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <iterator>
#include <vector>
#include "DetectorCollection.h"
#include "BaseTask.h"

class OccupancyBlock
{
 protected:
	 std::vector<int> activationTriggers;
	 std::vector<int> closingTriggers;
	 std::vector<OccupancyBlock*> adjacentBlocks;
	 std::vector<BaseTask*> tasks;

	 bool isOccupied;
	 bool adjacentOccupied;
	 DetectorCollection detectorCollection;
	 void init();
	 int number;

 public:
	 OccupancyBlock(DetectorCollection detectors, int number);
	 void AddActivationTrigger(int pin, int bit);
	 void AddClosingTrigger(int pin, int bit);	 
	 void ProcessBlock();
	 void AddAdjacentBlock(OccupancyBlock* obPtr);
	 void AdjacentOccupied(bool flag);	 
	 void AddTask(BaseTask* task);
};

#endif

