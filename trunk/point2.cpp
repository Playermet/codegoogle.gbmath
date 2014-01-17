#include "_gbmath.h"
 
namespace gbmath
{
    

	point2& point2::moveAlongNormal(const normal2& normal, float distance) 
	{
		_x += normal.x() * distance;
		_y += normal.y() * distance;
		return *this;
	}

	normal2 point2::direction_to(const point2& _to) const 
	{
		normal2 res;
		res.direction_between(*this , _to);
		return res;
	}

	point2& point2::move_to(const point2& _to, float dist)
	{
		normal2 n;
		n.direction_between(*this , _to);
		_x += n.x() * dist;
		_y += n.y() * dist;

		return *this;
	}

	point2& point2::transform(const  mat22& m) 
	{
		vec2 temp = vec2(_x, _y);
		temp = m * temp;
		_x = temp.x;
		_y = temp.y;
		return *this;
	}



}
