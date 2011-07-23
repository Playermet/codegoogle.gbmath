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
		/** \brief 3-х мерный размер */
		struct Size3d {

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

			union 
			{
				float z;
				float depth;
			};

			inline operator  vec3() const { return  vec3(x,y,z); }


		};	
	}
}
