// Logger.h

#ifndef _LOGGER_h
#define _LOGGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "SoftwareSerial.h"
#include <string>
#include "Time.h"
#include "SD.h"
#include "SPI.h"

enum SEVERITY { INFO, WARN, ERROR };

class LoggerClass
{
 private:
	 void initSerial();
	 String setMessage(SEVERITY sev, String msg);
	 void initSD();

	 uint8_t mosiPinSD, misoPinSD, clkPinSD, csPinSD;

	 bool logSD, logSerial, serialInit, sdInit;
	 uint8_t serialTX, serialRX;
	 long serialSpeed;	
	 SEVERITY minSev;
	 static SoftwareSerial serial;
	 File logFile;

 protected:

 public:
	 LoggerClass(SEVERITY minimumSevToLog, bool logToSerial, bool logToSD);
	 void SetSerial(uint8_t serialTXPin, uint8_t serialRXpin, long serialPortSpeed);
	 void SetSD(uint8_t mosiPin, uint8_t misoPin, uint8_t clkPin, uint8_t csPin);
	 void Log(SEVERITY severity, String msg);
	 void Log(String msg);
	 ~LoggerClass();
};

extern LoggerClass Logger(SEVERITY minimumSevToLog, bool logToSerial, bool logToSD);

#endif

