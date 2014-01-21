/**  \file
 \brief  vector 2d


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{




	//! \brief 2d-base vector. Corrected by operators epislon
	struct vec2 
	{
		union
		{
			struct
			{
				float x, y;
			};

			float floats [2];
		};

		inline vec2() 
		{ 
			x=y=0.0f; 
		}

		inline vec2(const vec2& v)      { x=v.x;  y=v.y;  }
		inline vec2(const vec2* v)      { x=v->x;  y=v->y;    }
		inline vec2(float _x, float _y)   { x=_x;   y=_y;   }
		inline vec2(const float* pfArray) { *this = pfArray; }


		#ifdef B2_MATH_H

		inline vec2(const b2Vec2& a)
		{
			x = (float)a.x;
			y = (float)a.y;
		}

		#endif 


		inline void operator = (const float* pf)
		{
			x=pf[0];
			y=pf[1];
		}

		inline bool  operator == (const vec2 & v) const
		{
			return (x == v.x && y == v.y  );
		}

		inline bool  operator != (const vec2 & v) const
		{
			return (x != v.x || y != v.y  );
		}

		inline vec2  operator + () const   { 	return *this; }
		inline vec2  operator - () const   { vec2 res; res.x = -x;	res.y = -y;	return res; }

		inline vec2  operator + (const vec2 &v) const { vec2 res = *this; res += v; return res; }
		inline vec2  operator - (const vec2 &v) const {	vec2 res = *this; res -= v; return res; }

		inline vec2  operator + (const float v) const { vec2 res = *this; res.x += v; res.x += v; return res; }
		inline vec2  operator - (const float v) const {	vec2 res = *this; res.x -= v; res.y -= v; return res; }
		
		inline vec2  operator * (float f) const         { vec2 res;	res = *this; res.x *= f;  res.y *= f; return res; }
		inline vec2  operator / (float f) const         { vec2 res;	res = *this; res.x /= f;  res.y /= f; return res; }

		inline vec2 &  operator += (const vec2 &v)  { x += v.x; y += v.y;   return *this; }
		inline vec2 &  operator -= (const vec2 &v)  { x -= v.x; y -= v.y;   return *this; }
		inline vec2 &  operator *= (float f)          { x *= f;   y *= f;	    return *this; }
		inline vec2 &  operator *= ( const vec2& v) { x *= v.x;	y *= v.y;	return *this; }

		inline vec2 &  operator /= (float f)           { x /= f;    y /= f;   return *this; }
		inline vec2 &  operator /= ( const vec2& v ) { x /= v.x;  y /= v.y; return *this; }



		inline operator  const float*() const  { return (float*)&x; }
		inline operator        float*()        { return (float*)&x; }



		inline float operator [] (size_t index) const throw(std::out_of_range)
		{
			if(index>=2) throw std::out_of_range("invalid index");
			const float* pf = &x;
			return pf[index];
		}

		inline  float& operator [] (size_t index)throw(std::out_of_range)
		{
			if(index>=2) throw std::out_of_range("invalid index");
			float* pf = &x;
			return *(pf + index);
		}


		#ifdef __D3DX9MATH_H__

		inline operator const D3DXVECTOR2*() const { return (D3DXVECTOR2*)&x; }
		inline operator   D3DXVECTOR2*()   { return (D3DXVECTOR2*)&x; }
		inline operator   D3DXVECTOR2() const  { return D3DXVECTOR2(x,y); }

		inline void operator = (const D3DXVECTOR2& v) {	x=v.x; y=v.y; }
		#endif



		#if  defined(_WINDOWS_) && defined(WIN32)
		void operator = (const POINT& p)
		{
			x = (float)p.x;
			y = (float)p.y;
		}

		#endif 


		#ifdef B2_MATH_H

		inline void operator = (const b2Vec2& a)
		{
			x = (float)a.x;
			y = (float)a.y;
		}

		inline operator  b2Vec2 () const 
		{
			b2Vec2 res;
			res.x = (float32)x;
			res.y = (float32)y;
			return res;
		}
		
		#endif


		inline void setzero() {x=y=0.0f; }
		inline bool empty() const { return  (x==0.0f) && (y==0.0f); }

		inline vec2& set     (float _x, float _y) {x=_x; y=_y;  return *this; }
		inline vec2& set_all (float val) { x=val; y=val;        return *this; }

		inline bool is_zero(float epsilon) const
		{
			return( abs( x ) <= epsilon ) && ( abs( y ) <= epsilon );
		}


		inline float     length () const  {	return (float)sqrt ( x*x + y*y );	}
		inline float     length_sq() const {	return (x*x + y*y );  }

		inline float distance(const vec2& point) const
		{
			return  sqrt( distance_sq( point ) );
		}

		inline float distance_sq(const vec2& point) const
		{
			return vec2(*this - point).length_sq();
		}


		inline vec2&   normalize()
		{
			if( (0.0f==x) && (0.0f==y) ) // < NAN
				return *this;

			register float fl=length();
			x/=fl;
			y/=fl;
			return *this;
		}

		//! \brief  return normalized
		inline vec2 normalized() const
		{
			vec2 res(*this);
			res.normalize();
			return res;
		}

		inline float  dot(const vec2& v) const
		{
			return x*v.x + y*v.y;
		}


		//! \brief Returns the z-component by taking the cross product of two 2D vectors. 
		float ccw(const vec2& v) const ;


		inline float angle (const vec2& a) const
		{
			const float fdot = x*a.x + y*a.y;
			return acos( fdot );
		}

		//! \brief  invert signs
		inline vec2& inverse()
		{
			x = -x;
			y = -y;
			return *this;
		}

		//! \brief return inverted
		inline vec2  inverted() const
		{
			return vec2 ( -x, -y );
		}


		inline float     get_max_absolute () const
		{
			if( fabs (x) >= fabs (y) )
				return x;
			else
				return y;
		}

		inline vec2    lerp(const vec2& v, const float k) const
		{
			vec2 r;
			r.x = x + (v.x - x) * k;
			r.y = y + (v.y - y) * k;
			return r;
		}


		//! \brief  get minimal component
		inline float min_value() const 
		{ 
			if(x<y) return x;   return y; 
		}

		//! \brief  get meximum component
		inline float max_value() const { if(x>y) return x;   return y; }

		//! \brief  return min vector
		inline vec2& minimize(const vec2& v)
		{
			if (v.x < x) x = v.x;
			if (v.y < y) y = v.y;
			return *this;
		}

		//! \brief  return max vector
		inline vec2& maximize(const vec2& v)
		{
			if (v.x > x) x = v.x;
			if (v.y > y) y = v.y;
			return *this;
		}

		//! \brief return min vector between this and v
		inline vec2 minimized(const vec2& v) const 
		{ 
			vec2 r = *this; 
			r.minimize(v); 
			return r; 
		}

		//! \brief return max vector between this and v
		inline vec2 maximized(const vec2& v) const 
		{ 
			vec2 r = *this; 
			r.maximize(v);
			return r; 
		}


		//! \brief  return min absolute
		inline float min_abs_value() const 
		{ 
			float ax=abs(x); 
			float ay=abs(y); 
			float res=ax; 
			if(ay<res) res=ay; 
			return res; 
		}

		//! \brief  return max absolute
		inline float max_abs_value() const 
		{ 
			float ax=abs(x); 
			float ay=abs(y); 
			float res=ax;  
			if(ay>res) res=ay; 
			return res; 
		}

		//! \brief  Clipping values ​​within vmin and vmax
		inline vec2& clump(const vec2& vmin, const vec2& vmax)
		{
			if( x < vmin.x) x=vmin.x;  if(x > vmax.x) x=vmax.x;
			if( y < vmin.y) y=vmin.y;  if(y > vmax.y) y=vmax.y;
			
			return *this;
		}

		//! \brief return middle point between this and point
		inline vec2 middle(const vec2& point) const
		{
			vec2 res;
			res.x = ( x + point.x ) / 2.0f;
			res.y = ( y + point.y ) / 2.0f;
			return res;
		}


		//!  \brief   return true if all components > 0
		inline bool is_positive() const
		{
			return ( (x>=0.0f) && (y>=0.0f) );
		}

		vec2& move( const vec2& dir, float dist)
		{
			*this += dir * dist;
			return *this;
		}

		//! \brief return moved point
		vec2 moved( const vec2& dir, float dist) const
		{
			vec2 res(*this);
			res.move(dir, dist);
			return res;
		}

		vec2 direction_to(const vec2& pnt) const 
		{
			return vec2 (pnt - *this).normalize();
		}

		friend std::ostream &operator << (std::ostream &stream, const vec2& v)
		{
			stream << v.x << " " << v.y ;
			return stream;
		}

		operator std::string() const
		{
			std::ostringstream ss;
			ss << x << " " << y;
			return ss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream ss(str);
			ss >> x;
			ss >> y;
			if( ss.fail() ) throw std::invalid_argument("bad input string");
		}


		friend std::istream &operator >> (std::istream &stream, vec2& v)
		{
			stream >> v.x;
			stream >> v.y;
			return stream;
		}


		friend std::istringstream &operator >> (std::istringstream &ss, vec2& v)
		{
			ss >> v.x;
			ss >> v.y;
			return ss;
		}



	};


}
