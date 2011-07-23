/**  \file
 \brief ?????? яяяяяяяяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	



//! \brief   Позиция, точка в двухмерном измерении  ВОЗМОЖНО УДАЛИТЬ
class Point2 {
public:
   float _x;
   float _y;
   
   Point2() { _x=0.0f; _y=0.0f; }
   Point2(const Point2& p) {_x=p._x ; _y=p._y ; }
   Point2(const float x, const float y) { _x=x;  _y=y; }
   
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
}
