/**  \file
 \brief  direction / normal in 3-dimensional space.
Higher level than a vector. Always normalized.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{
 

		/** \brief  direction / normal in 3-dimensional space.
Higher level than a vector. Always normalized. */
		class normal3 {
		private:
			float _x;
			float _y;
			float _z;

			inline void __normalize()
			{
#pragma message("ks777: need insert code check zero " __FILE__)
				register float len = sqrt ( _x*_x + _y*_y + _z*_z );
				_x/=len;
				_y/=len;
				_z/=len;
			}

		public:


			//! \brief //! \brief  by default normal [0 , 0 , 1]
			inline normal3() 
			{ 
				_x = 0.0f; 
				_y = 0.0f; 
				_z = 1.0f;  
			}
			
			inline normal3(const normal3& n) 
			{ 
				_x=n._x; 
				_y=n._y; 
				_z=n._z; 
			}
			
			inline normal3(float x, float y, float z) 
			{ 
				_x=x; 
				_y=y; 
				_z=z; 
				__normalize(); 
			}
			
			inline normal3(const  vec3& v) 
			{ 
				*this = v;  
			}


			inline operator  const float*() const  { return &_x; };
			//inline operator        float*()        { return &_x; };

			inline float x() const { return _x; }
			inline float y() const { return _y; }
			inline float z() const { return _z; }

			inline void operator = (const  vec3& vn)	
			{ 
				_x = vn.x; 
				_y = vn.y; 
				_z = vn.z; 
				__normalize(); 
			}

			inline operator  vec3() const 
			{ 
				return  vec3 (_x,_y,_z);  
			}

			inline operator  const vec3*() const 
			{ 
				return (vec3*)&_x; 
			}

			//! \brief  compute angle between normals .
			inline float angle (const normal3& n)
			{
				const float fdot = _x*n._x + _y*n._y + _z*n._z;
                return acos(  fdot );
			}

			 //! \brief Set the direction between points and pntDest pntSrc.
			normal3& setDirectionBetweenPoints(const point3& pntSrc, const point3& pntDest);

			//! \brief Change in the opposite direction
			inline void negate() 
			{
				_x = -_x; 
				_y = -_y;
				_z = -_z; 
			}

			//! \brief  Трансформировать нормаль по матрице m
			normal3& transform(const  mat44& m)
			{
			    vec3 v = *this;
			   v.transform_normal(m);
			   _x = v.x;
			   _y = v.y;
			   _z = v.z;
				return *this;
			}


#ifdef _D3D9_H_
			inline operator D3DVECTOR*() { return (D3DVECTOR*)&_x; }
			inline operator const D3DVECTOR*() const { return (D3DVECTOR*)&_x; }
			inline operator D3DVECTOR() const  { D3DVECTOR r; r.x=_x; r.y=_y; r.z=_z; return r;  }
			inline void operator = (const D3DVECTOR& v) {	_x=v.x; _y=v.y; _z=v.z; __normalize(); }
#endif


#ifdef __D3DX9MATH_H__
			inline operator const D3DXVECTOR3*() const { return (D3DXVECTOR3*)&_x; }

#endif


		};

}
