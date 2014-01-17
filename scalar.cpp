#pragma once

#include "_gbmath.h"

#include <stdlib.h>
#include <time.h>

 
namespace gbmath
{
 

float random()
{
	static bool sbFirstCall = true;
	static int stime;

	if(sbFirstCall)
	{
		sbFirstCall = false;
		stime=  (int)(time(NULL)/2);
		srand(stime);
	}


	return  (float) ::rand() /  (float)RAND_MAX   ;
}


 
 
 
}
