﻿/**  \file
 \brief  яяяяяяяяя





*/


//!   \todo Написать для circle построение внутреннего и внешнего прямоуголника.


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{

 

		//! \brief circle in two-dimensional space 
		class Circle {
		public:

			 vec2	center;
			 float  radius;


			inline Circle() 
			{ 
				center.setzero(); 
				radius=0.0f; 
			}

			inline Circle(const Circle& c) 
			{
				center = c.center; 
				radius = c.radius; 
			}

			inline Circle(const  vec2 & _center, const float _radius) 
			{ 
				center = _center; 
				radius = _radius; 
			}

			inline Circle(float _centerx, float _centery,  float _radius)    
			{ 
				center.x = _centerx; 
				center.y = _centery;   
				radius = _radius; 
			}

			inline void set(int iCenterX, int iCenterY, int iRadius) 
			{ 
				center.x = (float)iCenterY; 
				center.y = (float)iCenterY; 
				radius = (float)iRadius;	
			}

			inline void set(const  vec2& vCenter, float fRadius)    
			{ 
				center = vCenter; 
				radius = fRadius; 
			}

			inline void set(float _centerx, float _centery,  float _radius)    
			{ 
				center.x = _centerx; 
				center.y = _centery;   
				radius = _radius; 
			}


			//! \brief Check touching circles
			bool checkIntersect(const Circle& c)
			{
				float fDist;
				{  vec2 t(center - c.center); fDist = t.length();  }
				if (fDist >= (radius + c.radius))	return false;
				return true;
			}



			// bool checkIntersectContactPoints(vec2& outp1, vec2& outp2, const Circle& c) {...}
			// http://algolist.manual.ru/maths/geom/intersect/circlecircle2d.php


			/****************
			bool checkIntersectCircleContactPnt(const Circle& c, vec3_s& pc1, vec3_s& pc2) const {...}


			**************/


			//! \brief Verification of the point
			inline bool checkContainPoint(const  vec2 point)
			{
				float fDist;
				{  
					vec2 t(center - point); 
					fDist = t.length();  
				}

				if( fDist > radius )
					return false;

				return true;
			}


			// TODO: bool checkIntersectCircle(const Circle& c) const {...}
			// TODO: bool checkIntersectRect(const Rect& r) const {...}

			// TODO:  3d::Sphere toObjectSphere(VP& vp, )



			// fromCstr(const char* s) {..}
			// toCstr(char* buf) const	  {....}



			//-----------------------------------

			void operator  = (const std::string& str) throw (std::runtime_error)
			{
				std::istringstream iss(str);
				iss >> center;
				iss >> radius;

				if( iss.fail() )
				{
					throw std::runtime_error("bad argument");
				}
			}

			operator std::string() const
			{
				std::ostringstream oss;
				oss << center;
				oss << "   ";
				oss << radius;
				return oss.str();
			}

			friend std::ostream& operator << (std::ostream& os, const Circle& a)
			{
				os << a.center;
				os << "   ";
				os << a.radius;
				return os;
			}


		};


 
}