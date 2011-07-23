/**  \file
 \brief яяяяяяяяяяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	
	
	

//! \brief  Нормаль, направление в двухмерном измерении /xx
class Normal2 {
private:
   float _x;
   float _y;
   
  inline void __normalize() 
  { 
	  float fm = sqrt(_x*_x+_y*_y); 
	  _x/=fm; 
	  _y/=fm;  
  }

public:
	// по дефолту нормаль смотрит по Y 
	Normal2() { _x=0.0f; _y=1.0f;  }
	Normal2(const Normal2& n) {  _x=n._x;   _y=n._y; }
	
	//! \brief Передавать правильные значения для нормали. Нельзя оба в ноль и т.д.
	Normal2(float x, float y)  
	{ 
		if( (0.0f==_x) && (0.0f==_y) )  throw std::runtime_error("invalid arg");
		_x=x; _y=y; __normalize(); 
	}

	Normal2(const  vec2& vn) { *this = vn; }
 

	inline float x() const { return _x; }
	inline float y() const { return _y; }


	inline void operator = ( vec2& v) {_x=v.x; _y=v.y; __normalize(); }
	inline void inverse() {_x=-_x; _y=-_y; }
	
	// setDirBetweenPoints(const Point2& src, const Point2& dest)
    // void transform(const  mat44_s& m) {....}
	// Normal2 cross(){...}
	// inline float angle(const Normal& n) const {...}
	
	// rotate (const mat22_s& m) {...}
	
	
	
	
}; 


	
	
	
	
	
	
	
	}
}
