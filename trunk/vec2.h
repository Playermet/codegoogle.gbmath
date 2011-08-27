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
		struct vec2 {

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

				//! \brief Присваивание из float-массива
				inline void operator = (const float* pf)
				{
					x=pf[0];
					y=pf[1];
				}

				inline bool  operator == (const vec2 & v) const
				{
					return (x == v.x && y == v.y  );
				}


				// new
				//friend bool operator == (const vec2& v1, const vec2& v2)
				//{
				//	
				//}

				inline bool  operator != (const vec2 & v) const
				{
					return (x != v.x || y != v.y  );
				}

				inline vec2  operator + () const   { 	return *this; }
				inline vec2  operator - () const   { vec2 res; res.x = -x;	res.y = -y;	return res; }

				inline vec2  operator + (const vec2 &v) const { vec2 res;	res = *this; res += v; return res; }
				inline vec2  operator - (const vec2 &v) const {	vec2 res;	res = *this; res -= v; return res; }
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
#else

			/*
#ifdef   __GB_TYPES_H__
	 void operator = (const POINT& p)
	 {
		 x = (float)p.x;
		 y = (float)p.y;
	 }
#endif
*/

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
					if( (0.0f==x) && (0.0f==y) ) // < без этого глючит. nan
						return *this;

					register float fl=length();
					x/=fl;
					y/=fl;
					return *this;
				}

				//! \brief  Вернуть нормализованый
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


				//! \brief Returns the z-component by taking the cross product of two 2D vectors.  ПРОВЕРЕНА!
				float ccw(const vec2& v) const ;


				//! \brief  Инвертировать (поменять знаки компонентов).
				inline vec2& inverse()
				{
					x = -x;
					y = -y;
					return *this;
				}

				//! \brief Вернуть вектор, с противоположными знаками
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

  			   // inline vec2&   invert() {x=-x; y=-y;  return *this; }

				inline vec2    lerp(const vec2& v, const float k) const
				{
					vec2 r;
					r.x = x + (v.x - x) * k;
					r.y = y + (v.y - y) * k;
					return r;
				}



				//! \brief  Получить минимальную компоненту
				inline float min_value() const 
				{ 
					if(x<y) return x;   return y; 
				}

				//! \brief  Получить Максимальную компоненту
				inline float max_value() const { if(x>y) return x;   return y; }

				////! \brief  Сравнить два вектора v1 и v2 и присвоить минимальный
				//inline vec2& minimize(const vec2& v1, const vec2& v2)
				//{
				//	if (v1.x < v2.x) x = v1.x; else  x = v2.x;
				//	if (v1.y < v2.y) y = v1.y; else  y = v2.y;
				//	return *this;
				//}

				//! \brief  Сравнить вектор v и собственное значение и присвоить минимальный
				inline vec2& minimize(const vec2& v)
				{
					if (v.x < x) x = v.x;
					if (v.y < y) y = v.y;
					return *this;
				}

				////! \brief  Сравнить два вектора v1 и v2 и присвоить максимальный
				//inline vec2& maximize(const vec2& v1, const vec2& v2)
				//{
				//	if (v1.x > v2.x) x = v1.x; else  x = v2.x;
				//	if (v1.y > v2.y) y = v1.y; else  y = v2.y;
				//	return *this;
				//}

				//! \brief  Сравнить вектор v и собственное значение и присвоить максимальный
				inline vec2& maximize(const vec2& v)
				{
					if (v.x > x) x = v.x;
					if (v.y > y) y = v.y;
					return *this;
				}

				//! \brief Вернуть минимальный вектор между this и v
				inline vec2 minimized(const vec2& v) const 
				{ 
					vec2 r = *this; 
					r.minimize(v); 
					return r; 
				}

				//! \brief Вернуть максимальный вектор между this и v
				inline vec2 maximized(const vec2& v) const 
				{ 
					vec2 r = *this; 
					r.maximize(v);
					return r; 
				}


				//! \brief  вычислить мин. абсолютное значение компонент.
				inline float min_abs_value() const 
				{ 
					float ax=abs(x); 
					float ay=abs(y); 
					float res=ax; 
					if(ay<res) res=ay; 
					return res; 
				}

				//! \brief  вычислить макс. абсолютное значение компонент
				inline float max_abs_value() const 
				{ 
					float ax=abs(x); 
					float ay=abs(y); 
					float res=ax;  
					if(ay>res) res=ay; 
					return res; 
				}

/***********
				//! \brief  вычисление миним, компоненты
				inline float min_abs_value() const 
				{
					if( abs(x) < abs(y) ) return x; 
					return y;	
				}

				//! \brief  вычисление. макс компоненты
				inline float max_abs_value() const 
				{ 
					if( abs(x) > abs(y) ) return x; 
					return y;	
				}
****************/

				//! \brief  Отсечение значений в пределах vmin и vmax
				inline void clump(const vec2& vmin, const vec2& vmax)
				{
					if( x < vmin.x) x=vmin.x;  if(x > vmax.x) x=vmax.x;
					if( y < vmin.y) y=vmin.y;  if(y > vmax.y) y=vmax.y;
				}

				//! \brief Вернуть среднюю точку между this и point
				inline vec2 middle(const vec2& point) const
				{
					vec2 res;
					res.x = ( x + point.x ) / 2.0f;
					res.y = ( y + point.y ) / 2.0f;
					return res;
				}


				//!  \brief   Вернёт true если все компоненты положительные.
				inline bool is_positive() const
				{
					return ( (x>=0.0f) && (y>=0.0f) );
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





 /*

			#if defined(_MSC_VER)
			#pragma warning( push )
			#pragma warning( disable : 4290 )
			#endif

			friend std::stringstream &operator >> (std::stringstream &stream, color3<T>& c) throw (std::invalid_argument)
			{
				stream >> c.r;
				stream >> c.g;
				stream >> c.b;

				if(stream.fail())
				{
					throw std::invalid_argument("cast error");
				}

				return stream;
			}



			#if defined(_MSC_VER)
			#pragma warning( pop )
			#endif


*/



			};



 
}