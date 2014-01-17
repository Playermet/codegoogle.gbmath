#pragma once

#include "_gbmath.h"

 
namespace gbmath
{

	Rect Circle::to_rec_outside() const
	{
		return Rect ( 
			vec2( center - radius  )  , 
			vec2( center + radius  ) 
			);
	}

	Rect Circle::to_rec_inside() const
	{
		static const float SINPIF = sin(PI * 0.25f);
		float k = SINPIF * radius;
		return Rect ( 
			vec2( center - k  )  ,
			vec2( center + k  ) 
			);
	}
 
}


 