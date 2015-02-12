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
}

void OccupancyLibrary::Update()
{

}


