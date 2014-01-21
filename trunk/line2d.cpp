 

#include "_gbmath.h"
 
 
 
namespace gbmath
{



	vec2 line2d::project_point( const vec2& pnt )
	{

		//const Vector2&  p ta,
		//const Vector2&  p tb,
		//const Vector2&  pt _from,
		//Vector2&  pt_to



		float b1 = pnt.x * ( src.x -  dest.x) + pnt.y * ( src.y -  dest.y);
		float b2 =  src.x *  dest.y -  src.y *  dest.x;

		vec2 pt_to;

		pt_to.y = ( src.x -  dest.x) * ( src.x -  dest.x) + ( src.y -  dest.y) * ( src.y -  dest.y);
		float det_k = b1 * ( src.x -  dest.x) - b2 * ( src.y -  dest.y);

		pt_to.x = det_k/pt_to.y;
		det_k = ( src.x -  dest.x) * b2 + ( src.y -  dest.y) * b1;
		pt_to.y = det_k/pt_to.y;
 
		return pt_to;
	}



/*	bool line2d::IsCollisionCircle( vec2& _pContact1, vec2& _pContact2 ,  const Circle& cir  )
	{

		vec2 p1(src.x , src.y );
		vec2 p2( dest.x ,  dest.y );

		const vec2 Dir = ( dest  - src  ) ;
		const vec2 VecConst = vec2 ( src.x - cir.center.x , src.y - cir.center.y  ) ;
		const float A = Dir.length_sq();
		const float B = 2.0f * ( VecConst.x * Dir.x + VecConst.y * Dir.y ) ;
		const float C = VecConst.length_sq ( ) - pow ( cir.radius , 2.0f ) ;
		const float D = pow ( B , 2.0f ) - 4.0f * A * C ;

		if ( D < 0.0f )
		{
			return false;
		}

		const float T0 = ( - B + sqrt ( D ) ) / ( 2.0f * A ) ;
		const float T1 = ( - B - sqrt ( D ) ) / ( 2.0f * A ) ;

		vec2 _p1, _p2;	

		if ( T0 > T1 )
		{
			_p1 = p1 + Dir * T0 ;
			_p2 = p1 + Dir * T1 ;
		}
		else
		{
			_p1 = p1 + Dir * T1 ;
			_p2 = p1 + Dir * T0 ;
		}

		_pContact1 = _p1;
		_pContact2 = _p2;

		return true;
	}

	*/


	bool  line2d::IsIntersectCircle(float* ps0, float* ps1,   const Circle& cir )
	{


		vec2 v = src  - cir.center;
		float b = 2.0f * src.direction_to( dest).dot( v );
		float c = v.dot(v) - cir.radius * cir.radius;
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

	bool  line2d::IsIntersectCircleContactPoints(vec2& pContact1, vec2& pContact2, const Circle& cir )
	{
		pContact1 = vec2();
		pContact2 = vec2();

		float s0, s1;

		bool res = IsIntersectCircle(&s0, &s1,   cir);

		if( res )
		{
			pContact1 =  src;
			pContact1.move( direction(), s0 );

			pContact2 =  src;
			pContact2.move( direction(), s1 );
		}


		return res;
	}



  

}

