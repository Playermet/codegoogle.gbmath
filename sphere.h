/**  \file
 \brief ??????


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{



	//! \brief Сфера по центральной точке и радиусу. Она же Bounding sphere.
	class sphere {
	public:

	   vec3  center;  ///<  центральная координата сферы.
	  float   radius;  ///<  радиус сферы.

	  inline sphere()
	  {
		   center.setzero();
		   radius = 0.0f;
	  }

	  inline sphere(const sphere& s)
	  {
		  center = s.center;
		  radius = s.radius;
	  }
	  inline sphere(const  vec3& _center, const float _radius)
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
	  inline float distanceBetweenSpheres(const sphere& s) const
	  {
		  const float dist = center.distance(s.center);
		  float res = dist - ( radius + s.radius );
		  return res;
	  }

	  //! \brief  Получить бокс построеный  внутри сферы.	ПРОВЕРЕНО
	  aabb toAabbInside() const;

	  //! \brief  Получить бокс построеный по краю сферы. ПРОВЕРЕНО
	  aabb toAabbOutside() const;


	  //! \brief Проверка пересечения сфер  . ПРОВЕРЕНО
	  inline bool checkIntersectSphere(const sphere& s) const
	  {
		  const float dist = center.distance(s.center);
		  const float rsum = radius + s.radius;

		  if (dist > (rsum) )
			  return false;

		  return true;
	  }


//bool checkIntersectRay(const Ray& ray) {....}	<- ненадо. Есть у луча
//bool checkIntersecеSphere(const sphere& sph) {....}   есть
//bool checkIntersectAABB(const aabb& aabb) {....}
//bool checkIntersectPlane(const Plane& aabb) {....}


	obj_contains_e BSphereContainsBSphere(const sphere& s) const
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