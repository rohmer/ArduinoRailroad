/* 
* Appender.h
*
* Created: 1/28/2015 12:13:30 PM
* Author: rohmer
*/


#ifndef __APPENDER_H__
#define __APPENDER_H__

#include "WString.h"
#include "..\Common.h"

class Appender
{
//functions
public:
	virtual ~Appender();
	virtual void Log(Severity severity, String message);
	virtual void Log(String message);
}; //Appender

#endif //__APPENDER_H__
