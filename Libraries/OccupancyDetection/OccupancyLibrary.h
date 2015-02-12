// OccupancyLibrary.h

#ifndef _OCCUPANCYLIBRARY_h
#define _OCCUPANCYLIBRARY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "DetectorCollection.h"
#include "OccupancyBlock.h"
#include "Common.h"

class OccupancyLibrary
{
 private:
	
	 DetectorCollection detectors;
	 bool debugMode = false;

	 int mPinA, mPinB, mPinC;
	 Logger logger;
	 std::vector<OccupancyBlock*> occupancyBlocks;
	 int currentNum;

 protected:
	 void init();

 public:
	 OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog);		
	 OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog, bool debug);

	 int CreateBlock(std::vector<DetectorPins> activationTriggers, std::vector<DetectorPins> closingTriggers, std::vector<BaseTask*> tasks);
	 void AddAdjacentBlocks(int block, std::vector<int> adjacentBlocks);
	 
	 void Update();

};


#endif

