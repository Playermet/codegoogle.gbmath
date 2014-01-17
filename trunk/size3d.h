/**  \file
 \brief 3-dimensional size.

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{

	//! \brief 3-dimensional size.
	struct size3d 
	{

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

		inline operator  vec3() const 
		{ 
			return  vec3(x,y,z); 
		}

		friend std::ostream& operator << (std::ostream& os, const size3d& a)
		{
			os << a.x << " " << a.y << " " << a.z;
			return os;
		}


	};
 
}
