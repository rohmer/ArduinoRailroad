// 
// 
// 

#include "OccupancyLibrary.h"

OccupancyLibrary::OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC)
{
	mPinA = multiplexerPinBitA;
	mPinB = multiplexerPinBitB;
	mPinC = multiplexerPinBitC;
	init();
}

OccupancyLibrary::OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool debug)
{
	mPinA = multiplexerPinBitA;
	mPinB = multiplexerPinBitB;
	mPinC = multiplexerPinBitC;
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


