/* 
* SD.h
*
* Created: 1/28/2015 11:43:26 AM
* Author: rohmer
*/


#ifndef __SD_H__
#define __SD_H__

#ifdef __AVR_ATmega2560__
#define MEGA_SOFT_SPI 1
#endif

#include "SdFat/SdFat.h"
#include "SdFat/SdFatConfig.h"
#include "WString.h"
#include "Appender.h"
#include "../Common.h"
#include "Time/Time.h"

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class SDAppender : public Appender
{
//variables
	public:
	protected:
	private:
		int mosiPin;
		int misoPin;
		int clkPin;
		int csPin;
		int sckPin;
		bool initialized;		
		SdFile logfile;
		SdFat sd;
		uint8_t spiSpeed;
		uint32_t logfileMaxSize;			// 5 Meg Default
		int flushCounter;
		int flushMax;
		
//functions
public:
	SDAppender();
	SDAppender(int MOSIPin, int MISOPin, int CLKPin, int CSPin, int ssPin);
	void Log(Severity sev, String msg);		
	void Log(String msg);
	void SetSpeed(uint8_t value);
	void SetMaxSize(uint32_t value);
	~SDAppender();
protected:
private:
	void init();
	static String CreateMsg(Severity sev, String Message);
	void rotateLogs();
	
}; //SD

#endif //__SD_H__
