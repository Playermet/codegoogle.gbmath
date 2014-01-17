/**  \file
 \brief The scope of the center point and radius. She Bounding sphere.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{



	//! \brief The scope of the center point and radius. She Bounding sphere.
	class sphere 
	{
	public:

	   vec3   center;  ///<  center of sphere.
	  float   radius;  ///<  radius of sphere.

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

	  inline bool empty() const 
	  {
		  return ( center.empty() ) && ( radius == 0.0f ); 
	  }


	  //! \brief Get the distance between the edges of the spheres.
				
	  inline float distanceBetweenSpheres(const sphere& s) const
	  {
		  const float dist = center.distance(s.center);
		  float res = dist - ( radius + s.radius );
		  return res;
	  }

	  //! \brief  Get a box built inside the sphere. TESTED!
	  aabb toAabbInside() const;

	  //! \brief  Get a box built on the edge of the area. TESTED
	  aabb toAabbOutside() const;


	  //! \brief  check sphere is contact . TESTED!
	  inline bool checkIntersectSphere(const sphere& s) const
	  {
		  const float dist = center.distance(s.center);
		  const float rsum = radius + s.radius;

		  if (dist > (rsum) )
			  return false;

		  return true;
	  }





	obj_contains_e BSphereContainsBSphere(const sphere& s) const ;




	};
 
 
}
