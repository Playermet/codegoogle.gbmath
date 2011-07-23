
#include "fmath.h"


namespace gb
{

namespace fmath
{


//=========================================================================
//  AABB
//=========================================================================

//=========================================================================
bool AABB::checkIntersectPlane(const plane_s& pl) const
{


   vec3 normal = pl.normal();
  float d = pl.d;

   vec3 vmax, vmin;
 
     bool result= false;

     for (unsigned int i= 0; i<3; i++)
	 {
          if (normal[i] > 0.0f) 
		  {
               vmin[i] =  min[i];
               vmax[i] =  max[i];
          } 
		  else 
		  {
               vmin[i] =  max[i];
               vmax[i] =  min[i];
		  };
     }

     if ( normal.dot(vmin) + d >  0.0f)   return result;
     if ( normal.dot(vmax) + d >= 0.0f)   result = true;
	 
	 return result;
}


}
}
