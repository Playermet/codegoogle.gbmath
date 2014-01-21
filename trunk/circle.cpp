 

#include "_gbmath.h"

 
namespace gbmath
{


bool Circle::checkContainPoint(const  vec2 point)
{
	float fDist;
	{  
		vec2 t(center - point); 
		fDist = t.length();  
	}

	if( fDist > radius )
		return false;

	return true;
}



Rect Circle::to_rec_outside() const
{
	return Rect ( 
		vec2( center - radius  )  , 
		vec2( center + radius  ) 
		);
}

Rect Circle::to_rec_inside() const
{
	static const float SINPIF = sin(PI * 0.25f);
	float k = SINPIF * radius;
	return Rect ( 
		vec2( center - k  )  ,
		vec2( center + k  ) 
		);
}



bool Circle::IsContactCircles( const Circle& c2, bool& containFully )
{
	containFully = false;

	const float dr = center.distance(c2.center);

	if( dr <radius + c2.radius )
	{
		// true	contact

		if( radius <= c2.radius )
		{
			// c1 < c2
			if( dr < (c2.radius + radius - radius*2.0f ) )
			{
				containFully = true;
			}

		}
		else
		{
			// c2 < c1
			if( dr < (radius + c2.radius - c2.radius * 2.0f ) )
			{
				containFully = true;
			}

		}

		if(containFully)
		{
			return true;
		}


		return true;
	}


	return false;
}


bool Circle::IsContactCirclesWithContactPoints(  const Circle& c2, bool& containFully, vec2& pContact1, vec2& pContact2 )
{


	containFully = false;
	pContact1 = vec2();
	pContact2 = vec2();
	float dist =  center.distance(c2.center);


	if(  radius <= c2.radius )
	{
		// c1 < c2
		if( dist < (c2.radius + radius - radius * 2.0f ) )
		{
			containFully = true;
		}

	}
	else
	{
		// c2 < c1
		if( dist < (radius + c2.radius - c2.radius*2.0f ) )
		{
			containFully = true;
		}

	}


	if(containFully)
	{
		return  true;
	}



	const float X1 = center.x;
	const float Y1 = center.y;
	const float R1 = radius;


	const float X2 = c2.center.x;
	const float Y2 = c2.center.y;
	const float R2 = c2.radius;



	float vx=X2-X1;
	float vy=Y2-Y1;
	float vv=vx*vx+vy*vy;

	if( (R1+R2)*(R1+R2)<vv )
	{
		return false;
	}

	float a=(R1+R2)*(R1-R2)/2/vv+0.5f;
	float b=sqrt(R1*R1/vv-a*a);
	pContact1.x=X1+a*vx-b*vy;
	pContact1.y=Y1+a*vy+b*vx;
	pContact2.x=X1+a*vx+b*vy;
	pContact2.y=Y1+a*vy-b*vx;

	return true;
}





}


 