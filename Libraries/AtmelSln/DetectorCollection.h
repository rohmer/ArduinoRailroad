// DetectorCollection.h

#ifndef _DETECTORCOLLECTION_h
#define _DETECTORCOLLECTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class DetectorCollection {
private:
	struct Detector {
		int dValues[32];
		int dMax;
		int dMin;
		int dRange;
		int dAverageValue;
		int dCurrentValue;
		int dThreshold;
		int dCurrentIndex;
		bool dFullArray;
		int dAnalogPin;
		int dBitIndex;
		bool dIsActive;
	} detectors[32];
	int numDetectors;
	int digPins[3];
public:
	DetectorCollection(int _digPin1, int _digPin2, int _digPin3);
	DetectorCollection();
	bool AddDetector(int _aPin, int _bit);
	void UpdateDetector(int detector);
	void UpdateAllDetectors();
	bool IsActive(int detector);
	void DebugInformation(int detector);
	int GetCurrentValue(int detector);
	int GetDetectorNum(int pin, int bit);
};


#endif

