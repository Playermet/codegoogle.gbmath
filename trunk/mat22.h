/**  \file
 \brief standard float 2x2 matrix .


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	//! \brief matrix 2x2
	struct mat22
	{
		union
		{
			struct 
			{

			   float _11,  _12,
					 _21,  _22;
			};

			float floats [2][2];

			float array [4];
		};

		inline mat22() 
		{

		}

		inline mat22(const mat22& m) 
		{ 
			*this=m; 
		}

		inline mat22(float _11_, float _12_, float _21_, float _22_) 
		{
			_11=_11_; 
			_12=_12_; 
			_21=_21_; 
			_22=_22_;  
		}

		inline mat22(const float* pfArray) 
		{ 
			*this = pfArray; 
		}

		inline operator  const float*() const  { return &_11; }
		inline operator        float*()        { return &_11; }


		inline mat22&  operator =  ( const mat22& m)
		{
			floats [0][0] = m.floats [0][0];
			floats [0][1] = m.floats [0][1];
			floats [1][0] = m.floats [1][0];
			floats [1][1] = m.floats [1][1];
			return *this;
		}

		inline void operator = (const float* pfArray)
		{
			_11 = pfArray[0];
			_12 = pfArray[1];
			_21 = pfArray[2];
			_22 = pfArray[3];
		}

		//! \brief  In the main diagonal set f rest neutral earthing.
		inline mat22&  operator =  ( float f) 
		{ 	
			floats [0][1] = floats [1][0] = 0.0; floats [0][0] = floats [1][1] = f; 
		}

		//!	 \brief  invert all values	
		inline mat22 operator - () const 
		{ 
			mat22 r = *this; 
			r._11 = -r._11; 
			r._12 = -r._12; 
			r._21 = -r._21; 
			r._22 = -r._22; 
			return r; 
		}

		inline mat22&  operator += ( const mat22& m)
		{
			floats [0][0] += m.floats [0][0];
			floats [0][1] += m.floats [0][1];
			floats [1][0] += m.floats [1][0];
			floats [1][1] += m.floats [1][1];
			return *this;
		}

		inline mat22&  operator -= ( const mat22& m)
		{
			floats [0][0] -= m.floats [0][0];
			floats [0][1] -= m.floats [0][1];
			floats [1][0] -= m.floats [1][0];
			floats [1][1] -= m.floats [1][1];
			return *this;
		}

		inline mat22&  operator *= ( const mat22& m)
		{
			mat22 c  = *this ;
			floats [0][0] = c.floats [0][0]*m.floats [0][0] + c.floats [0][1]*m.floats [1][0];
			floats [0][1] = c.floats [0][0]*m.floats [0][1] + c.floats [0][1]*m.floats [1][1];
			floats [1][0] = c.floats [1][0]*m.floats [0][0] + c.floats [1][1]*m.floats [1][0];
			floats [1][1] = c.floats [1][0]*m.floats [0][1] + c.floats [1][1]*m.floats [1][1];
			return *this;
		}

		inline mat22&  operator *= ( float f)
		{
			floats [0][0] *= f;
			floats [0][1] *= f;
			floats [1][0] *= f;
			floats [1][1] *= f;
			return *this;
		}

		inline mat22&  operator /= ( float f)
		{
			floats [0][0] /= f;
			floats [0][1] /= f;
			floats [1][0] /= f;
			floats [1][1] /= f;
			return *this;
		}

		inline mat22 operator + ( const mat22& m) const
		{
			mat22 res;
			res.floats[0][0] = floats [0][0] + m.floats [0][0];
			res.floats[0][1] = floats [0][1] + m.floats [0][1];
			res.floats[1][0] = floats [1][0] + m.floats [1][0];
			res.floats[1][1] = floats [1][1] + m.floats [1][1];
			return res;
		}

		inline mat22 operator - ( const mat22& m) const
		{
			  mat22 res;
			res.floats [0][0] = floats [0][0] - m.floats [0][0];
			res.floats [0][1] = floats [0][1] - m.floats [0][1];
			res.floats [1][0] = floats [1][0] - m.floats [1][0];
			res.floats [1][1] = floats [1][1] - m.floats [1][1];
			return res;
		}

		inline mat22 operator * ( const mat22& m) const
		{
			mat22 res;
			res.floats[0][0] = floats[0][0]*m.floats[0][0]+floats[0][1]*m.floats[1][0];
			res.floats[0][1] = floats[0][0]*m.floats[0][1]+floats[0][1]*m.floats[1][1];
			res.floats[1][0] = floats[1][0]*m.floats[0][0]+floats[1][1]*m.floats[1][0];
			res.floats[1][1] = floats[1][0]*m.floats[0][1]+floats[1][1]*m.floats[1][1];
			return res;
		}

		inline mat22 operator * ( float f ) const
		{
			  mat22 res;
			res.floats[0][0] = floats[0][0] * f;
			res.floats[0][1] = floats[0][1] * f;
			res.floats[1][0] = floats[1][0] * f;
			res.floats[1][1] = floats[1][1] * f;
			return  res;
		}

		inline vec2  operator * ( const vec2& v ) const
		{
			vec2 res;
			res.x =  floats [0][0]*v.x + floats [0][1]*v.y ;
			res.y =  floats [1][0]*v.x + floats [1][1]*v.y ;
			return res;
		}

		inline vec2 row(size_t index)
		{
		   if(index>=2) throw (index) ;
		   vec2 res;

		   switch(index)
		   {
			case 0: { res.x=_11; res.y=_12; } break;
			case 1: { res.x=_21; res.y=_22; } break;
			default: {}
		   }
		   return res;
		}

		inline vec2 column(size_t index)
		{
			if(index>=2) throw (index) ;

			vec2 res;
			switch(index)
			{
				case 0: { res.x=_11; res.y=_21; } break;
				case 1: { res.x=_12; res.y=_22; } break;
				default: {}
			}
			return res;
		}


		inline bool empty() const 
		{
			return _11==0.0f && _12==0.0f && _21==0.0f && _22==0.0f; 
		}

		inline mat22&  setzero()     
		{ 
			_11=_12=_21=_22=0.0f; 
			return *this; 
		}
		
		inline void reset() { setIdentity(); }

		inline mat22&  setIdentity() 
		{	
			_11=1.0f; _12=0.0f;	_21=0.0f; _22=1.0f;	
			return *this; 
		}

		inline mat22&  transpone()   
		{  
			register float f=_12; _12=_21; _21=f;  
			return *this; 
		}

		inline bool isIdentity() const
		{
			return floats[0][0] == 1.0f && floats[0][1] == 0.0f &&
				   floats[1][0] == 0.0f && floats[1][1] == 1.0f;
		}

		inline float determinant () const 
		{ 
			return floats [0][0] * floats [1][1] -  floats [0][1] * floats [1][0];	
		}

		inline mat22&  invert ()
		{
			float det =   determinant();
			mat22 m;
			m.floats [0][0] =  floats [1][1] / det;
			m.floats [0][1] = -floats [0][1] / det;
			m.floats [1][0] = -floats [1][0] / det;
			m.floats [1][1] =  floats [0][0] / det;
			*this = m;
			return *this;
		}

		//! \brief  return inverted
		inline mat22   inverted () const 
		{ 
			mat22 r(*this); 
			r.invert(); 
			return r;  
		}

		inline mat22&  setScaling ( const vec2& v )
		{
			   floats [0][0] = v.x;
			   floats [1][1] = v.y;
			   floats [0][1] = floats [1][0] = 0.0;
			   return *this;
		}

		inline mat22&   setScaling (float x, float y)
		{
			floats [0][0] = x;
			floats [1][1] = y;
				floats [0][1] = floats [1][0] = 0.0;
				return *this;
		}

		mat22&  setRotation ( float angle )
		{
			float    cosine, sine;
			scalar::sincos(angle , sine , cosine );
			floats [0][0] = cosine;
			floats [0][1] = sine;
			floats [1][0] = -sine;
			floats [1][1] = cosine;
			return *this;
		}


		inline mat22&  setMirrorX () 
		{ 
			setIdentity();  
			floats [0][0] = -1.0; 
			return *this; 
		}

		inline mat22&  setMirrorY () 
		{ 
			setIdentity();  
			floats [1][1] = -1.0; 
			return *this; 
		}


	};
 

}

