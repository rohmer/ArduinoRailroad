// 
// 
// 

#include "Logging.h"

LoggerClass::LoggerClass(SEVERITY minimumSevToLog, bool logToSerial, bool logToSD)
{
	minSev = minimumSevToLog;
	logSerial = logToSerial;
	logSD = logToSD;
	serialInit = false;
	sdInit = false;	
	serialRX = 10;
	serialTX = 11;
	serialSpeed = 19200;
	mosiPinSD = MOSI_PIN;
	misoPinSD = MISO_PIN;
	clkPinSD = SCK_PIN;
	csPinSD = SS_PIN;	
}

void LoggerClass::initSerial()
{
	SoftwareSerial serial(serialRX, serialTX);
	while (!Serial)
	{
		;
	}

	Serial.begin(serialSpeed);
}

void LoggerClass::SetSerial(uint8_t serialTXPin, uint8_t serialRXpin, long serialPortSpeed)
{
	serialRX = serialRXpin;
	serialTX = serialTXPin;
	serialSpeed = serialPortSpeed;
	initSerial();
}

String LoggerClass::setMessage(SEVERITY sev, String msg)
{
	String ret;
	ret.concat(hour());
	ret.concat(":");
	ret.concat(minute());
	ret.concat(":");
	ret.concat(second());
	ret.concat(" - ");
	ret.concat(sev);
	ret.concat(" - ");
	ret.concat(msg);
	return msg;
}

void LoggerClass::Log(SEVERITY sev, String msg)
{
	if (sev <= minSev)
		return;
	msg = setMessage(sev, msg);
	if (logSerial)
	{
		if (!serialInit)
		{
			initSerial();
			serial.println(msg);
		}
	}
	if (logSD)
	{
		File logFile = SD.open("log.txt", FILE_WRITE);
		if (logFile)
		{
			logFile.println(msg);			
			logFile.close();
		}
		
	}
}

void LoggerClass::Log(String msg)
{
	Log(INFO, msg);
}

void LoggerClass::SetSD(uint8_t mosiPin, uint8_t misoPin, uint8_t clkPin, uint8_t csPin)
{
	misoPinSD = misoPin;
	mosiPinSD = mosiPin;
	clkPinSD = clkPin;
	csPinSD = csPin;
	initSD();
}

void LoggerClass::initSD()
{
	pinMode(csPinSD, OUTPUT);
	if (!SD.begin(csPinSD))
		return;
}

LoggerClass::~LoggerClass()
{
}

LoggerClass Logger(SEVERITY minimumSevToLog, bool logToSerial, bool logToSD);

