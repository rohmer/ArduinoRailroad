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
	this->csPin=4;
	this->chipSelect=4;
	spiSpeed=SPI_FULL_SPEED;
} //SD

SDAppender::SDAppender(int CSPin, int ChipSelect)
{
	this->chipSelect=ChipSelect;
	this->csPin=CSPin;	
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
	if(!logfile.available())
	{
		logfile=SD.open("logfile.txt", O_READ | O_WRITE | O_CREAT);
		if(!logfile.available())
		{
			return;
		}		
	}
				
	char *buf=new char(message.length());
	message.toCharArray(buf,message.length(),0);
	logfile.println(buf);
	flushCounter++;
	if(flushCounter>flushMax)
	{		
		logfile.flush();
		flushCounter=0;
		if(logfile.size()>logfileMaxSize)
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

	pinMode(ssPin,OUTPUT);
	
	if(!SD.begin(this->csPin))
	{
		initialized=false;
		return;
	}		

	logfile=SD.open("logfile.txt", O_READ | O_WRITE | O_CREAT);
	if(!logfile)
	{
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

// This could be time consuming, may want to not do it.
void SDAppender::rotateLogs()
{
	logfile.close();
	if(SD.exists("logfile.old.txt"))
	{
		SD.remove("logfile.old.txt");
		File oldFile=SD.open("logfile.txt",FILE_READ);
		File newFile=SD.open("logfile.old.txt",FILE_WRITE);
		while(oldFile.available())
		{
			newFile.write(oldFile.read());
		}
		oldFile.close();
		newFile.close();
		SD.remove("logfile.txt");
	}

	logfile=SD.open("logfile.txt", O_READ | O_WRITE | O_CREAT);

	if(!logfile)
	{
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
