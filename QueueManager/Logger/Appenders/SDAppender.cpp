/* 
* SD.cpp
*
* Created: 1/28/2015 11:43:26 AM
* Author: rohmer
*/


#include "SDAppender.hpp"

// default constructor
SDAppender::SDAppender()
{	
	this->mosiPin=SOFT_SPI_MOSI_PIN;
	this->misoPin=SOFT_SPI_MISO_PIN;
	this->sckPin=SOFT_SPI_SCK_PIN;
	this->csPin=10;
	spiSpeed=SPI_FULL_SPEED;
} //SD

SDAppender::SDAppender(int MOSIPin, int MISOPin, int CLKPin, int CSPin, int SCKPin)
{
	this->mosiPin=MOSIPin;
	this->misoPin=MISOPin;
	this->clkPin=CLKPin;
	this->csPin=CSPin;	
	this->sckPin=SCKPin;	
	spiSpeed=SPI_FULL_SPEED;
}

void SDAppender::Log(String msg)
{
	Log(INFO,msg);		
}

void SDAppender::Log(Severity sev, String msg)
{
	if(!initialized)
		return;
		
	String message=CreateMsg(sev,msg);
	if(!logfile.isOpen())
	{
		if(!logfile.open("logfile.txt", O_RDWR | O_CREAT | O_AT_END))
		{
			sd.errorHalt("Opening 'logfile.txt' for write failed");
			return;
		}		
	}
				
	logfile.write(message.c_str());	
	flushCounter++;
	if(flushCounter>flushMax)
	{		
		flushCounter=0;
		logfile.flush();
		if(logfile.fileSize()>logfileMaxSize)	
		{
			rotateLogs();
		}
	}
}

void SDAppender::SetSpeed(uint8_t value)
{
	spiSpeed=value;	
}

void SDAppender::init()
{
	initialized=false;
	logfileMaxSize=5242880;
	flushCounter=0;
	flushMax=10;
	
	if(!sd.begin(this->csPin,spiSpeed)) 
	{
		sd.initErrorHalt();
		initialized=false;
		return;
	}		
	if(!logfile.open("logfile.txt", O_RDWR | O_CREAT | O_AT_END))
	{
		sd.errorHalt("Opening 'logfile.txt' for write failed");
		return;
	}
	
	initialized=true;
}

String SDAppender::CreateMsg(Severity sev, String Message)
{
	String msg=numberOfHours(now())+":"+numberOfMinutes(now());
	msg=msg+":"+numberOfSeconds(now())+" "+sev+" - "+Message;
	return msg;
}

void SDAppender::rotateLogs()
{
	logfile.close();
	if(sd.exists("logfile.old.txt"))
	{
		sd.remove("logfile.old.txt");
	}
	sd.rename("logfile.txt","logfile.old.txt");
	if(!logfile.open("logfile.txt", O_RDWR | O_CREAT | O_AT_END))
	{
		sd.errorHalt("Opening 'logfile.txt' for write failed");
		initialized=false;
		return;
	}	
}

void SDAppender::SetMaxSize(uint32_t value)
{
	logfileMaxSize=value;
}

// default destructor
SDAppender::~SDAppender()
{
	logfile.close();	
} //~SD
