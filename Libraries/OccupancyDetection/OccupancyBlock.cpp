// 
// 
// 

#include "OccupancyBlock.h"

OccupancyBlock::OccupancyBlock(DetectorCollection detectors, int number)
{	
	detectorCollection = detectors;
	this->number = number;
	init();
}

void OccupancyBlock::init()
{
	isOccupied = false;
	adjacentOccupied = false;
}

void OccupancyBlock::AddActivationTrigger(int pin, int bit)
{
	int detectorNum = detectorCollection.GetDetectorNum(pin, bit);
	if (detectorNum == -1)
	{
		detectorCollection.AddDetector(pin, bit);
		detectorNum = detectorCollection.GetDetectorNum(pin, bit);
	}
	activationTriggers.push_back(detectorNum);
}

void OccupancyBlock::AddClosingTrigger(int pin, int bit)
{
	int detectorNum = detectorCollection.GetDetectorNum(pin, bit);
	if (detectorNum == -1)
	{
		detectorCollection.AddDetector(pin, bit);
		detectorNum = detectorCollection.GetDetectorNum(pin, bit);
	}
	closingTriggers.push_back(detectorNum);
}

void OccupancyBlock::AddAdjacentBlock(OccupancyBlock* obPtr)
{
	adjacentBlocks.push_back(obPtr);
}

void OccupancyBlock::AdjacentOccupied(bool flag)
{
	adjacentOccupied = flag;
}

void OccupancyBlock::ProcessBlock()
{
	// First lets see if we are occupied
	std::vector<int>::const_iterator it;
	for (it = activationTriggers.begin(); it != activationTriggers.end(); it++)
	{
		if (detectorCollection.IsActive(*it))
		{
			if (!isOccupied)						// Only run on state change
			{
				isOccupied = true;
				std::vector<OccupancyBlock*>::iterator iter;
				for (iter = adjacentBlocks.begin(); iter != adjacentBlocks.end(); iter++)
				{
					(*iter)->AdjacentOccupied(true);
				}
				
				std::vector<BaseTask*>::iterator taskIterator;
				for (taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
				{
					(*taskIterator)->Run(isOccupied);
				}
				return;
			}
		}
	}

	// We havent hit occupied, so we arent, but we might be closing
	if (!isOccupied)
		return;

	for (it = closingTriggers.begin(); it != closingTriggers.end(); it++)
	{
		if (!detectorCollection.IsActive(*it))
		{
			isOccupied = false;
			std::vector<BaseTask*>::iterator taskIterator;
			for (taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
			{
				(*taskIterator)->Run(isOccupied);
			}

			return;
		}
	}
}
	
void OccupancyBlock::AddTask(BaseTask* task)
{
	tasks.push_back(task);
}