// 
// 
// 

#include "OccupancyLibrary.h"

OccupancyLibrary::OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog)
{
	mPinA = multiplexerPinBitA;
	mPinB = multiplexerPinBitB;
	mPinC = multiplexerPinBitC;	
	logger = Logger(logSerial, logSD, minSevToLog);
	init();
}

OccupancyLibrary::OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog, bool debug)
{
	mPinA = multiplexerPinBitA;
	mPinB = multiplexerPinBitB;
	mPinC = multiplexerPinBitC;
	logger = Logger(logSerial, logSD, minSevToLog);
	debugMode = debug;
	init();
}

void OccupancyLibrary::init()
{
	detectors = DetectorCollection(mPinA, mPinB, mPinC);
	currentNum = 0;
}

int OccupancyLibrary::CreateBlock(std::vector<DetectorPins> activationTriggers, std::vector<DetectorPins> closingTriggers)
{
	OccupancyBlock block = OccupancyBlock(detectors,currentNum);
	currentNum++;
	std::vector<DetectorPins>::iterator it;
	for (it = activationTriggers.begin(); it != activationTriggers.end(); it++)
	{
		block.AddActivationTrigger(it->pin, it->bit);
	}
	for (it = closingTriggers.begin(); it != closingTriggers.end(); it++)
	{
		block.AddClosingTrigger(it->pin, it->bit);
	}
	
	return currentNum;
}

void OccupancyLibrary::AddAdjacentBlocks(int number, std::vector<int> adjacentBlocks)
{
	if (number > currentNum)
	{
		logger.Log(ERROR, "Number>current number of blocks defined");
		return;
	}
	
	std::vector<int>::iterator it;
	for (it = adjacentBlocks.begin(); it != adjacentBlocks.end(); it++)
	{		
		if (*it > currentNum)
		{
			char buf[40];
			sprintf(buf, "Number: %d > total blocks", *it);
			logger.Log(ERROR, buf);
		}
		else
		{
			occupancyBlocks[number]->AddAdjacentBlock(occupancyBlocks[*it]);
		}
	}
}

void OccupancyLibrary::AddBlockTask(int blockNumber, BaseTask task, std::vector<byte> arguments)
{
	if (blockNumber > currentNum)
	{
		logger.Log(ERROR, "Number>current number of blocks defined");
		return;
	}
	
	occupancyBlocks[blockNumber]->AddTask(task&);
	bool dupeTask = false;
	for (int a = 0; a <= tasksInitialized.size(); a++)
	{
		if (tasksInitialized[a].equals(task.GetName))
			dupeTask = true;
	}
	if (!dupeTask)
		task.Init();
	char buf[40];
	sprintf(buf, "Task %s initalized", task.GetName());
	logger.Log(buf);
}

void OccupancyLibrary::Update()
{

}


