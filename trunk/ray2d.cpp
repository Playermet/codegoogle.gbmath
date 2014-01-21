 

#include "_gbmath.h"

 
namespace gbmath
{




	int __IsPointInBoundingBox(float x1, float y1, float x2, float y2, float px, float py)
	{
		float left, top, right, bottom; // Bounding Box For Line Segment

		// For Bounding Box
		if(x1 < x2)
		{
			left = x1;
			right = x2;
		}
		else
		{
			left = x2;
			right = x1;
		}

		if(y1 < y2)
		{
			top = y1;
			bottom = y2;
		}
		else
		{
			top = y2;
			bottom = y1;
		}

		if( (px+0.01) >= left && (px-0.01) <= right && 
			(py+0.01) >= top && (py-0.01) <= bottom )
		{
			return 1;
		}
		else
			return 0;

	}



	int __LineSegmentIntersection(float l1x1, float l1y1, float l1x2, float l1y2,
		float l2x1, float l2y1, float l2x2, float l2y2,
		float *m1, float *c1, float *m2, float *c2,
		float* intersection_X, float* intersection_Y)
	{

		float dx, dy;

		dx = l1x2 - l1x1;
		dy = l1y2 - l1y1;

		*m1 = dy / dx;

		// y = mx + c
		// intercept c = y - mx
		*c1 = l1y1 - *m1 * l1x1; // which is same as y2 - slope * x2

		dx = l2x2 - l2x1;
		dy = l2y2 - l2y1;

		*m2 = dy / dx;
		// y = mx + c
		// intercept c = y - mx
		*c2 = l2y1 - *m2 * l2x1; // which is same as y2 - slope * x2

		if( (*m1 - *m2) == 0)
			return 0;
		else
		{
			*intersection_X = (*c2 - *c1) / (*m1 - *m2);
			*intersection_Y = *m1 * *intersection_X + *c1;
		}

		if(__IsPointInBoundingBox(l1x1, l1y1, l1x2, l1y2, *intersection_X, *intersection_Y) == 1 && __IsPointInBoundingBox(l2x1, l2y1, l2x2, l2y2, *intersection_X, *intersection_Y) == 1)
		{
			return 1;
		}
		else
			return 0;
	}




bool ray2d::IsIntersect(vec2& pointIntersection , const ray2d& ry )
{
	vec2 s1 = orig;
	s1.move( dir, FLT_MAX  );

	vec2 s2 = ry.orig;
	s2.move( ry.dir , FLT_MAX );

	float m1, c1, m2, c2;
	float intersection_X, intersection_Y;

	int res = __LineSegmentIntersection( 
		orig.x , orig.y , s1.x , s1.y, //s1.p1.x , s1.p1.y , s1.p2.x , s1.p2.y , 
		orig.x , orig.y , s2.x , s2.y, //s2.p1.x , s2.p1.y , s2.p2.x , s2.p2.y ,
		&m1, &c1, &m2, &c2,
		&intersection_X, &intersection_Y
		);

	pointIntersection.x = intersection_X;
	pointIntersection.y = intersection_Y;

	return res != 0;
}




bool ray2d::IsIntersectCircle(float* ps0, float* ps1, const Circle& cir )
{
	vec2 v = orig - cir.center;
	float b = 2.0f * dir.dot( v );
	float c = v.dot(v) - cir.radius*cir.radius;
	float discriminant = (b * b) - (4.0f * c);
	if(discriminant < 0.0f)
	{
		return false;
	}

	discriminant = sqrtf(discriminant);

	float s0 = (-b + discriminant) / 2.0f;
	float s1 = (-b - discriminant) / 2.0f;

	if(ps0) *ps0 = s0;
	if(ps1) *ps1 = s1;

	if(s0 >= 0.0f || s1 >= 0.0f)
	{
		return true;
	}

	return false;
}





bool ray2d::IsIntersectCirclePoints(vec2& point0, vec2& point1,  const Circle& cir )
{

	point0 = vec2();
	point1 = vec2();

	float f0 = 0.0f;
	float f1 = 0.0f;

	bool res = IsIntersectCircle(&f0, &f1, cir);
	if(!res)
	{
		return res;
	}

	point0 = orig.moved( dir, f0 );
	point1 = orig.moved( dir, f1 );

	return res;
}




}
 