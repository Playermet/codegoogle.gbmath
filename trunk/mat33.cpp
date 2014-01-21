 

#include "_gbmath.h"


 
namespace gbmath
{



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
}


float mat33::determinant () const
{
	return floats [0][0]*(floats [1][1]* floats [2][2]-floats [1][2]* floats [2][1]) -
	       floats [0][1]*(floats [1][0]* floats [2][2]-floats [1][2]* floats [2][0]) +
	       floats [0][2]*(floats [1][0]* floats [2][1]-floats [1][1]* floats [2][0]);
}


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


mat33& mat33::operator = ( float a )
{
  floats [0][1] = floats [0][2] = floats [1][0] =
  floats [1][2] = floats [2][0] = floats [2][1] = 0.0;

  floats [0][0] = floats [1][1] = floats [2][2] = a;

	return *this;
}


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


mat33 mat33::operator * ( const mat33& m ) const
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


vec3 mat33::operator * ( const vec3& v ) const
{
	vec3 res;

	res.x = floats [0][0]*v.x + floats [0][1]*v.y + floats [0][2]*v.z;
	res.y = floats [1][0]*v.x + floats [1][1]*v.y + floats [1][2]*v.z;
	res.z = floats [2][0]*v.x + floats [2][1]*v.y + floats [2][2]*v.z;

	return res;
}


mat33& mat33::setScaling ( float x, float y, float z )
{
	 setIdentity();

  floats  [0][0] = x;
  floats  [1][1] = y;
  floats  [2][2] = z;

	return *this;
}


mat33& mat33::setScaling ( const vec3& v )
{
    setIdentity();

  floats  [0][0] = v.x;
  floats  [1][1] = v.y;
  floats  [2][2] = v.z;

	return *this;
}


mat33& mat33::setRotationX ( float angle )
{
	float sine ,  cosine;
	 sincos(angle , sine, cosine);

	setIdentity();
	floats  [1][1] = cosine;
	floats  [1][2] = sine;
	floats  [2][1] = -sine;
	floats  [2][2] = cosine;

	return *this;
}


mat33& mat33::setRotationY ( float angle )
{
	float sine ,  cosine;
	 sincos(angle , sine, cosine);

	setIdentity();
	floats  [0][0] = cosine;
	floats  [0][2] = -sine;
	floats  [2][0] = sine;
	floats  [2][2] = cosine;

	return *this;
}


mat33& mat33::setRotationZ ( float angle )
{

	float sine ,  cosine;
	 sincos(angle , sine, cosine);

	setIdentity();
	floats  [0][0] = cosine;
	floats  [0][1] = sine;
	floats  [1][0] = -sine;
	floats  [1][1] = cosine;

	return *this;
}


mat33& mat33::setRotation ( const vec3& v, float angle )
{

 	float sine ,  cosine;
 	 sincos(angle , sine, cosine);

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


mat33&  mat33::setMirrorX()
{
	setIdentity();
	floats  [0][0] = -1.0;
	return *this;
}


mat33&  mat33::setMirrorY()
{
	setIdentity();
	floats  [1][1] = -1.0;
	return *this;
}

 
mat33&  mat33::setMirrorZ()
{
	setIdentity();
	floats  [2][2] = -1.0;
	return  *this;
}


 
}
