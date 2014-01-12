/**  \file
 \brief vector 3d


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{




		//! \brief 3d-base vector. Corrected by operators epislon
		struct vec3  {

		    union
			{

				struct
				{
				   float x, y, z;
				};

				float floats [3];
			};

			inline vec3() 
			{ 
				x = y = z = 0.0f; 
			}

			inline vec3(const vec3& v)             
			{ 
				x = v.x;   
				y = v.y;   
				z = v.z;   
			}

			inline vec3(const vec3* v)             
			{ 
				x = v->x;  
				y = v->y; 
				z = v->z;   
			}

			inline vec3(const vec2& v, float _z)   
			{ 
				x = v.x;  
				y = v.y; 
				z = _z;     
			}

			inline vec3(float _x, float _y, float _z)  
			{ 
				x=_x;    
				y=_y;    
				z=_z;  
			}
 

			inline vec3(const float* pfArray) 
			{ 
				*this = pfArray; 
			}


			// physX cats
#ifdef NX_FOUNDATION_NXVEC3

			inline vec3(const NxVec3 & a)
			{
				x = (float)a.x;
				y = (float)a.y;
				z = (float)a.z;
			}


#endif  // #ifdef NX_FOUNDATION_NXVEC3


#ifdef B2_MATH_H

	inline vec3 (const b2Vec3& a)
	{
		x = (float)a.x;
		y = (float)a.y;
		z = (float)a.z;
	}

#endif 
 

			inline void operator = (const float* pf) 
			{
				x = pf[0]; 
				y = pf[1]; 
				z = pf[2]; 
			}

			inline bool  operator == (const vec3 &v) const 
			{ 
				return (x == v.x && y == v.y && z == v.z ); 
			}

			inline bool  operator != (const vec3 &v) const
			{ 
				return (x != v.x || y != v.y || z != v.z ); 
			}

			//inline bool  operator <  (const vec3 &v) const {	return (x <  v.x && y <  v.y && z <  v.z ); }
			//inline bool  operator <= (const vec3 &v) const {	return (x <= v.x && y <= v.y && z <= v.z ); }
			//inline bool  operator >  (const vec3 &v) const {	return (x >  v.x && y >  v.y && z >  v.z ); }
			//inline bool  operator >= (const vec3 &v) const {	return (x >= v.x && y >= v.y && z >= v.z ); }

			inline vec3  operator + () const   
			{ 	
				return *this; 
			}

			inline vec3  operator - () const 
			{	
				vec3 res;	
				res.x = -x;	
				res.y = -y;	
				res.z = -z;	
				return res; 
			}

			inline vec3  operator + (const vec3 &v) const {	vec3 res;	res = *this; res += v;	return res; }
			inline vec3  operator - (const vec3 &v) const {	vec3 res;	res = *this; res -= v;	return res; }
			inline vec3  operator * (float f) const         { vec3 res = *this;      res.x *= f;	res.y *= f;	res.z *= f;	return res; }
			inline vec3  operator / (float f) const         { vec3 res = *this;	     res.x /= f;	res.y /= f;	res.z /= f;	return res; }

			inline vec3 &  operator += (const vec3 &v)    {	x += v.x;	y += v.y;	z += v.z;	return *this; }
			inline vec3 &  operator -= (const vec3 &v)    {	x -= v.x;	y -= v.y;	z -= v.z;	return *this; }
			inline vec3 &  operator *= (float f)            {	x *= f;	y *= f;	z *= f;	return *this; }
			inline vec3 &  operator *= (const vec3 &v)    {	x *= v.x;	y *= v.y;	z *= v.z;	return *this; }
			inline vec3 &  operator /= (float f)            {	x /= f;	y /= f;	z /= f;	return *this; }
			inline vec3 &  operator /= (const vec3 &v)    {	x /= v.x;	y /= v.y;	z /= v.z;	return *this; }

			//inline vec3 &  operator += (float f) {  }

			inline operator  const float*() const  { return &x; }
			inline operator        float*()        { return &x; }


			inline float operator [] (unsigned int index) const throw(std::out_of_range)
			{
				if(index>2) throw std::out_of_range("invalid index");
				const float* pf = &x;
				return pf[index];
			}

			inline  float& operator [] (unsigned int index) throw(std::out_of_range)
			{
				if(index>2) throw std::out_of_range("invalid index");
				float* pf = &x;
				return *(pf + index);
			}




#ifdef _D3D9_H_
			inline operator D3DVECTOR*() { return (D3DVECTOR*)&x; }
			inline operator const D3DVECTOR*() const { return (D3DVECTOR*)&x; }
			inline operator D3DVECTOR() const  { D3DVECTOR r; r.x=x; r.y=y; r.z=z; return r;  }
			inline void operator = (const D3DVECTOR& v) {	x=v.x; y=v.y; z=v.z; }
#endif // #ifdef _D3D9_H_


#ifdef __D3DX9MATH_H__
			inline operator D3DXVECTOR3*() { return (D3DXVECTOR3*)&x; }
			inline operator const D3DXVECTOR3*() const { return (D3DXVECTOR3*)&x; }
			inline operator D3DXVECTOR3() const  {  return D3DXVECTOR3(x,y,z); }
		   	inline void operator = (const D3DXVECTOR3& v) {	x=v.x; y=v.y; z=v.z; }
#endif // #ifdef __D3DX9MATH_H__

 

// physX cats
#ifdef NX_FOUNDATION_NXVEC3


			inline void operator = (const NxVec3 & a)
			{
				x = (float)a.x;
				y = (float)a.y;
				z = (float)a.z;
			}

			inline operator NxVec3 () const
			{
				NxVec3 res;
				res.x = (NxReal)x;
				res.y = (NxReal)y;
				res.z = (NxReal)z;
				return res;
			}
 

#endif  // #ifdef NX_FOUNDATION_NXVEC3

#ifdef B2_MATH_H

	inline void operator = (const b2Vec3& a)
	{
		x = (float)a.x;
		y = (float)a.y;
		z = (float)a.z;
	}
	
	inline operator  b2Vec3 () const 
	{
		b2Vec2 res;
		res.x = (float32)x;
		res.y = (float32)y;
		res.z = (float32)z;
		return res;
	}


#endif 


 
			void operator = (const point3& pnt);


		    inline void setzero() 
			{ 
				x = y = z = 0.0f; 
			}

			inline bool empty() const 
			{ 
				return (x==0.0f) && (y==0.0f) && (z==0.0f); 
			}

			inline vec3& set    (float _x, float _y, float _z) 
			{ 
				x=_x; 
				y=_y; 
				z=_z; 
				return *this; 
			}

			inline vec3& set_all ( float val ) 
			{ 
				x = val; 
				y = val; 
				z = val;    
				return *this; 
			}

			inline bool is_zero(float epsilon) const
			{
				return( abs( x ) <= epsilon ) && ( abs( y ) <= epsilon ) && ( abs( z ) <= epsilon )  ;
			}

			inline float     length () const 
			{	
				return (float)sqrt ( x*x + y*y + z*z );	
			}

			inline float     length_sq() const 
			{	 
				return (x*x + y*y + z*z);  
			}

			inline float     dot(const vec3& v) const 
			{ 
				return x*v.x + y*v.y + z*v.z; 
			}

			inline vec3& inverse() 
			{ 
				x = -x; 
				y = -y; 
				z = -z; 
				return *this; 
			}

			inline vec3  inverted() const 
			{ 
				return vec3 (-x, -y, -z); 
			}

			inline vec3    cross (const vec3 &v) const
			{
				vec3 r;
				r.x = y * v.z - z * v.y;
				r.y = z * v.x - x * v.z;
				r.z = x * v.y - y * v.x;
				return r;
			}

 
			inline vec3&   normalize ()
			{
				if( (0.0f == x) && (0.0f == y) && (0.0f == z) ) // < без этого глючит. nan
					   return *this;

				register float fl=length();
				x /= fl;
				y /= fl;
				z /= fl;
				return *this;
			}

			//! \brief  get normalized
			inline vec3    normalized() const 
			{ 
				vec3 r = *this; 
				r.normalize(); 
				return r; 
			}

			//! \brief  Compute and return the distance between this and point.
			inline float distance(const vec3& point)   const 
			{ 
				return  sqrt( distance_sq(point) );  
			}

			//! \brief  Compute and return the square of the distance between the points and this point.
			inline float distance_sq(const vec3& point) const 
			{ 
				return vec3( *this - point ).length_sq();  
			}


			//! \brief Get the most out of each component of the absolute
			inline float     get_max_value () const 
			{   
				return scalar::max3 ( fabs (x), fabs (y), fabs (z) );   
			}

			inline vec3&   invert() 
			{
				x = -x; 
				y = -y; 
				z = -z; 
				return *this; 
			}

			inline vec3    lerp(const vec3& v, const float k) const
			{
				vec3 r;
				r.x = x + (v.x - x) * k;
				r.y = y + (v.y - y) * k;
				r.z = z + (v.z - z) * k;
				return r;
			}
			
			inline float angle (const vec3& n)
			{
				const float fdot = dot(n);
				return acos(  fdot );
			}

			//! \brief     get min component
			inline float min_value() const
			{
				float ret = x;
				if (y < ret) ret = y;
				if (z < ret) ret = z;
				return ret;
			}

			//! \brief     get max component
			inline float max_value()  const
			{
				float ret = x;
				if (ret < y) ret = y;
				if (ret < z) ret = z;
				return ret;
			}


			//! \brief   get min absolute component
			inline float minAbsVal() const
			{
				float ax=abs(x);
				float ay=abs(y);
				float az=abs(z);
				float res=ax;
				if(ay<res) res=ay;
				if(az<res) res=az;
				return res;
			}


			//! \brief      get max absolute component
			inline float maxAbsVal() const
			{
				float ax=abs(x);
				float ay=abs(y);
				float az=abs(z);
				float res=ax;
				if(ay>res) res=ay;
				if(az>res) res=az;
				return res;
			}


			vec3& maximize(const vec3& v1, const vec3& v2)
			{
				if (v1.x > v2.x) x = v1.x; else x = v2.x;
				if (v1.y > v2.y) y = v1.y; else y = v2.y;
				if (v1.z > v2.z) z = v1.z; else z = v2.z;
				return *this;
			}

			vec3& maximize(const vec3& v)
			{
				if (v.x > x) x = v.x;
				if (v.y > y) y = v.y;
				if (v.z > z) z = v.z;
				return *this;
			}

			vec3& minimize(const vec3& v1, const vec3& v2)
			{
				if (v1.x < v2.x) x = v1.x; else x = v2.x;
				if (v1.y < v2.y) y = v1.y; else y = v2.y;
				if (v1.z < v2.z) z = v1.z; else z = v2.z;
				return *this;
			}

			vec3& minimize(const vec3& v)
			{
				if (v.x < x) x = v.x;
				if (v.y < y) y = v.y;
				if (v.z < z) z = v.z;
				return *this;
			}

			inline vec3 minimized(const vec3& v) const 
			{ 
				vec3 r; r.minimize(*this, v); 
				return r; 
			}

			inline vec3 maximized(const vec3& v) const 
			{ 
				vec3 r; r.maximize(*this, v); 
				return r; 
			}



			//! \brief  set clumped
			inline vec3& clump(const vec3& vmin, const vec3& vmax)
			{
				if( x < vmin.x) x=vmin.x;  if(x > vmax.x) x=vmax.x;
				if( y < vmin.y) y=vmin.y;  if(y > vmax.y) y=vmax.y;
				if( z < vmin.z) z=vmin.z;  if(z > vmax.z) z=vmax.z;
				  return *this;
			}

			//! \brief return middle point between this and point
			inline vec3 middle(const vec3& point) const
			{
				vec3 res;
				res.x = ( x + point.x ) / 2.0f;
				res.y = ( y + point.y ) / 2.0f;
				res.z = ( z + point.z ) / 2.0f;
				return res;
			}

			//! \brief  return true if all > 0.0
			inline bool is_positive() const 
			{  
				return ( (x>=0.0f) && (y>=0.0f) && (z>=0.0f) );	
			}

			//! \brief  Transform as point
			vec3&  transform_coord(const mat44& m);

			//! \brief  Transform as normal
			vec3&  transform_normal(const mat44& m);


 
    // TODO: void transformCoordArray(float* pfOut, int strideOut, const float* pvInput, int strideInput,  const M44& m, const int num) {...}
    // TODO: void transformNormalArray(float* pfOut, int strideOut, const float* pvInput, int strideInput,  const M44& m, const int num) {...}


			/** \brief  The projection of the vector from the virtual "Looking Glass" on the screen.
					Returns a display designed according vector.	*/
			vec3 project (
				const ViewportZ& vp,
				const  mat44& Proj, 
				const  mat44& View, 
				const  mat44& World 
				)  const;



			/** \brief  Translation of the screen coordinates in the spatial coordinates
					Returns the mapped vector.  */
			vec3  unproject(
				const ViewportZ& vp,    
				const  mat44& Proj,	
				const  mat44& View,	
				const  mat44& World	
				) const	;


			friend std::ostream &operator << (std::ostream &stream, const vec3& v)
			{
				stream << v.x << " " << v.y << " " << v.z ;
				return stream;
			}

			friend std::istream &operator >> (std::istream &stream,  vec3& a)
			{
				stream >> a.x;
				stream >> a.y;
				stream >> a.z;
				return stream;
			}

			/*
			friend std::istream &operator >> (std::istream &stream, vec3& v)
			{
			stream >> v.x;
			stream >> v.y;
			stream >> v.z;
			return stream;
			}   
			friend std::istringstream &operator >> (std::istringstream &ss, vec3& v)
			{
			ss >> v.x;
			ss >> v.y;
			ss >> v.z;
			return ss;
			}  
			*/


			operator std::string() const
			{
				std::ostringstream ss;
				ss << x << " " << y << " " << z;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				std::istringstream ss(str);
				ss >> x;
				ss >> y;
				ss >> z;
				if( ss.fail() )
				{
					throw std::invalid_argument("bad input string");
				}
			}






		}; // end vec3
 

 
}