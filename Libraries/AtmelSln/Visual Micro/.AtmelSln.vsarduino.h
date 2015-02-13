/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Mega w/ ATmega2560 (Mega 2560), Platform=avr, Package=arduino
*/

#define __AVR_ATmega2560__
#define _VMDEBUG 1
#define ARDUINO 160
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

//
//

#include "c:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\mega\pins_arduino.h" 
#include "c:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino\arduino.h"
#include <OccupancyDetection.ino>
#include <BaseTask.cpp>
#include <BaseTask.h>
#include <Common.h>
#include <DetectorCollection.cpp>
#include <DetectorCollection.h>
#include <LEDTask.cpp>
#include <LEDTask.h>
#include <LedControl.cpp>
#include <LedControl.h>
#include <OccupancyBlock.cpp>
#include <OccupancyBlock.h>
#include <OccupancyLibrary.cpp>
#include <OccupancyLibrary.h>
#include <ServoTask.cpp>
#include <ServoTask.h>
