#pragma once

#include "_gbmath.h"
 

namespace gbmath
{


float vec2::ccw(const vec2& v) const
{

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
