/**  \file
 \brief яяяяяяяяя

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
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