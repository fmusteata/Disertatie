#include "general_types.h"
 
#define OFFSET 0.0025

const float32 sigPoints[10] ={-5,	       -4, 	      -3,         -2, 	      -1,         1,          2, 	      3, 	      4, 	      5}; 
const float32 sigValue[10] =  {0.00669285, 0.0179862, 0.04742857, 0.11920292, 0.26894142, 0.73105857, 0.88079707, 0.95257412, 0.98201379, 0.99330714}; 


float32 sigmoid(float x)
{
    float32 return_value;
	uint8 index;
	float32 resolution;
	
	
	if(x >= sigPoints[9])
	{
		return 1;
	}
	else if(x <= sigPoints[0])
	{
		return 0;
	}
	
	/* Find the interval where the input value is */
	for(uint8 i = 0; i < 10; i++)
	{
		if((x > sigPoints[i]) && (x <= sigPoints[i+1]))
		{
			index = i;
		}
	}

	/********************* Compute the resolution *******************************/
	/*																			*/
	/*    				phys_max - phy_min	  ;	sigPoints => raw inerval		*/
	/*  resolution = -----------------------    								*/
	/*					 raw_max - raw_min	  ;	sigValue => phys interval		*/
	/*																			*/
	/****************************************************************************/
	resolution = (sigValue[index+1] - sigValue[index]) / (sigPoints[index+1] - sigPoints[index]);
	
	/********************* Compute the output ***********************************/
	/*																			*/
	/*  return_value = (input - raw_min) * resolution + phys_min				*/
	/*																			*/
	/****************************************************************************/
	return_value = (x - sigPoints[index]) * resolution + sigValue[index];

    return return_value;
}





























