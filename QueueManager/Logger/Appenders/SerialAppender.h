/* 
* SerialAppender.h
*
* Created: 1/28/2015 6:18:12 PM
* Author: Ron
*/


#ifndef __SERIALAPPENDER_H__
#define __SERIALAPPENDER_H__

#include "Common.h"
#include "Time/Time.h"
#include "WString.h"
#include "Appender.h"

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class SerialAppender: public Appender
{
//variables
public:
protected:
private:	
	
//functions
public:
	SerialAppender();
	~SerialAppender();
	void Log(Severity sev, String msg);	
	void Log(String msg);
protected:
private:	
}; //SerialAppender

#endif //__SERIALAPPENDER_H__
