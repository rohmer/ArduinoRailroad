// OccupancyLibrary.h

#ifndef _OCCUPANCYLIBRARY_h
#define _OCCUPANCYLIBRARY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "DetectorCollection.h"

class OccupancyLibrary
{
 private:
	 DetectorCollection detectors;
	 bool debugMode = false;

	 int mPinA, mPinB, mPinC;

 protected:
	 void init();

 public:
	 OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC);		
	 OccupancyLibrary(int multiplexerPinBitA, int multiplexerPinBitB, int multiplexerPinBitC, bool debug);

	 void Update();

};


#endif

