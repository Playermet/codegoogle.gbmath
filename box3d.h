/**  \file
 \brief  (deprecated) class box3d 
*
*
*/


#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gbmath
{

	//! \brief  (deprecated) class box3d .
	struct box3d {


		float width,   height,  deph;



		box3d() 
		{
		   width = height = deph = 0.0f;
		}
 

	};

}
