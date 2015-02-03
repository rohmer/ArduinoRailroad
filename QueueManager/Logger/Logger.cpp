/* 
* Logger.cpp
*
* Created: 1/28/2015 12:13:49 PM
* Author: rohmer
*/


#include "Logger.h"

// default constructor
Logger::Logger()
{
	logFile=true;
	logSerial=true;
	appenderCount=0;
	minSevToLog=WARNING;
	logAppenders=new Appender*[2];
} //Logger

Logger::Logger(bool LogSerial, bool LogFile, Severity sev)
{
	logFile=LogFile;
	logSerial=LogSerial;
	minSevToLog=sev;	
	appenderCount=0;	
	int a=0;
	if(LogSerial)
		a++;
	if(LogFile)
		a++;
	logAppenders=new Appender*[2];
}

void Logger::Init()
{
	if(logFile)
	{
		logAppenders[appenderCount]=new SDAppender();
		appenderCount++;
	}
	if(logSerial)
	{
		logAppenders[appenderCount]=new SerialAppender();
		appenderCount++;
	}
}

void Logger::Log(String msg)
{
	Log(INFO,msg);	
}

void Logger::Log(Severity sev, String msg)
{
	// We aren't logging this level
	if(sev>minSevToLog)	
		return;
	
	// Call the appenders
	for(int a=0; a<=appenderCount; a++)
	{
		logAppenders[a]->Log(sev,msg);
	}
}

// default destructor
Logger::~Logger()
{
	delete[] logAppenders;
} //~Logger
