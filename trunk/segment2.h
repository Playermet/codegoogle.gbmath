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
	
		vec2 p1, p2;
		
		segment2() {}
		segment2(const segment2& a) { *this = a; }
		segment2(const vec2& _p1 , const vec2& _p2) : p1(_p1) , p2(_p2) {}
	
	
		bool IsIntersection( const segment2& s2,  vec2& pIntersect );
	
	
	};
  

}

