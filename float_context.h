/**  \file 
 \brief яяяяяяяя
 
 
*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
 
  
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
}
