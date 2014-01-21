 

#include "_gbmath.h"
 

#ifdef _MSC_VER
	#pragma  warning(push)
	#pragma  warning(disable : 4244)
#endif



namespace  gbmath
{


void color4f::operator =  (const color4_32 val)
{
	a =  (float)  (val >> 24)         / 255.0f;
	r =  (float)( (val << 8 ) >> 24 ) / 255.0f;
	g =  (float)( (val << 16) >> 24 ) / 255.0f;
	b =  (float)( (val << 24) >> 24 ) / 255.0f;
}




inline color4f::operator  color4_32() const
{
	color4_32 res ;
	res.r = (byte_t) r * 255.0f;
	res.g = (byte_t) g * 255.0f;
	res.b = (byte_t) b * 255.0f;
	res.a = (byte_t) a * 255.0f;
	return res;
}



}


#ifdef _MSC_VER
	#pragma  warning(pop)
#endif
