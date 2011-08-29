/**  \file
 \brief  standard float 4x4 matrix .


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

namespace gbmath
{

	struct clip_values {
	
		float znear;
		float zfar;
	
		clip_values()
		{
			znear = zfar = 0.0f;
		}
		
		clip_values(const clip_values& a)
		{
			znear = a.znear;
			zfar  = a.zfar;
		}
		
		clip_values(float _znear, float _zfar)
		{
			znear = _znear;
			zfar  = _zfar;
		}
	
	
	};


}
