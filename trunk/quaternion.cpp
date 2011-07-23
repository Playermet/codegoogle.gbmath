
//#include "pch.h"
//#include "stdafx.h"
//#include "d3d9pch.h"

#include "fmath.h"

namespace gb 
{
namespace fmath 
{

//=========================================================================


 


//=========================================================================
//                          Quaternion
//=========================================================================

//=========================================================================
Quaternion&  Quaternion::setRotationMatrix(const  mat44& m)
{

	float fTrace = m.floats[0][0] + m.floats[1][1] + m.floats[2][2];
	float fRoot;

	if (fTrace > 0.0) 
	{
		fRoot =  sqrt(fTrace + 1.0f);
		 w = 0.5f * fRoot;

		fRoot = 0.5f / fRoot;

		 x = (m.floats[1][2] - m.floats[2][1]) * fRoot;
		 y = (m.floats[2][0] - m.floats[0][2]) * fRoot;
		 z = (m.floats[0][1] - m.floats[1][0]) * fRoot;
	}
	else
	{
		static size_t s_iNext[3] = { 1, 2, 0 };
		size_t i = 0;

		if (m.floats[1][1] > m.floats[0][0] ) i = 1;
		if (m.floats[2][2] > m.floats[i][i] ) i = 2;

		size_t j = s_iNext[i];
		size_t k = s_iNext[j];

		fRoot =  sqrt(m.floats[i][i] - m.floats[j][j] - m.floats[k][k] + 1.0f);

		floats[i] = 0.5f * fRoot;
		fRoot = 0.5f / fRoot;
		w = (m.floats[j][k] - m.floats[k][j]) * fRoot;
		floats[j] = (m.floats[i][j] + m.floats[j][i]) * fRoot;
		floats[k] = (m.floats[i][k] + m.floats[k][i]) * fRoot;
	}
 
   return *this;
};


//=========================================================================
Quaternion Quaternion::slerp( const Quaternion &q1, float t )
{
 
//
//	// Check for out-of range parameter and return edge points if so
//
//	if (t <= 0.0f) return q0;
//	if (t >= 1.0f) return q1;
//
//	// Compute "cosine of angle between quaternions" using dot product
//
//	float cosOmega =   q0.dot(q1); //  xx  dotProduct(q0, q1);
//
//	// If negative dot, use -q1.  Two quaternions q and -q
//	// represent the same rotation, but may produce
//	// different slerp.  We chose q or -q to rotate using
//	// the acute angle.
//
//	float q1w = q1.w;
//	float q1x = q1.x;
//	float q1y = q1.y;
//	float q1z = q1.z;
//
//	if (cosOmega < 0.0f) 
//	{
//		q1w = -q1w;
//		q1x = -q1x;
//		q1y = -q1y;
//		q1z = -q1z;
//		cosOmega = -cosOmega;
//	}
//
//	// We should have two unit quaternions, so dot should be <= 1.0
//
//#pragma message("ks777::  gb::fmath::quat slerp ассерт отключён"  __FILE__)
////	assert(cosOmega < 1.1f);
//
//
//	// Compute interpolation fraction, checking for quaternions
//	// almost exactly the same
//
//	float k0, k1;
//	if (cosOmega > 0.9999f) 
//	{
//
//		// Very close - just use linear interpolation,
//		// which will protect againt a divide by zero
//
//		k0 = 1.0f-t;
//		k1 = t;
//
//	} 
//	else 
//	{
//
//		// Compute the sin of the angle using the
//		// trig identity sin^2(omega) + cos^2(omega) = 1
//
//		float sinOmega = sqrt(1.0f - cosOmega*cosOmega);
//
//		// Compute the angle from its sin and cosine
//
//		float omega = atan2(sinOmega, cosOmega);
//
//		// Compute inverse of denominator, so we only have
//		// to divide once
//
//		float oneOverSinOmega = 1.0f / sinOmega;
//
//		// Compute interpolation parameters
//
//		k0 = sin((1.0f - t) * omega) * oneOverSinOmega;
//		k1 = sin(t * omega) * oneOverSinOmega;
//	}
//
//	// Interpolate
//
//	Quaternion result;
//	result.x = k0*q0.x + k1*q1x;
//	result.y = k0*q0.y + k1*q1y;
//	result.z = k0*q0.z + k1*q1z;
//	result.w = k0*q0.w + k1*q1w;
//
//	// Return it
//
//	return result;
// 

	Quaternion res;

	float k0,k1,cosomega = this->x * q1.x + this->y * q1.y + this->z * q1.z + this->w * q1.w;
	Quaternion q;
	if(cosomega < 0.0) 
	{
		cosomega = -cosomega;
		q.x = -q1.x;
		q.y = -q1.y;
		q.z = -q1.z;
		q.w = -q1.w;
	} 
	else 
	{
		q.x = q1.x;
		q.y = q1.y;
		q.z = q1.z;
		q.w = q1.w;
	}
	if(1.0 - cosomega > 1e-6) 
	{
		float omega = acos(cosomega);
		float sinomega = sin(omega);
		k0 = sin((1.0f - t) * omega) / sinomega;
		k1 = sin(t * omega) / sinomega;
	} 
	else 
	{
		k0 = 1.0f - t;
		k1 = t;
	}
	res.x = this->x * k0 + q.x * k1;
	res.y = this->y * k0 + q.y * k1;
	res.z = this->z * k0 + q.z * k1;
	res.w = this->w * k0 + q.w * k1;
	return res;

};

//=======================================================================
Quaternion Quaternion::pow(const Quaternion &q, float exponent) const 
{
 
	// Check for the case of an identity quaternion.
	// This will protect against divide by zero

	if (fabs(q.w) > .9999f) {
		return q;
	}

	// Extract the half angle alpha (alpha = theta/2)

	float	alpha = acos(q.w);

	// Compute new alpha value

	float	newAlpha = alpha * exponent;

	// Compute new w value

	Quaternion result;
	result.w = cos(newAlpha);

	// Compute new xyz values

	float	mult = sin(newAlpha) / sin(alpha);
	result.x = q.x * mult;
	result.y = q.y * mult;
	result.z = q.z * mult;

	// Return it

	return result;
 

}

//=========================================================================
 vec3	Quaternion::getRotationAxis() const 
{

	// Compute sin^2(theta/2).  Remember that w = cos(theta/2),
	// and sin^2(x) + cos^2(x) = 1

	float sinThetaOver2Sq = 1.0f - w*w;

	// Protect against numerical imprecision

	if (sinThetaOver2Sq <= 0.0f) {

		// Identity quaternion, or numerical imprecision.  Just
		// return any valid vector, since it doesn't matter

		return  vec3(1.0f, 0.0f, 0.0f);
	}

	// Compute 1 / sin(theta/2)

	float	oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);

	// Return axis of rotation

	return  vec3 (
		x * oneOverSinThetaOver2,
		y * oneOverSinThetaOver2,
		z * oneOverSinThetaOver2
		);
}

//=========================================================================
Quaternion&  Quaternion::setRotationAxis(const  vec3 &axis, float theta) 
{

	// The axis of rotation must be normalized

#pragma message("KS777: MATH::QUAT::setRotationAboutAxisAngle >> NEED CHECK !!"   __FILE__ )
	// assert( fabs(vectorMag(axis) - 1.0f) < 0.01f );

	// Compute the half angle and its sin
	const float	thetaOver2 = theta*0.5f;
	const float	sinThetaOver2 = sin(thetaOver2);

	// Set the values
	w = cos(thetaOver2);
	x = axis.x * sinThetaOver2;
	y = axis.y * sinThetaOver2;
	z = axis.z * sinThetaOver2;
	return *this;
}

//=========================================================================
inline AxiesAngle Quaternion::getRotationAxiesAngle() const 
{
	 AxiesAngle res;
	res.angle = getRotationAngle();
	res.axies = getRotationAxis();
	return res;
}

//=========================================================================
AxiesAngle Quaternion::toAxiesAngle() const 
{ 
	return getRotationAxiesAngle(); 
}

//=========================================================================
Quaternion&  Quaternion::setRotationAxis(const AxiesAngle& aa)
{
	return setRotationAxis( aa.axies , aa.angle );
}

//=========================================================================
void Quaternion::setRotationEulersAngles(const euler_angles& ea)
{
	setRotationYawPitchRoll(ea.yaw, ea.pitch, ea.roll);
}


//=========================================================================

} // end  namespace fmath
} // end namespace gb

// end file