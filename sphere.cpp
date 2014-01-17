#pragma once

#include "_gbmath.h"

 
namespace gbmath
{


aabb sphere::toAabbInside() const
{
  aabb res;

   static const float k =  1.0f / sqrt(1.0f+1.0f+1.0f);

  res.min.x = center.x - radius * k;
  res.min.y = center.y - radius * k;
  res.min.z = center.z - radius * k;

  res.max.x = center.x + radius * k;
  res.max.y = center.y + radius * k;
  res.max.z = center.z + radius * k;

   return res;


}


aabb sphere::toAabbOutside() const
{
  aabb res;

  res.min.x = center.x - radius;
  res.min.y = center.y - radius;
  res.min.z = center.z - radius;

  res.max.x = center.x + radius;
  res.max.y = center.y + radius;
  res.max.z = center.z + radius;

  return res;

}


obj_contains_e sphere::BSphereContainsBSphere(const sphere& s) const
{
	   const float d2 = (center - s.center).length_sq();

	  if(  d2 <  sqr( radius + s.radius)  )
	  {
			if ( d2 <  sqr(radius-s.radius) )
				return SC_CONTAINSFULLY;

			else
				return SC_CONTAINSPARTIALLY;
	  }

	  // else
	  //  return SC_NOOVERLAP;

	  return   SC_NOOVERLAP;
}



}