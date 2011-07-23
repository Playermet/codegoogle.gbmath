
#include "fmath.h"

namespace gb
{

namespace fmath
{



//=========================================================================
//                          Normal3
//=========================================================================

//=========================================================================
	Normal3& Normal3::setDirectionBetweenPoints(const Point3& pntSrc, const Point3& pntDest) 
	{
		 vec3 v;
		v.x=  pntDest._x - pntSrc._x; // пусть пока так будет
		v.y=  pntDest._y - pntSrc._y;
		v.z=  pntDest._z - pntSrc._z;
		*this = v;
		return *this;
	}
 


}
}
