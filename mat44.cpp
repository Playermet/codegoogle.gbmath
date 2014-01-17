#pragma once

#include "_gbmath.h"

 
namespace gbmath
{



mat44& mat44::setRotationQuaternion(const  Quaternion& q)
{

	mat44 t  (
		1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z,   2.0f*q.x*q.y - 2.0f*q.z*q.w,         2.0f*q.x*q.z + 2.0f*q.y*q.w,          0.0f,
		2.0f*q.x*q.y + 2.0f*q.z*q.w,          1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z,  2.0f*q.y*q.z - 2.0f*q.x*q.w,          0.0f,
		2.0f*q.x*q.z - 2.0f*q.y*q.w,          2.0f*q.y*q.z + 2.0f*q.x*q.w,         1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y,   0.0f,
		0.0f,                                 0.0f,                                0.0f,                                 1.0f);

	t.transpone();

	*this = t;

	return *this;
}


mat44& mat44::setTransformation(const vec3& vScale,
								const  Quaternion& qRotation,
								const vec3& vTranslation)
{
   mat44 ms;
   ms.setScaling( vScale );

   mat44 mr;
   mr.setRotationQuaternion(  qRotation );

   mat44 mt;
   mt.setTranslation(  vTranslation );

   *this = mt * mr * ms;

   return *this;
}


mat44& mat44::setWorldTransform(const TransformData& t)
{
	return setTransformation(t.vScaling, t.qRotation, t.vTranslation );
}


mat44& mat44::setReflection(const plane_s& plane )
{

	float a, b, c, d;

	const float k = sqrt( plane.a*plane.a + plane.b*plane.b + plane.c*plane.c );
	a = plane.a / k;
	b = plane.b / k;
	c = plane.c / k;
	d = plane.d / k;

	mat44 Out;

	Out._11=1.0f-2.0f* sqr(a);   Out._12=-2.0f*b*a;					 Out._13=-2.0f*c*a;				    Out._14=0.0f;

	Out._21=-2.0f*a*b;					  Out._22=1.0f-2.0f* sqr(b);  Out._23=-2.0f*c*b;					Out._24=0.0f;

	Out._31=-2.0f*a*c;				     Out._32=-2.0f*b*c;					 Out._33=1.0f-2.0f* sqr(c);  Out._34=0.0f;

	Out._41=-2.0f*a*d;					 Out._42=-2.0f*b*d;				     Out._43=-2.0f*c*d;				    Out._44=1.0f;

	*this = Out;

	return *this;
}


mat44&  mat44::setShadow(const vec4& Light, const plane_s& Plane )
{
	float a,b,c,d;
	const float k = sqrt(  sqr(Plane.a) +  sqr(Plane.b) +  sqr(Plane.c) );
	a = Plane.a / k;
	b = Plane.b / k;
	c = Plane.c / k;
	d = Plane.d / k;

	float x,y,z,w;
	x = Light.x;
	y = Light.y;
	z = Light.z;
	w = Light.w;

	float f = Light.x*Plane.x + Light.y*Plane.b + Light.z*Plane.c + Light.w*Plane.d;

	mat44 Out;

	Out._11=f-x*a;  Out._12=-y*a;    Out._13=-z*a;    Out._14=-w*a;

	Out._21=-x*b;   Out._22=f-y*b;   Out._23=-z*b;    Out._24=-w*b;

	Out._31=-x*c;   Out._32=-y*c;    Out._33=f-z*c;   Out._34=-w*c;

	Out._41=-x*d;   Out._42=-y*d;    Out._43=-z*d;    Out._44=f-w*d;

	 *this = Out;

     return *this;
}


bool mat44::empty() const
{
	static const mat44 _ZERO(0.0f);
	if( memcmp( &_ZERO._11 , &_11 , sizeof(mat44) ) == 0 )
		return true;

	return false;
}


mat44 mat44::operator * ( const mat44& m ) const
{
	mat44 r;

	r._11 = floats[0][0] * m.floats[0][0] + floats[0][1] * m.floats[1][0] + floats[0][2] * m.floats[2][0] + floats[0][3] * m.floats[3][0];
	r._12 = floats[0][0] * m.floats[0][1] + floats[0][1] * m.floats[1][1] + floats[0][2] * m.floats[2][1] + floats[0][3] * m.floats[3][1];
	r._13 = floats[0][0] * m.floats[0][2] + floats[0][1] * m.floats[1][2] + floats[0][2] * m.floats[2][2] + floats[0][3] * m.floats[3][2];
	r._14 = floats[0][0] * m.floats[0][3] + floats[0][1] * m.floats[1][3] + floats[0][2] * m.floats[2][3] + floats[0][3] * m.floats[3][3];

	r._21 = floats[1][0] * m.floats[0][0] + floats[1][1] * m.floats[1][0] + floats[1][2] * m.floats[2][0] + floats[1][3] * m.floats[3][0];
	r._22 = floats[1][0] * m.floats[0][1] + floats[1][1] * m.floats[1][1] + floats[1][2] * m.floats[2][1] + floats[1][3] * m.floats[3][1];
	r._23 = floats[1][0] * m.floats[0][2] + floats[1][1] * m.floats[1][2] + floats[1][2] * m.floats[2][2] + floats[1][3] * m.floats[3][2];
	r._24 = floats[1][0] * m.floats[0][3] + floats[1][1] * m.floats[1][3] + floats[1][2] * m.floats[2][3] + floats[1][3] * m.floats[3][3];

	r._31 = floats[2][0] * m.floats[0][0] + floats[2][1] * m.floats[1][0] + floats[2][2] * m.floats[2][0] + floats[2][3] * m.floats[3][0];
	r._32 = floats[2][0] * m.floats[0][1] + floats[2][1] * m.floats[1][1] + floats[2][2] * m.floats[2][1] + floats[2][3] * m.floats[3][1];
	r._33 = floats[2][0] * m.floats[0][2] + floats[2][1] * m.floats[1][2] + floats[2][2] * m.floats[2][2] + floats[2][3] * m.floats[3][2];
	r._34 = floats[2][0] * m.floats[0][3] + floats[2][1] * m.floats[1][3] + floats[2][2] * m.floats[2][3] + floats[2][3] * m.floats[3][3];

	r._41 = floats[3][0] * m.floats[0][0] + floats[3][1] * m.floats[1][0] + floats[3][2] * m.floats[2][0] + floats[3][3] * m.floats[3][0];
	r._42 = floats[3][0] * m.floats[0][1] + floats[3][1] * m.floats[1][1] + floats[3][2] * m.floats[2][1] + floats[3][3] * m.floats[3][1];
	r._43 = floats[3][0] * m.floats[0][2] + floats[3][1] * m.floats[1][2] + floats[3][2] * m.floats[2][2] + floats[3][3] * m.floats[3][2];
	r._44 = floats[3][0] * m.floats[0][3] + floats[3][1] * m.floats[1][3] + floats[3][2] * m.floats[2][3] + floats[3][3] * m.floats[3][3];

	return  r;
}


mat44& mat44::invert () throw()
{
	mat44* pthis = this;

#define SWAP_ROWS(a, b) {  float * _tmp = a; (a)=(b); (b)=_tmp; }
#define MAT(fl,r,c)     fl [r][c]
#define INV_ERR  // throw std::runtime_error("invert failed");

	float	wtmp [4][8];
	float	m0, m1, m2, m3, s;
	float	* r0, * r1, * r2, * r3;

	r0 = wtmp [0];
	r1 = wtmp [1];
	r2 = wtmp [2];
	r3 = wtmp [3];

	r0 [0] = MAT(floats,0,0);
	r0 [1] = MAT(floats,0,1);
	r0 [2] = MAT(floats,0,2);
	r0 [3] = MAT(floats,0,3);
	r0 [4] = 1;
	r0 [5] =
	r0 [6] =
	r0 [7] = 0;

	r1 [0] = MAT(floats,1,0);
	r1 [1] = MAT(floats,1,1);
	r1 [2] = MAT(floats,1,2);
	r1 [3] = MAT(floats,1,3);
	r1 [5] = 1;
	r1 [4] =
	r1 [6] =
	r1 [7] = 0,

	r2 [0] = MAT(floats,2,0);
	r2 [1] = MAT(floats,2,1);
	r2 [2] = MAT(floats,2,2);
	r2 [3] = MAT(floats,2,3);
	r2 [6] = 1;
	r2 [4] =
	r2 [5] =
	r2 [7] = 0;

	r3 [0] = MAT(floats,3,0);
	r3 [1] = MAT(floats,3,1);
	r3 [2] = MAT(floats,3,2);
	r3 [3] = MAT(floats,3,3);
	r3 [7] = 1;
	r3 [4] =
	r3 [5] =
	r3 [6] = 0;

											// choose pivot - or die
	if ( fabs (r3 [0] )> fabs ( r2 [0] ) )
		SWAP_ROWS ( r3, r2 );

	if ( fabs ( r2 [0] ) > fabs ( r1 [0] ) )
		SWAP_ROWS ( r2, r1 );

	if ( fabs ( r1 [0] ) > fabs ( r0 [0 ] ) )
		SWAP_ROWS ( r1, r0 );

	if ( r0 [0] == 0 )
	{
		  INV_ERR
		//return false;
	}

											// eliminate first variable
	m1 = r1[0]/r0[0];
	m2 = r2[0]/r0[0];
	m3 = r3[0]/r0[0];

	s = r0[1];
	r1[1] -= m1 * s;
	r2[1] -= m2 * s;
	r3[1] -= m3 * s;

	s = r0[2];
	r1[2] -= m1 * s;
	r2[2] -= m2 * s;
	r3[2] -= m3 * s;

	s = r0[3];
	r1[3] -= m1 * s;
	r2[3] -= m2 * s;
	r3[3] -= m3 * s;

	s = r0[4];

	if ( s != 0 )
	{
		r1[4] -= m1 * s; r2[4] -= m2 * s; r3[4] -= m3 * s;
	}

	s = r0[5];

	if ( s != 0.0 )
	{
		r1[5] -= m1 * s; r2[5] -= m2 * s; r3[5] -= m3 * s;
	}

	s = r0[6];

	if ( s != 0 )
	{
		r1[6] -= m1 * s; r2[6] -= m2 * s; r3[6] -= m3 * s;
	}

	s = r0[7];

	if ( s != 0 )
	{
		r1[7] -= m1 * s; r2[7] -= m2 * s; r3[7] -= m3 * s;
	}

											// choose pivot - or die
	if ( fabs (r3 [1] ) > fabs ( r2 [1] ) )
		SWAP_ROWS ( r3, r2 );

	if ( fabs ( r2 [1] ) > fabs ( r1 [1] ) )
		SWAP_ROWS ( r2, r1 );

	if ( r1 [1] == 0 )
	{
       INV_ERR
		//return false;
	}


											// eliminate second variable
	m2     = r2[1]/r1[1]; m3     = r3[1]/r1[1];
	r2[2] -= m2 * r1[2];  r3[2] -= m3 * r1[2];
	r2[3] -= m2 * r1[3];  r3[3] -= m3 * r1[3];

	s = r1[4];

	if ( 0 != s )
	{
		r2[4] -= m2 * s; r3[4] -= m3 * s;
	}

	s = r1[5];

	if ( 0 != s )
	{
		r2[5] -= m2 * s; r3[5] -= m3 * s;
	}

	s = r1[6];

	if ( 0 != s )
	{
		r2[6] -= m2 * s; r3[6] -= m3 * s;
	}

	s = r1[7];

	if ( 0 != s )
	{
		r2[7] -= m2 * s; r3[7] -= m3 * s;
	}

											// choose pivot - or die
	if ( fabs ( r3 [2] ) > fabs ( r2 [2] ) )
		SWAP_ROWS ( r3, r2 );

	if ( r2 [2] == 0)
	{
		INV_ERR
	    //return false;
	}

											// eliminate third variable
	m3     = r3[2]/r2[2];
	r3[3] -= m3 * r2[3], r3[4] -= m3 * r2[4],
	r3[5] -= m3 * r2[5], r3[6] -= m3 * r2[6],
	r3[7] -= m3 * r2[7];

											// last check
	if ( r3 [3] == 0 )
	{
		INV_ERR
		//return false;
	}


											// now back substitute row 3
	s      = 1/r3[3];
	r3[4] *= s; r3[5] *= s; r3[6] *= s; r3[7] *= s;

											// now back substitute row 2
	m2    = r2[3];
	s     = 1/r2[2];
	r2[4] = s * (r2[4] - r3[4] * m2), r2[5] = s * (r2[5] - r3[5] * m2),
	r2[6] = s * (r2[6] - r3[6] * m2), r2[7] = s * (r2[7] - r3[7] * m2);

	m1     = r1[3];
	r1[4] -= r3[4] * m1, r1[5] -= r3[5] * m1,
	r1[6] -= r3[6] * m1, r1[7] -= r3[7] * m1;

	m0     = r0[3];
	r0[4] -= r3[4] * m0, r0[5] -= r3[5] * m0,
	r0[6] -= r3[6] * m0, r0[7] -= r3[7] * m0;

											// now back substitute row 1
	m1    = r1[2];
	s     = 1/r1[1];
	r1[4] = s * (r1[4] - r2[4] * m1), r1[5] = s * (r1[5] - r2[5] * m1),
	r1[6] = s * (r1[6] - r2[6] * m1), r1[7] = s * (r1[7] - r2[7] * m1);

	m0     = r0[2];
	r0[4] -= r2[4] * m0, r0[5] -= r2[5] * m0,
	r0[6] -= r2[6] * m0, r0[7] -= r2[7] * m0;

											// now back substitute row 0
	m0    = r0[1];
	s     = 1/r0[0];

	r0[4] = s * (r0[4] - r1[4] * m0), r0[5] = s * (r0[5] - r1[5] * m0),
	r0[6] = s * (r0[6] - r1[6] * m0), r0[7] = s * (r0[7] - r1[7] * m0);

	MAT(floats,0,0) = r0[4];   MAT(floats,0,1) = r0[5],
	MAT(floats,0,2) = r0[6];   MAT(floats,0,3) = r0[7],
	MAT(floats,1,0) = r1[4];   MAT(floats,1,1) = r1[5],
	MAT(floats,1,2) = r1[6];   MAT(floats,1,3) = r1[7],
	MAT(floats,2,0) = r2[4];   MAT(floats,2,1) = r2[5],
	MAT(floats,2,2) = r2[6];   MAT(floats,2,3) = r2[7],
	MAT(floats,3,0) = r3[4];   MAT(floats,3,1) = r3[5],
	MAT(floats,3,2) = r3[6];   MAT(floats,3,3) = r3[7];

#undef MAT
#undef SWAP_ROWS
#undef INV_ERR

 
	return *this;
}

//====================================================================
void mat44::decompose( vec3& scale,  Quaternion& rot, vec3& pos ) const
{

	mat44 m =  *this;;

	pos =  getTranslation();

	scale.x =  sqrt(  sqr(m.floats[0][0]) +   sqr(m.floats[0][1]) +   sqr(m.floats[0][2]));
	scale.y =  sqrt(  sqr(m.floats[1][0]) +   sqr(m.floats[1][1]) +   sqr(m.floats[1][2]));
	scale.z =  sqrt(  sqr(m.floats[2][0]) +   sqr(m.floats[2][1]) +   sqr(m.floats[2][2]));

	for (int i=0; i<3; i++)
	{
		if (scale.floats[i] > EPSILON)
		{
			m.floats[i][0] /= scale.floats[i];
			m.floats[i][1] /= scale.floats[i];
			m.floats[i][2] /= scale.floats[i];
		}
	}

	rot.setRotationMatrix(m);


}



// void mat44::decompose(vec3& pos,  Quaternion& rot, vec3& scale) const
// {

		// mat44 m = *this;

		// pos = m.getPos();

		// scale.x = gbmath::sqrt(gbmath::sqr(m.data[0][0]) + gbmath::sqr(m.data[0][1]) + gbmath::sqr(m.data[0][2]));
		// scale.y = gbmath::sqrt(gbmath::sqr(m.data[1][0]) + gbmath::sqr(m.data[1][1]) + gbmath::sqr(m.data[1][2]));
		// scale.z = gbmath::sqrt(gbmath::sqr(m.data[2][0]) + gbmath::sqr(m.data[2][1]) + gbmath::sqr(m.data[2][2]));

		// for (int i=0; i<3; i++) {
			// if (scale.v[i] > EPSILON) {
				// m.data[i][0] /= scale.v[i];
				// m.data[i][1] /= scale.v[i];
				// m.data[i][2] /= scale.v[i];
			// }
		// }

		// rot.fromMatrix(m);

// }

 
}
