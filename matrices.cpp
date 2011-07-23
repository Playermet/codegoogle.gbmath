
//#include "pch.h"
//#include "stdafx.h"
//#include "d3d9pch.h"


#include "fmath.h"

namespace gb 
{
namespace fmath 
{
 
//===============================================================


 


//=========================================================================
//    mat22_s
//=========================================================================
//
////=======================================================================
//mat22_s& mat22_s::operator = ( const mat22_s& m )
//{
//fggfgdfg
//
//	return *this;
//}
//
////=========================================================================
//mat22_s& mat22_s::operator = ( float f )
//{
//gfgdfdfgfdg
//
//	return *this;
//}
//
////=========================================================================
//mat22_s& mat22_s::operator += ( const mat22_s& m )
//{
//dfdsfsdfdsf
//}
//
////=========================================================================
//mat22_s& mat22_s::operator -= ( const mat22_s& m )
//gffgdfg
//
////=========================================================================
//mat22_s& mat22_s::operator *= ( const mat22_s& m )
//
//
////=========================================================================
//mat22_s& mat22_s::operator *= ( float f )
//gfdfgfgfd
//
////=========================================================================
//mat22_s& mat22_s::operator /= ( float f )
//{
//fddfs
//};
//
//
////=========================================================================
//mat22_s  mat22_s::operator + ( const mat22_s& m ) const 
//gfggfggfgfggdgf fgfggf
//
////=========================================================================
//mat22_s  mat22_s::operator - ( const mat22_s& m) const 
//dffdfdsf
//
////=========================================================================
//mat22_s  mat22_s::operator * ( const mat22_s& m) const 
//fgdfgfdgfd
//
////=========================================================================
//mat22_s  mat22_s::operator * (  float f ) const
//fdfddf
//
////=========================================================================
//vec2_s   mat22_s::operator * ( const vec2_s& v ) const

/************************
//=========================================================================
mat22_s operator * ( float b, const mat22_s& a )
{
	mat22_s c;

	c.x[0][0]=a.x[0][0]*b;
	c.x[0][1]=a.x[0][1]*b;
	c.x[1][0]=a.x[1][0]*b;
	c.x[1][1]=a.x[1][1]*b;

	return c;
}
**************************************/

//=========================================================================

//
//
////=========================================================================
//mat22_s& mat22_s::invert ()
//fgfddgdfg
// 
////=========================================================================
//mat22_s& mat22_s::setScaling ( const vec2_s& v )
//ggffdf
//
////=========================================================================
//mat22_s&   mat22_s::setScaling (float x, float y)
//dfdsdfsdfds
//
////=========================================================================
//mat22_s& mat22_s::setRotation ( float angle )
//dfdsfdsdf
// 
 


//=========================================================================
//
//    mat33
//
//=========================================================================
 
//=========================================================================
mat33& mat33::operator *= ( float f )
{
	floats[0][0] *= f;
	floats[0][1] *= f;
	floats[0][2] *= f;
	floats[1][0] *= f;
	floats[1][1] *= f;
	floats[1][2] *= f;
	floats[2][0] *= f;
	floats[2][1] *= f;
	floats[2][2] *= f;

	return *this;
}

//=========================================================================
mat33& mat33::operator /= ( float f )
{
	floats[0][0] /= f;
	floats[0][1] /= f;
	floats[0][2] /= f;
	floats[1][0] /= f;
	floats[1][1] /= f;
	floats[1][2] /= f;
	floats[2][0] /= f;
	floats[2][1] /= f;
	floats[2][2] /= f;

	return *this;
};

//=========================================================================
float mat33::determinant () const
{
	return floats [0][0]*(floats [1][1]* floats [2][2]-floats [1][2]* floats [2][1]) -
	       floats [0][1]*(floats [1][0]* floats [2][2]-floats [1][2]* floats [2][0]) +
	       floats [0][2]*(floats [1][0]* floats [2][1]-floats [1][1]* floats [2][0]);
}

//=========================================================================
mat33&  mat33::invert ()
{
	mat33 a;

 
	float det = 
		floats [0][0]*(floats [1][1]* floats [2][2]-floats [1][2]* floats [2][1]) -
	    floats [0][1]*(floats [1][0]* floats [2][2]-floats [1][2]* floats [2][0]) +
	    floats [0][2]*(floats [1][0]* floats [2][1]-floats [1][1]* floats [2][0]);

	a.floats  [0][0] = (floats [1][1]* floats [2][2]-floats [1][2]* floats [2][1]) / det;
	a.floats  [0][1] = (floats [0][2]* floats [2][1]-floats [0][1]* floats [2][2]) / det;
	a.floats  [0][2] = (floats [0][1]* floats [1][2]-floats [0][2]* floats [1][1]) / det;
	a.floats  [1][0] = (floats [1][2]* floats [2][0]-floats [1][0]* floats [2][2]) / det;
	a.floats  [1][1] = (floats [0][0]* floats [2][2]-floats [0][2]* floats [2][0]) / det;
	a.floats  [1][2] = (floats [0][2]* floats [1][0]-floats [0][0]* floats [1][2]) / det;
	a.floats  [2][0] = (floats [1][0]* floats [2][1]-floats [1][1]* floats [2][0]) / det;
	a.floats  [2][1] = (floats [0][1]* floats [2][0]-floats [0][0]* floats [2][1]) / det;
	a.floats  [2][2] = (floats [0][0]* floats [1][1]-floats [0][1]* floats [1][0]) / det;

	*this = a;

	return *this;
}

//=========================================================================

mat33 mat33::operator + ( const mat33& m ) const  
{
	mat33 res;

	res.floats [0][0] = floats [0][0] + m.floats [0][0];
	res.floats [0][1] = floats [0][1] + m.floats [0][1];
	res.floats [0][2] = floats [0][2] + m.floats [0][2];
	res.floats [1][0] = floats [1][0] + m.floats [1][0];
	res.floats [1][1] = floats [1][1] + m.floats [1][1];
	res.floats [1][2] = floats [1][2] + m.floats [1][2];
	res.floats [2][0] = floats [2][0] + m.floats [2][0];
	res.floats [2][1] = floats [2][1] + m.floats [2][1];
	res.floats [2][2] = floats [2][2] + m.floats [2][2];

	return res;
}

//=========================================================================
mat33 mat33::operator - ( const mat33& m ) const  
{
	mat33 r;

	r.floats [0][0] = floats [0][0] - m.floats [0][0];
	r.floats [0][1] = floats [0][1] - m.floats [0][1];
	r.floats [0][2] = floats [0][2] - m.floats [0][2];
	r.floats [1][0] = floats [1][0] - m.floats [1][0];
	r.floats [1][1] = floats [1][1] - m.floats [1][1];
	r.floats [1][2] = floats [1][2] - m.floats [1][2];
	r.floats [2][0] = floats [2][0] - m.floats [2][0];
	r.floats [2][1] = floats [2][1] - m.floats [2][1];
	r.floats [2][2] = floats [2][2] - m.floats [2][2];

	return r;
}

//==========================================================================
mat33& mat33::operator = ( float a )
{
  floats [0][1] = floats [0][2] = floats [1][0] =
  floats [1][2] = floats [2][0] = floats [2][1] = 0.0;
  
  floats [0][0] = floats [1][1] = floats [2][2] = a;

	return *this;
}

//=========================================================================
mat33& mat33::operator += ( const mat33& a )
{
  floats [0][0] += a.floats  [0][0];
  floats [0][1] += a.floats  [0][1];
  floats [0][2] += a.floats  [0][2];
  floats [1][0] += a.floats  [1][0];
  floats [1][1] += a.floats  [1][1];
  floats [1][2] += a.floats  [1][2];
  floats [2][0] += a.floats  [2][0];
  floats [2][1] += a.floats  [2][1];
  floats [2][2] += a.floats  [2][2];

	return *this;
}

//=========================================================================
mat33& mat33::operator -= ( const mat33& a )
{
  floats [0][0] -=a.floats  [0][0];
  floats [0][1] -=a.floats  [0][1];
  floats [0][2] -=a.floats  [0][2];
  floats [1][0] -=a.floats  [1][0];
  floats [1][1] -=a.floats  [1][1];
  floats [1][2] -=a.floats  [1][2];
  floats [2][0] -=a.floats  [2][0];
  floats [2][1] -=a.floats  [2][1];
  floats [2][2] -=a.floats  [2][2];

	return *this;
}


//=========================================================================
mat33 mat33::operator * ( const mat33& m) const 
{
	mat33 res;
    res = *this;

	res.floats[0][0]= floats [0][0]*m.floats[0][0]+ floats [0][1]*m.floats[1][0]+ floats [0][2]*m.floats[2][0];
	res.floats[0][1]= floats [0][0]*m.floats[0][1]+ floats [0][1]*m.floats[1][1]+ floats [0][2]*m.floats[2][1];
	res.floats[0][2]= floats [0][0]*m.floats[0][2]+ floats [0][1]*m.floats[1][2]+ floats [0][2]*m.floats[2][2];
	res.floats[1][0]= floats [1][0]*m.floats[0][0]+ floats [1][1]*m.floats[1][0]+ floats [1][2]*m.floats[2][0];
	res.floats[1][1]= floats [1][0]*m.floats[0][1]+ floats [1][1]*m.floats[1][1]+ floats [1][2]*m.floats[2][1];
	res.floats[1][2]= floats [1][0]*m.floats[0][2]+ floats [1][1]*m.floats[1][2]+ floats [1][2]*m.floats[2][2];
	res.floats[2][0]= floats [2][0]*m.floats[0][0]+ floats [2][1]*m.floats[1][0]+ floats [2][2]*m.floats[2][0];
	res.floats[2][1]= floats [2][0]*m.floats[0][1]+ floats [2][1]*m.floats[1][1]+ floats [2][2]*m.floats[2][1];
	res.floats[2][2]= floats [2][0]*m.floats[0][2]+ floats [2][1]*m.floats[1][2]+ floats [2][2]*m.floats[2][2];

	return res;
}

//=========================================================================
mat33 mat33::operator * (  float f ) const 
{
	mat33  res;

	res.floats [0][0] =  floats  [0][0] * f;
	res.floats [0][1] =  floats  [0][1] * f;
	res.floats [0][2] =  floats  [0][2] * f;
	res.floats [1][0] =  floats  [1][0] * f;
	res.floats [1][1] =  floats  [1][1] * f;
	res.floats [1][2] =  floats  [1][2] * f;
	res.floats [2][0] =  floats  [2][0] * f;
	res.floats [2][1] =  floats  [2][1] * f;
	res.floats [2][0] =  floats  [0][0] * f;

	return res;
}

//=========================================================================
mat33&   mat33::operator *= ( const mat33& m )
{
	mat33 t  = *this;

	floats[0][0]=t.floats[0][0]*m.floats[0][0]+t.floats[0][1]*m.floats[1][0]+t.floats[0][2]*m.floats[2][0];
	floats[0][1]=t.floats[0][0]*m.floats[0][1]+t.floats[0][1]*m.floats[1][1]+t.floats[0][2]*m.floats[2][1];
	floats[0][2]=t.floats[0][0]*m.floats[0][2]+t.floats[0][1]*m.floats[1][2]+t.floats[0][2]*m.floats[2][2];
	floats[1][0]=t.floats[1][0]*m.floats[0][0]+t.floats[1][1]*m.floats[1][0]+t.floats[1][2]*m.floats[2][0];
	floats[1][1]=t.floats[1][0]*m.floats[0][1]+t.floats[1][1]*m.floats[1][1]+t.floats[1][2]*m.floats[2][1];
	floats[1][2]=t.floats[1][0]*m.floats[0][2]+t.floats[1][1]*m.floats[1][2]+t.floats[1][2]*m.floats[2][2];
	floats[2][0]=t.floats[2][0]*m.floats[0][0]+t.floats[2][1]*m.floats[1][0]+t.floats[2][2]*m.floats[2][0];
	floats[2][1]=t.floats[2][0]*m.floats[0][1]+t.floats[2][1]*m.floats[1][1]+t.floats[2][2]*m.floats[2][1];
	floats[2][2]=t.floats[2][0]*m.floats[0][2]+t.floats[2][1]*m.floats[1][2]+t.floats[2][2]*m.floats[2][2];
 
	return *this;
}

//=========================================================================
vec3 mat33::operator * ( const vec3& v ) const
{
	vec3 res;

	res.x = floats [0][0]*v.x + floats [0][1]*v.y + floats [0][2]*v.z;
	res.y = floats [1][0]*v.x + floats [1][1]*v.y + floats [1][2]*v.z;
	res.z = floats [2][0]*v.x + floats [2][1]*v.y + floats [2][2]*v.z;

	return res;
}

//=========================================================================
mat33& mat33::setScaling ( float x, float y, float z )
{
	 setIdentity();

  floats  [0][0] = x;
  floats  [1][1] = y;
  floats  [2][2] = z;

	return *this;
}

//=========================================================================
mat33& mat33::setScaling ( const vec3& v )
{
    setIdentity();

  floats  [0][0] = v.x;
  floats  [1][1] = v.y;
  floats  [2][2] = v.z;

	return *this;
}

//=========================================================================
mat33& mat33::setRotationX ( float angle )
{
	float sine ,  cosine;
	scalar::sincos(angle , sine, cosine);
 
	setIdentity();
	floats  [1][1] = cosine;
	floats  [1][2] = sine;
	floats  [2][1] = -sine;
	floats  [2][2] = cosine;

	return *this;
}

//=========================================================================
mat33& mat33::setRotationY ( float angle )
{
	float sine ,  cosine;
	scalar::sincos(angle , sine, cosine);
 
	setIdentity();
	floats  [0][0] = cosine;
	floats  [0][2] = -sine;
	floats  [2][0] = sine;
	floats  [2][2] = cosine;

	return *this;
}

//=========================================================================
mat33& mat33::setRotationZ ( float angle )
{
 
	float sine ,  cosine;
	scalar::sincos(angle , sine, cosine);
 
	setIdentity();
	floats  [0][0] = cosine;
	floats  [0][1] = sine;
	floats  [1][0] = -sine;
	floats  [1][1] = cosine;

	return *this;
}

//=========================================================================
mat33& mat33::setRotation ( const vec3& v, float angle )
{

 	float sine ,  cosine;
 	scalar::sincos(angle , sine, cosine);

	 floats [0][0] = v.x *v.x + (1-v.x*v.x) * cosine;
	 floats [0][1] = v.x *v.y * (1-cosine) + v.z * sine;
	 floats [0][2] = v.x *v.z * (1-cosine) - v.y * sine;
	 floats [1][0] = v.x *v.y * (1-cosine) - v.z * sine;
	 floats [1][1] = v.y *v.y + (1-v.y*v.y) * cosine;
	 floats [1][2] = v.y *v.z * (1-cosine) + v.x * sine;
	 floats [2][0] = v.x *v.z * (1-cosine) + v.y * sine;
	 floats [2][1] = v.y *v.z * (1-cosine) - v.x * sine;
	 floats [2][2] = v.z *v.z + (1-v.z*v.z) * cosine;

	
	return *this; 
}

//=========================================================================
mat33&  mat33::setMirrorX()
{
 setIdentity();
 floats  [0][0] = -1.0;
 return *this;
}

//=========================================================================
mat33&  mat33::setMirrorY()
{
 setIdentity();
  floats  [1][1] = -1.0;
 return *this;
}

//=========================================================================
mat33&  mat33::setMirrorZ()
{
 setIdentity();
 floats  [2][2] = -1.0;
 return  *this;
}

//=========================================================================
//    mat44
//=========================================================================



//=====================================================================
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
};


//=========================================================================
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
};

//=========================================================================
mat44& mat44::setWorldTransform(const TransformData& t)
{
	return setTransformation(t.vScaling, t.qRotation, t.vTranslation );
}

//=========================================================================
mat44& mat44::setReflection(const plane_s& plane )
{

	float a, b, c, d;

	const float k = sqrt( plane.a*plane.a + plane.b*plane.b + plane.c*plane.c );
	a = plane.a / k;
	b = plane.b / k;
	c = plane.c / k;
	d = plane.d / k;

	mat44 Out;

	Out._11=1.0f-2.0f*scalar::sqr(a);   Out._12=-2.0f*b*a;					 Out._13=-2.0f*c*a;				    Out._14=0.0f;

	Out._21=-2.0f*a*b;					  Out._22=1.0f-2.0f*scalar::sqr(b);  Out._23=-2.0f*c*b;					Out._24=0.0f;

	Out._31=-2.0f*a*c;				     Out._32=-2.0f*b*c;					 Out._33=1.0f-2.0f*scalar::sqr(c);  Out._34=0.0f;

	Out._41=-2.0f*a*d;					 Out._42=-2.0f*b*d;				     Out._43=-2.0f*c*d;				    Out._44=1.0f;

	*this = Out;

	return *this;
};

//=========================================================================
mat44&  mat44::setShadow(const vec4& Light, const plane_s& Plane )
{
	float a,b,c,d;
	const float k = sqrt( scalar::sqr(Plane.a) + scalar::sqr(Plane.b) + scalar::sqr(Plane.c) );
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
};



//=========================================================================
mat44& mat44::invert () throw()
{
#define SWAP_ROWS(a, b) {  float * _tmp = a; (a)=(b); (b)=_tmp; }
#define MAT(fl,r,c)     fl [r][c]
#define INV_ERR   std::runtime_error("invert failed");

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

	//return true;
	return *this;
}

//====================================================================
void mat44::decompose( vec3& scale,  Quaternion& rot, vec3& pos ) const
{

	mat44 m =  *this;;

	pos =  getTranslation();

	scale.x =  sqrt( scalar::sqr(m.floats[0][0]) +  scalar::sqr(m.floats[0][1]) +  scalar::sqr(m.floats[0][2]));
	scale.y =  sqrt( scalar::sqr(m.floats[1][0]) +  scalar::sqr(m.floats[1][1]) +  scalar::sqr(m.floats[1][2]));
	scale.z =  sqrt( scalar::sqr(m.floats[2][0]) +  scalar::sqr(m.floats[2][1]) +  scalar::sqr(m.floats[2][2]));

	for (int i=0; i<3; i++) 
	{
		if (scale.floats[i] > constan::CEPSILON) 
		{
			m.floats[i][0] /= scale.floats[i];
			m.floats[i][1] /= scale.floats[i];
			m.floats[i][2] /= scale.floats[i];
		}
	}

	rot.setRotationMatrix(m);
 

};


//=========================================================================

 
// void mat44::decompose(vec3& pos,  Quaternion& rot, vec3& scale) const 
// {

		// mat44 m = *this;

		// pos = m.getPos();

		// scale.x = fmath::sqrt(fmath::sqr(m.data[0][0]) + fmath::sqr(m.data[0][1]) + fmath::sqr(m.data[0][2]));
		// scale.y = fmath::sqrt(fmath::sqr(m.data[1][0]) + fmath::sqr(m.data[1][1]) + fmath::sqr(m.data[1][2]));
		// scale.z = fmath::sqrt(fmath::sqr(m.data[2][0]) + fmath::sqr(m.data[2][1]) + fmath::sqr(m.data[2][2]));

		// for (int i=0; i<3; i++) {
			// if (scale.v[i] > EPSILON) {
				// m.data[i][0] /= scale.v[i];
				// m.data[i][1] /= scale.v[i];
				// m.data[i][2] /= scale.v[i];
			// }
		// }

		// rot.fromMatrix(m);
		
// }
 
 
//=========================================================================

}
// end namespace
}
// end namespace

// end file