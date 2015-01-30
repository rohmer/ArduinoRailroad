/* 
* SerialAppender.cpp
*
* Created: 1/28/2015 6:18:12 PM
* Author: Ron
*/


#include "SerialAppender.h"

// default constructor
SerialAppender::SerialAppender()
{
	Serial.begin(57600);
	while(!Serial)
	{
		;		
	}	
} //SerialAppender

void SerialAppender::Log(Severity sev, String msg)
{
	if(!Serial)
	{
		Serial.begin(57600);
		while(!Serial)
		{
			;
		}				
	}
	String mesg=numberOfHours(now())+":"+numberOfMinutes(now());
	mesg=mesg+":"+numberOfSeconds(now())+" "+sev+" - "+msg;
	Serial.println(mesg);
	Serial.flush();
}

void SerialAppender::Log(String msg)
{
	Log(INFO,msg);
}

// default destructor
SerialAppender::~SerialAppender()
{
} //~SerialAppender
