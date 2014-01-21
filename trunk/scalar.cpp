 

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


float random(float min, float max)
{
	static bool sbFirstCall=true;
	static int stime;
	if(sbFirstCall)
	{
		sbFirstCall = false;
		stime = (int)(time(NULL)/2);
		srand(stime);
	}
	
	return min + (max - min) * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
}

 
 
 
}
