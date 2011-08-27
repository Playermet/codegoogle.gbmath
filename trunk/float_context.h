/**  \file
 \brief float type  context .


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 

namespace gbmath
{


   //! \brief     float type  context .
   class float_context {
   public:

	 float time;
	 float timeElapsed;

	 float fps;

		struct mouseData_s
		{
			 int x, y;
			 bool bLeftButtonDown;
			 bool bRIghtButtonDown;
		};

	mouseData_s  mouseData;

	vieport_s  viewport;

	perspective_projection_data projData;

	float modelBoundingSphereRadius;

	float getValue_by_context_type(const float_context_type_e::e) const throw(std::runtime_error&);

   };

 
 
}
