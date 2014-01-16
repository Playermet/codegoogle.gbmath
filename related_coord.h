/**  \file
 \brief The relative screen coordinates.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gbmath
{


	//! \brief The relative screen coordinates.
	struct related_coord
	{

		  float x;
		  float y;


		/** \brief   Conversion of absolute screen coordinates, in
				relative screen coordinates,
				to fit the screen (vpWidth and vpHeight) TESTED!  OK! */
		inline void   fromScreenCoord( // ScreenCoord_To_RelatCoord(
											const  vec2& vScrCoord,
											const int vpWidth, const int vpHeight )
		{
			  x = - ( ((float)vpWidth /2.0f) - vScrCoord.x ) / ((float)vpWidth /2.0f);
			  y = - ( ((float)vpHeight/2.0f) - vScrCoord.y ) / ((float)vpHeight/2.0f);
		}


		/** \briefConversion of relative screen coordinates
			in absolute screen coordinates,
			to fit the screen (vpWidth and vpHeight) TESTED!  OK! */
		inline  vec2  toScreenCoord(const int vpWidth, const int vpHeight ) const
		{
				vec2 res;
			   res.x =  ((float)vpWidth /2.0f) +   x * ((float)vpWidth /2.0f);
			   res.y =  ((float)vpHeight/2.0f) +   y * ((float)vpHeight/2.0f);
			   return res;
		}

	};

}

