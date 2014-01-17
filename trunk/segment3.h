/**  \file
 \brief  segment (2 point)  in 3-dimensional space 
 
 
*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{

	class segment3
	{
	public:
	
		vec3 a1, a2;
		
		segment3() {}
		segment3(const segment2& a) { *this = a; }
		segment3(const vec3& _a1 , const vec3& _a2) : a1(_a1) , a2(_a2) {}
	
	
	
	
	};
  

}

