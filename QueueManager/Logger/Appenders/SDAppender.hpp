/* 
* SDAppender.hpp
*
* Created: 1/28/2015 11:43:26 AM
* Author: rohmer
*/


#ifndef __SDAppender_H__
#define __SDAppender_H__

#include "WString.h"
#include "Appender.hpp"
#include "../Common.hpp"
#include "../Time/Time.h"
#include "SD/SD.h"

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
		int csPin;
		int chipSelect;
		int ssPin;
		bool initialized;		
		File logfile;
		uint8_t spiSpeed;
		uint32_t logfileMaxSize;			// 5 Meg Default
		int flushCounter;
		int flushMax;
		
//functions
public:
	SDAppender();
	SDAppender(int CSPin, int ChipSelect);
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
