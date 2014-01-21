 

#include "_gbmath.h"

 

namespace gbmath
{


normal3& normal3::setDirectionBetweenPoints(const point3& pntSrc, const point3& pntDest)
{
	vec3 v;
	v.x=  pntDest._x - pntSrc._x; 
	v.y=  pntDest._y - pntSrc._y;
	v.z=  pntDest._z - pntSrc._z;
	*this = v;
	return *this;
}


 
}