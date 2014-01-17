#pragma once

#include "_gbmath.h"

 
namespace gbmath
{

normal2& normal2::rotate (const mat22& m) 
{
	vec2 tmp(_x,_y);
	tmp = m * tmp;
	_x=tmp.x; 
	_y=tmp.y;
	return *this;
}

float normal2::angle( const normal2& n ) const
{
	float fdot = vec2(_x,_y).dot( vec2(n._x , n._y) );
	float res = acos(fdot);
	return res;
}

normal2& normal2::direction_between( const point2& src , const point2& dst )
{
	//vec2 vsrc(src._x , src._y);
	//vec2 vdst(dst._x , dst._y);
	_x = dst.x() - src.x();
	_y = dst.y() - src.y();
	return __normalize();
}


}
 