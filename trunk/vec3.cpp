#pragma once

#include "_gbmath.h"

 
namespace gbmath
{



void  vec3::operator = (const point3& pnt)
{
	x=pnt._x;
	y=pnt._y;
	z=pnt._z;
}

 
vec3  vec3::project (
			const Rectangle& vp, 
			const  mat44& Proj,
			const  mat44& View,
			const  mat44& World ) const
{
			 vec4 a= vec4( x, y, z, 1.0f );
			 mat44 wvp = World * View * Proj ;

			 vec4 b  = wvp * a ;

			 vec3  c;
			c.x = b.x / b.w;
			c.y = b.y / b.w;
			c.z = b.z / b.w;

			 vec3  res;
			res.x = vp.x + vp.width  * (1.0f + c.x)  /  2.0f;
			res.y = vp.y + vp.height * (1.0f - c.y)  /  2.0f;
			res.z = 0.0f; //vp.minZ + c.z * (vp.maxZ-vp.minZ);
			return res;
}

 
vec3  vec3::unproject( const Rectangle& vp,
						   const  mat44& Proj,
				 		   const  mat44& View,
						   const  mat44& World) const


{
	mat44 MAT = World * View *  Proj;
	MAT.invert();

	vec4 a;
	a.x =        (x-vp.x) * 2.0f   /  ( vp.width-1.0f );
	a.y = 1.0f - (y-vp.y) * 2.0f   /    vp.height;
	a.z = 0.0f; //(z-vp.minZ)  /  (vp.maxZ - vp.minZ);
	a.w = 1.0f;

	vec4 b  =  MAT * a ;

	const float k = 1.0f/b.w;
	vec3  res = vec3(  b.x*k  , b.y*k , b.z*k  );
	return  res;
}

 
vec3&  vec3::transform_coord(const mat44& m)
{
	vec4 v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 1.0f;

	v = m * v;

	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

 
vec3&  vec3::transform_normal(const mat44& m)
{
	vec4 v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0.0f;

	v = m * v;

	x = v.x;
	y = v.y;
	z = v.z;

    return *this;
}



void vec3::TransformCoordArray   (vec3* points, const size_t num, const size_t stride, const mat44& m)
{
	for( size_t c=0; c<num; c++ )
	{
		unsigned char* temp = (unsigned char*)points;
		vec3* curr = (vec3*)( temp + stride );
		curr->transform_coord(m);
	}
}

void vec3::TransformNormalArray  (vec3* points, const size_t num, const size_t stride, const mat44& m)
{
	for( size_t c=0; c<num; c++ )
	{
		unsigned char* temp = (unsigned char*)points;
		vec3* curr = (vec3*)( temp + stride );
		curr->transform_normal(m);
	}
}



}