/**  \file
 \brief яяяяяяяяя

*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{
	namespace fmath
	{
	
        /** \brief 2-х мерный размер. */
		struct Size2d {

			union 
			{
				float x;
				float width;	
			};

			union 
			{
				float y;
				float height;
			};

			inline operator  vec2 () const {  vec2 r(x,y); return r;  };


		};
	}
}
