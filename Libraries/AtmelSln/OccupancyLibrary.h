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
#include <Servo.h>
#include "ServoTask.h"
#include <stlport.h>
#include <stdlib.h>
#include <SPI.h>
#include <Logger.h>
#include "LEDTask.h"
#include "BaseTask.h"
#include "LEDTask.h"
#include "ServoTask.h"
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>

class OccupancyLibrary
{
 private:
	
	 DetectorCollection detectors;
	 bool debugMode = false;

	 int mPinA, mPinB, mPinC;
	 Logger logger;
	 std::vector<OccupancyBlock*> occupancyBlocks;
	 std::vector<String> tasksInitialized;
	 int currentNum;

 protected:
	 void init();

 public:
	OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog);		
	OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool logSerial, bool logSD, Severity minSevToLog, bool debug);

	int CreateBlock(std::vector<DetectorPins> activationTriggers, std::vector<DetectorPins> closingTriggers);
	void AddAdjacentBlocks(int block, std::vector<int> adjacentBlocks);
	void AddBlockTask(int blockNumber, BaseTask task);
	 
	void Update();
	DetectorPins CreateDetector(int pin, int bit);
	void CreateLEDTask(int blockNum, byte dataPin, byte clkPin, byte loadPin, byte numMax, byte maxAddr, byte ledRow, byte ledCol, bool OccupiedTurnsOn);
	
};


#endif

