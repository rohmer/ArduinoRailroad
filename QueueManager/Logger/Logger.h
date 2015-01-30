/* 
* Logger.h
*
* Created: 1/28/2015 12:13:49 PM
* Author: rohmer
*/


#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "Common.h"
#include "vector"
#include "Appenders\SDAppender.h"
#include "Appenders\SerialAppender.h"

class Logger
{
//variables
public:
protected:
private:
	bool logSerial;
	bool logFile;
	Severity minSevToLog;
	Appender** logAppenders;
	int appenderCount;
		
//functions
public:
	Logger();
	Logger(bool LogSerial, bool LogFile, Severity sev);
	void Log(String msg);
	void Log(Severity sev, String msg);
	~Logger();
protected:
private:
	void Init();

}; //Logger

#endif //__LOGGER_H__
