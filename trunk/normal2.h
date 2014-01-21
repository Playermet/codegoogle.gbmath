/**  \file
 \brief direction / normal in 2-dimensional space.
Higher level than a vector. Always normalized.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	//! \brief direction / normal in 2-dimensional space. Higher level than a vector. Always normalized.
	class normal2 
	{
	private:

	   float _x;
	   float _y;

	  inline normal2& __normalize()
	  {
		  float fm = sqrt(_x*_x+_y*_y);
		  _x /= fm;
		  _y /= fm;
		  return *this;
	  }

	public:
	
		//! \brief  by default normal [0 , 1]
		normal2() 
		{ 
			_x=0.0f; 
			_y=1.0f;  
		}
		
		normal2(const normal2& n) 
		{  
			_x=n._x;   
			_y=n._y; 
		}

		//! \brief Pass the correct values ​​for the normal. Can not be both a zero and so ...
		normal2(float x, float y)
		{
			if( (0.0f==_x) && (0.0f==_y) )  
				throw std::runtime_error("invalid arg");
				
			_x=x; 
			_y=y; 
			
			__normalize();
		}

		normal2(const  vec2& vn) 
		{ 
			*this = vn; 
		}


		inline float x() const { return _x; }
		inline float y() const { return _y; }


		inline void operator = ( vec2& v) 
		{
			_x = v.x; 
			_y = v.y; 
			__normalize(); 
		}
		
		inline void inverse() 
		{
			_x=-_x; 
			_y=-_y; 
		}
 
		normal2& rotate (const mat22& m);
		normal2& rotate90Degr( bool clockWise );

		float angle( const normal2& n ) const;

		normal2& direction_between( const point2& src , const point2& dest  );


		// setDirBetweenPoints(const Point2& src, const Point2& dest)
		// void transform(const  mat44_s& m) {....}
		// normal2 cross(){...}

		// 

		normal2& operator = (const vec2& a);
		operator vec2 () const;

	};
 
}
