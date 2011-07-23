/**  \file
 \brief ??????


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	

	//! \brief Сфера по центральной точке и радиусу. Она же Bounding sphere.
	class Sphere {
	public:

	   vec3  center;  ///<  центральная координата сферы.
	  float   radius;  ///<  радиус сферы.
	  
	  inline Sphere() 
	  {
		   center.setzero();
		   radius = 0.0f;
	  }

	  inline Sphere(const Sphere& s) 
	  {
		  center = s.center; 
		  radius = s.radius; 
	  }
	  inline Sphere(const  vec3& _center, const float _radius) 
	  {
		  center = _center; 
		  radius = _radius; 
	  }	  
	  
	
	  inline void set(const  vec3& _center, float _radius) 
	  {
		  center = _center; 
		  radius = _radius; 

	  }
	  inline void set( float centerX, float centerY, float centerZ, float fRadius) 
	  { 
		  center.x = centerX;  
		  center.y = centerY;  
		  center.z = centerZ;  
		  radius = fRadius; 	
	  }

 
	  //! \brief Получить расстояние между краями сфер. Вернёт отрицательное значение если сферы пересекаются.
	  inline float distanceBetweenSpheres(const Sphere& s) const 
	  {
		  const float dist = center.distance(s.center);
		  float res = dist - ( radius + s.radius );
		  return res;
	  }

	  //! \brief  Получить бокс построеный  внутри сферы.	ПРОВЕРЕНО
	  AABB toAabbInside() const;

	  //! \brief  Получить бокс построеный по краю сферы. ПРОВЕРЕНО
	  AABB toAabbOutside() const;		  
	

	  //! \brief Проверка пересечения сфер  . ПРОВЕРЕНО
	  inline bool checkIntersectSphere(const Sphere& s) const 
	  {
		  const float dist = center.distance(s.center);
		  const float rsum = radius + s.radius;

		  if (dist > (rsum) ) 
			  return false;

		  return true;
	  }


//bool checkIntersectRay(const Ray& ray) {....}	<- ненадо. Есть у луча
//bool checkIntersecеSphere(const Sphere& sph) {....}   есть
//bool checkIntersectAABB(const AABB& aabb) {....}
//bool checkIntersectPlane(const Plane& aabb) {....}


	ObjContainsE BSphereContainsBSphere(const Sphere& s) const
	{
	   const float d2 = (center - s.center).lengthSq(); 
	  
	  if (d2 < scalar::sqr( radius + s.radius))	   
	  {
			if ( d2 < scalar::sqr(radius-s.radius) )
			  return SC_CONTAINSFULLY;
			else
			  return SC_CONTAINSPARTIALLY;
	  } 
	  // else
	  //  return SC_NOOVERLAP;

	  return   SC_NOOVERLAP;
	};

	


	};
	// end class
	
		
	
	
	
	
	
	
	
	
	}
}
