
#include "_gbmath.h"
 
 
 
namespace gbmath
{
		


static int __dt1_IsPointInBoundingBox(float x1, float y1, float x2, float y2, float px, float py)
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



static int LineSegmentIntersection(float l1x1, float l1y1, float l1x2, float l1y2,
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

	if(__dt1_IsPointInBoundingBox(l1x1, l1y1, l1x2, l1y2, *intersection_X, *intersection_Y) == 1 && __dt1_IsPointInBoundingBox(l2x1, l2y1, l2x2, l2y2, *intersection_X, *intersection_Y) == 1)
	{
		return 1;
	}
	else
		return 0;
}


bool segment2::IsIntersection( const segment2& s2,  vec2& pIntersect )
{
 
	float m1, c1, m2, c2;
	float intersection_X, intersection_Y;

	int res = LineSegmentIntersection( p1.x , p1.y , p2.x , p2.y , 
		s2.p1.x , s2.p1.y , s2.p2.x , s2.p2.y ,
		&m1, &c1, &m2, &c2,
		&intersection_X, &intersection_Y
		);

	pIntersect.x = intersection_X;
	pIntersect.y = intersection_Y;

	return res != 0;
}






}

