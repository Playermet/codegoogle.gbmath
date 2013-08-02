﻿/**  \file
 \brief infinite spotlight on the line (point base) and corner spotlight


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{

 

	//!  \brief   infinite spotlight on the line (point base) and corner spotlight
	class  projector {
	public:
		ray3d ray;   ///<  ray of proj
		float phi; ///< angle of proj

		projector() 
		{

		}

		projector(const projector& pr) 
		{
			ray = pr.ray; 
			phi = pr.phi;  
		}


	}; 
 
 
}
