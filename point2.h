/**  \file
 \brief  point in 2-dimensional space


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{



#pragma  message("! delete point2 ???  "  __FILE__ )


	/** \brief  describes a point/coordinate/position in 3-dimensional space.
				Level higher than the vector */
	class point2 {
	public:

	   float _x;
	   float _y;

	   point2() { _x=0.0f; _y=0.0f; }
	   point2(const point2& p) {_x=p._x ; _y=p._y ; }
	   point2(const float x, const float y) { _x=x;  _y=y; }

	   inline operator const float* () const { return &_x; }

	   inline void operator = (const  vec2& v) { _x=v.x; _y=v.y; }

	#ifdef _WINDOWS_
	   inline void operator = (const POINT& p) { _x=(float)p.x; _y=(float)p.y; }
	#endif

	   // void moveAlongNormal(const Normal2& normal, float distance) {....}
	   // void transform(const  mat22_s& m) {....}


	    //  Point3 from3dSpace(const VP& vp, const mat44_s& mwvp) {...}



	};


 
}