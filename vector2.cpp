
#include "fmath.h"

namespace gb
{

namespace fmath
{


// =============================================================

// float vec2::ccw(const vec2& v) const 
// {
   // vec3 vv1;
   // vv1.x =  x;
   // vv1.y =  y;
   // vv1.z = 0.0f;

   // vec3 vv2;
   // vv2.x = v.x;
   // vv2.y = v.y;
   // vv2.z = 0.0f;

  // vec3 vres = vv1.cross(vv2);
   // return vres.z;
// };

			template<typename T>
			T vector2<T>::ccw(const vector2<T>& v) const
			{
			//#error  vec2::ccw
				vector3<T> vv1;
				vv1.x =  x;
				vv1.y =  y;
				vv1.z = 0.0f;

				vector3<T> vv2;
				vv2.x = v.x;
				vv2.y = v.y;
				vv2.z = 0.0f;

				vector3<T> vres = vv1.cross(vv2);
				return vres.z;
			}


   //=================================================

 			float vec2::ccw(const vec2& v) const
			{
			//#error  vec2::ccw
				vec3 vv1;
				vv1.x =  x;
				vv1.y =  y;
				vv1.z = 0.0f;

				vec3 vv2;
				vv2.x = v.x;
				vv2.y = v.y;
				vv2.z = 0.0f;

				vec3 vres = vv1.cross(vv2);
				return vres.z;
			}





}

}
