
#include "fmath.h"


namespace gb
{

namespace fmath
{




//=========================================================================
//  Sphere
//=========================================================================

//=========================================================================
AABB Sphere::toAabbInside() const
{
  AABB res;
 
   static const float k =  1.0f / sqrt(1.0f+1.0f+1.0f);

  res.min.x = center.x - radius * k;
  res.min.y = center.y - radius * k;
  res.min.z = center.z - radius * k;

  res.max.x = center.x + radius * k;
  res.max.y = center.y + radius * k;
  res.max.z = center.z + radius * k;

   return res;


}

//=========================================================================
AABB Sphere::toAabbOutside() const
{
    AABB res;
 
  res.min.x = center.x - radius;
  res.min.y = center.y - radius;  
  res.min.z = center.z - radius;  
  
  res.max.x = center.x + radius;
  res.max.y = center.y + radius;  
  res.max.z = center.z + radius;   
  
  return res;




}



}
}
