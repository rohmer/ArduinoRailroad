/*
 * MyClass.h
 *
 * Created: 2/6/2015 10:40:04 AM
 * Author: rohmer
 */ 

#ifndef _MYCLASS_h
#define _MYCLASS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class MyClass
{
 private:


 public:
	void setup();
	void loop();
};

extern MyClass myClass;

#endif

