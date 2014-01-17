/**  \file
 \brief  standard float 3x3 matrix .


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{

	//! \brief matrix 3x3
	struct mat33
	{
		union
		{
			struct 
			{
			   float _11,  _12,  _13,
					 _21,  _22,  _23,
					 _31,  _32,  _33;
			};
			   float floats [3][3];
			   float array [9];
		};

		inline mat33() {}

		inline mat33(const mat33& m)
		{ 
			*this = m; 
		}

		inline mat33( float _11_, float _12_, float _13_,
					  float _21_, float _22_, float _23_,
					  float _31_, float _32_, float _33_ ) :

							_11( _11_ ), _12( _12_ ), _13( _13_ ),
							_21( _21_ ), _22( _22_ ), _23( _23_ ),
							_31( _31_ ), _32( _32_ ), _33( _33_ ) {}

		inline mat33(const float* pfArray) 
		{ 
			*this = pfArray; 
		}

		inline operator  const float*() const  { return &_11; }
		inline operator        float*()        { return &_11; }

		inline mat33&  operator =  ( const mat22& m)
		{
			floats [0][0] = m.floats [0][0];
			floats [0][1] = m.floats [0][1];
			floats [1][0] = m.floats [1][0];
			floats [1][1] = m.floats [1][1];
			return *this;
		}

		inline void operator = (const float* pfArray)
		{
			_11=  pfArray[0]; _12= pfArray[1];  _13= pfArray[2];
			_21=  pfArray[3]; _22= pfArray[4];  _23= pfArray[5];
			_31=  pfArray[6]; _32= pfArray[7];  _33= pfArray[8];
		}

		mat33& operator = ( float a );

		//!  \brief Contacting mark all the elements of	
		inline mat33 operator - () const
		{
			mat33 r = *this;
			r._11=-r._11;   r._12=-r._12;   r._13=-r._13;
			r._21=-r._21;   r._22=-r._22;   r._23=-r._23;
			r._31=-r._31;   r._32=-r._32;   r._33=-r._33;
			return r;
		}

		mat33 operator + ( const mat33& m ) const;
		mat33 operator - ( const mat33& m ) const;

		mat33&   operator *= ( float f );
		mat33&   operator *= ( const mat33& m );
		mat33&   operator /= ( float f );

		mat33&   operator += ( const mat33& a );
		mat33&   operator -= ( const mat33& a );

		mat33  operator * ( const mat33& m) const;
		mat33  operator * (  float f ) const;

		vec3   operator * ( const vec3& v ) const;

		//!	 \brief Access to the rows of the index. 
		inline const vec3 operator [] ( size_t index ) const
		{
		   if( index >= 3 ) throw(index);
		   return reinterpret_cast<const vec3*>(this)[index];
		}
 

		//!	 \brief Conversion to 2x2 matrix
		inline operator mat22()
		{
			return mat22( _11, _12,
						  _21, _22 );
		}

		inline bool empty() const
		{
			return _11==0.0f && _12==0.0f && _13==0.0f
				&& _21==0.0f && _22==0.0f && _23==0.0f
				&& _31==0.0f && _32==0.0f && _33==0.0f;
		}

		//! \brief   set all to zero
		inline void setzero() 
		{ 
			_11=_12=_13=_21=_22=_23=_31=_32=_33=0.0f; 
		}

		//! \brief  reset. set to identity.
		inline void setIdentity()
		{
			_11=1.0f; _12=0.0f; _13=0.0f;
			_21=0.0f; _22=1.0f; _23=0.0f;
			_31=0.0f; _32=0.0f; _33=1.0f;
		}

		inline bool isIdentity() const
		{
			return floats[0][0] == 1.0f && floats[0][1] == 0.0f && floats[0][2] == 0.0f &&
				   floats[1][0] == 0.0f && floats[1][1] == 1.0f && floats[1][2] == 0.0f &&
				   floats[2][0] == 0.0f && floats[2][1] == 0.0f && floats[2][2] == 1.0f ;
		}

		//! \brief reset. set to identity.  same as setIdentity.
		inline void reset() 
		{ 
			setIdentity(); 
		}

		 //! \brief  transpose the matrix
		inline mat33&   transpone()
		{
			 register float t;
			t=_12;  _12=_21; _21=t;
			t=_13;  _13=_31; _31=t;
			t=_23;  _23=_32; _32=t;
			  return *this;
		}

		//! \brief    return transposed the matrix
		inline mat33 getTransponed() const
		{
			mat33 res = *this;
			res.transpone();
			return res;
		}

		float  determinant () const;

		mat33& invert ();
		mat33  inverted() const { mat33 res; res=*this; res.invert(); return res; }

		mat33& setScaling ( float x, float y, float z );
		mat33& setScaling ( const vec3& v );

		mat33& setRotationX ( float angle );
		mat33& setRotationY ( float angle );
		mat33& setRotationZ ( float angle );

		mat33& setRotation ( const vec3& v, float angle );

		mat33&  setMirrorX();
		mat33&  setMirrorY();
		mat33&  setMirrorZ();


		friend std::ostream& operator << (std::ostream& os, const mat33& a)
		{
			os << a._11 << " " << a._12 << " " << a._13 << "\n";
			os << a._21 << " " << a._22 << " " << a._23 << "\n";
			os << a._31 << " " << a._32 << " " << a._33 << "\n";
			return os;
		}



	};
 
}
