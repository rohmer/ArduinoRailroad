// 
// 
// 
#include "DetectorCollection.h"

DetectorCollection::DetectorCollection()
{
}

#include "DetectorCollection.h"
DetectorCollection::DetectorCollection(int _digPin1, int _digPin2, int _digPin3) {
	numDetectors = 0;
	digPins[0] = _digPin1;
	digPins[1] = _digPin2;
	digPins[2] = _digPin3;
}

bool DetectorCollection::AddDetector(int _aPin, int _bit) {	
	//initialise a detector. the array contains "zero'd" detectors
	//by default
	if (numDetectors < 32) {
		detectors[numDetectors].dAnalogPin = _aPin;
		detectors[numDetectors].dBitIndex = _bit;
		for (int idx = 0; idx < 32; idx++)
			detectors[numDetectors].dValues[idx] = 0;
		detectors[numDetectors].dMax = 0;
		detectors[numDetectors].dMin = 999;
		detectors[numDetectors].dRange = 0;
		detectors[numDetectors].dAverageValue = 0;
		detectors[numDetectors].dThreshold = 0;
		detectors[numDetectors].dCurrentIndex = 0;
		detectors[numDetectors].dFullArray = false;
		detectors[numDetectors].dIsActive = false;
		numDetectors++;
		return true;
	}
	else return false;
}

int DetectorCollection::GetDetectorNum(int pin, int bit)
{
	for (int d = 0; d < numDetectors; d++)
	{
		if (detectors[d].dAnalogPin == pin && detectors[d].dBitIndex == bit)
			return d;
	}

	return -1;
}

void DetectorCollection::UpdateDetector(int detector) {
	//set digital pins      
	for (int pin = 0; pin < 3; pin++)
		digitalWrite(digPins[pin],
		((detectors[detector].dBitIndex >> abs(pin - 2)) & 0x01) == true ? HIGH : LOW);


	//read analog pin.
	detectors[detector].dCurrentValue =
		analogRead(detectors[detector].dAnalogPin);
	detectors[detector].dValues[detectors[detector].dCurrentIndex] =
		detectors[detector].dCurrentValue;


	//find the lowest and highest values in the array and store as
	//the minimum and maximum extremities.
	int tempVal, newValue = 0;
	bool extremitiesChanged = false;
	for (int idx = 0; idx < 32; idx++) {
		tempVal = detectors[detector].dValues[idx];
		if (tempVal < detectors[detector].dMin || detectors[detector].dMin == 0) {
			detectors[detector].dMin = tempVal;
			extremitiesChanged = true;
		}
		if (tempVal > detectors[detector].dMax) {
			detectors[detector].dMax = tempVal;
			extremitiesChanged = true;
		}
		//used for average calculated below.
		newValue += tempVal;
	}

	//update range of this detector [max - min]
	detectors[detector].dRange =
		detectors[detector].dMax - detectors[detector].dMin;
	if (newValue > 0) {
		if (detectors[detector].dFullArray)
			detectors[detector].dAverageValue = newValue / 32;
		else detectors[detector].dAverageValue =
			newValue / (detectors[detector].dCurrentIndex + 1);
		//adjust threshold [average + (max-min*0.10)]
		detectors[detector].dThreshold =
			detectors[detector].dAverageValue +
			(detectors[detector].dRange * 0.35);
		//adjust active flag:
		detectors[detector].dIsActive =
			(detectors[detector].dCurrentValue >
			detectors[detector].dThreshold);
	}

	//finally update the next location to store the next incoming value...
	//we're using a circular buffer, so just point to the start of the
	//array instead of shifting everything along.
	detectors[detector].dCurrentIndex++;
	if (detectors[detector].dCurrentIndex >= 32) {
		detectors[detector].dCurrentIndex = 0;
		//for calculating the average, we need to know once 
		//we have a full buffer. Once it's full we will always 
		//have a full set of NUM_READINGS values, otherwise
		//we only have as many as dCurrentIndex
		detectors[detector].dFullArray = true;
	}
}

void DetectorCollection::UpdateAllDetectors() {
	for (int d = 0; d < numDetectors; d++) UpdateDetector(d);
}

bool DetectorCollection::IsActive(int detector) {
	return detectors[detector].dIsActive;
}

int DetectorCollection::GetCurrentValue(int detector) {
	return detectors[detector].dCurrentValue;
}

void DetectorCollection::DebugInformation(int detector) {
	Serial.print("Detector: ");
	Serial.print(detector);
	Serial.print(", APin: ");
	Serial.print(detectors[detector].dAnalogPin);
	Serial.print(", DBit: ");
	Serial.print(detectors[detector].dBitIndex);
	Serial.print(", Min: ");
	Serial.print(detectors[detector].dMin);
	Serial.print(", Max: ");
	Serial.print(detectors[detector].dMax);
	Serial.print(", Range: ");
	Serial.print(detectors[detector].dRange);
	Serial.print(", Threshold: ");
	Serial.print(detectors[detector].dThreshold);
	Serial.print(", Average: ");
	Serial.print(detectors[detector].dAverageValue);
	Serial.print(", Current: ");
	Serial.print(detectors[detector].dCurrentValue);
	Serial.print(", FullArray: ");
	Serial.print(detectors[detector].dFullArray);
	Serial.print(", CurrentIndex: ");
	Serial.println(detectors[detector].dCurrentIndex);
	/*for (int idx = 0; idx < 32; idx++) {
	Serial.print("|");
	if (idx == detectors[detector].dCurrentIndex) Serial.print("*");
	Serial.print(detectors[detector].dValues[idx]);
	}
	Serial.println("|");*/
}


