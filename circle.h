/**  \file
 \brief  яяяяяяяяя





*/


//!   \todo Написать для circle построение внутреннего и внешнего прямоуголника.


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{





		/** \brief Класс окружность в 2-х мерном пространстве   */
		class Circle {
		public:
			 vec2	center;
			float	radius;


			inline Circle() { center.setzero(); radius=0.0f; }
			inline Circle(const Circle& c) {center=c.center; radius=c.radius; };
			inline Circle(const  vec2 & _center, const float _radius) { center=_center; radius=_radius; }
			inline Circle(float _centerx, float _centery,  float _radius)    { center.x=_centerx; center.y=_centery;   radius=_radius; }

			inline void set(int iCenterX, int iCenterY, int iRadius) { center.x=(float)iCenterY; center.y=(float)iCenterY; radius=(float)iRadius;	}
			inline void set(const  vec2& vCenter, float fRadius)    { center=vCenter; radius=fRadius; }
			inline void set(float _centerx, float _centery,  float _radius)    { center.x=_centerx; center.y=_centery;   radius=_radius; }


			//! \brief Проверка пересечения окружностей overlap
			bool checkIntersect(const Circle& c)
			{
				float fDist;
				{  vec2 t(center - c.center); fDist = t.length();  }
				if (fDist >= (radius + c.radius))	return false;
				return true;
			}



			// bool checkIntersectContactPoints(vec2& outp1, vec2& outp2, const Circle& c) {...}
			// http://algolist.manual.ru/maths/geom/intersect/circlecircle2d.php


			/*
			bool checkIntersectCircleContactPnt(const Circle& c, vec3_s& pc1, vec3_s& pc2) const {...}
			*/

			//! \brief Проверка попадания точки   point
			inline bool checkContainPoint(const  vec2 point)
			{
				float fDist;
				{  vec2 t(center - point); fDist = t.length();  }
				if( fDist > radius )
					return false;
				return true;
			}

			// bool checkIntersectCircle(const Circle& c) const {...}
			// bool checkIntersectRect(const Rect& r) const {...}

			// 3d::Sphere toObjectSphere(VP& vp, )



			// fromCstr(const char* s) {..}
			// toCstr(char* buf) const	  {....}


		};


 
}