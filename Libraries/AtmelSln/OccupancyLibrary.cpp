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

DetectorPins OccupancyLibrary::CreateDetector(int pin, int bit)
{	
	DetectorPins retObj;
	retObj.pin=pin;
	retObj.bit=bit;
	return retObj;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Helper to create LED Tasks Easily</summary>
///
/// <remarks>Rohmer, 2/13/2015.</remarks>
///
/// <param name="blockNum">		  The block number. </param>
/// <param name="dataPin">		  The data pin. </param>
/// <param name="clkPin">		  The clock pin. </param>
/// <param name="loadPin">		  The load pin. </param>
/// <param name="numMax">		  Number of maximums. </param>
/// <param name="maxAddr">		  The maximum address. </param>
/// <param name="ledRow">		  The LED row. </param>
/// <param name="ledCol">		  The LED col. </param>
/// <param name="OccupiedTurnsOn">true to enable, false to disable the occupied turns. </param>
///
/// <returns>The new LED task.</returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

void OccupancyLibrary::CreateLEDTask(int blockNum, byte dataPin, byte clkPin, byte loadPin, byte numMax, byte maxAddr, byte ledRow, byte ledCol, bool OccupiedTurnsOn)
{
	std::vector<byte> args;
	args.push_back(dataPin);
	args.push_back(clkPin);
	args.push_back(loadPin);
	args.push_back(numMax);
	args.push_back(maxAddr);
	args.push_back(ledRow);
	args.push_back(ledCol);
	if(OccupiedTurnsOn)
		args.push_back(1);
	else
		args.push_back(0);
	LEDTask task=LEDTask(args,logger);
	AddBlockTask(blockNum,(BaseTask)task);
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

void OccupancyLibrary::AddBlockTask(int blockNumber, BaseTask task)
{
	if (blockNumber > currentNum)
	{
		logger.Log(ERROR, "Number>current number of blocks defined");
		return;
	}
	
	occupancyBlocks[blockNumber]->AddTask(task);
	bool dupeTask = false;
	for (uint16_t a = 0; a <= tasksInitialized.size(); a++)
	{
		if (tasksInitialized[a].equals(task.GetName()))
			dupeTask = true;
	}
	if (!dupeTask)
		task.Init();
	
	char buf[40];
	sprintf(buf, "Task %s initialized", task.GetName().c_str());
	logger.Log(buf);
}

void OccupancyLibrary::Update()
{
	for (uint8_t a = 0; a <= occupancyBlocks.size(); a++)
	{
		char buf[40];
		sprintf(buf, "Checking block: %d", a);
		logger.Log(buf);
		occupancyBlocks[a]->ProcessBlock();
	}
}


