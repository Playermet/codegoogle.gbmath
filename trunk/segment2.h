/**  \file
 \brief  segment (2 point)  in 2-dimensional space 
 
 
*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{

	class segment2
	{
	public:
	
		vec2 a1, a2;
		
		segment2() {}
		segment2(const segment2& a) { *this = a; }
		segment2(const vec2& _a1 , const vec2& _a2) : a1(_a1) , a2(_a2) {}
	
	
	
	
	};
  

}

