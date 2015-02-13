#include <Servo.h>
#include "ServoTask.h"
#include <stlport.h>
#include <stdlib.h>
#include <SPI.h>
#include <Logger.h>
#include "LEDTask.h"
#include "BaseTask.h"
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>
#include "OccupancyLibrary.h"
#include "OccupancyBlock.h"

OccupancyLibrary oLib=OccupancyLibrary(40,41,42,true,false,INFO);

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>Setups this object.</summary>
/// Example setup
/// 4 blocks    >1>2>3>4>1...  
/// 1 has Servo + LED Task, 2-4 have LED Tasks   
/// All have one detector for activation, and the next groups for deactivation;
/// <remarks>Rohmer, 2/13/2015.</remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void setup()
{
	
	std::vector<DetectorPins> blockOneDetector;
	blockOneDetector.push_back(oLib.CreateDetector(3,4));
	std::vector<DetectorPins> blockTwoDetector;
	blockTwoDetector.push_back(oLib.CreateDetector(5,6));
	std::vector<DetectorPins> blockThreeDetector;
	blockThreeDetector.push_back(oLib.CreateDetector(7,8));
	std::vector<DetectorPins> blockFourDetector;
	blockFourDetector.push_back(oLib.CreateDetector(9,10));
	
	int blockOne	=oLib.CreateBlock(blockOneDetector,blockTwoDetector);			// Block one, closed by Block two
	int blockTwo	=oLib.CreateBlock(blockTwoDetector,blockThreeDetector);			// Block two, closed by Block three
	int blockThree	=oLib.CreateBlock(blockThreeDetector,blockFourDetector);		// Block three, closed by Block four
	int blockFour	=oLib.CreateBlock(blockFourDetector,blockOneDetector);			// Block four, closed by Block one (Circular)
	
	// Blocks created, now add tasks
	
	oLib.CreateLEDTask(blockOne,2,4,3,1,0,1,1,true);
	
}

void loop()
{

  /* add main program code here */

}
