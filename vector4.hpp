// vector4.hpp

#ifndef __VECTOR4_H__
#define __VECTOR4_H__

#pragma once


namespace gb
{

	namespace fmath
	{
	
		template <typename T>
		struct vector4 {
 
			T  x, y, z, w;
 
			inline vector4<T> ()
			{ 
				x = y = z = w = T(); 
			}

			inline vector4<T> (const vector4<T>& a)
			{
				x = a.x;
				y = a.y;
				z = a.z;
				w = a.w;
			}
			
			inline vector4<T> (const vector2<T>& v, const T _z,  const T _w)
			{
				x = a.x; 
				y = a.y; 
				z = _z; 
				w = _w;
			}			

			inline vector4<T> (const vector3<T>& v, const T _w)
			{
				x = v.x;
				y = v.y;
				z = v.z;
				w =_w;
			}



			inline vector4<T> ( T _x, T _y, T _z, T _w )
			{
				x=_x;
				y=_y;
				z=_z;
				w=_w;
			}
 

			inline void operator = (const T* _array)
			{
				x = _array[0];
				y = _array[1];
				z = _array[2];
				w = _array[3];
			}
 
					 
			inline bool  operator == (const vector4<T> &v) const
			{
				return (x == v.x && y == v.y && z == v.z && w == v.w);
			}
			
			inline bool  operator != (const vector4<T> &v) const
			{
				return (x != v.x || y != v.y || z != v.z || w != v.w);
			}
 
			inline vector4<T>  operator + () const
			{
				return *this;
			}
			
			inline vector4<T>  operator - () const
			{
				return vector4<T>( -x, -y, -z, -w );
			}
			

			inline vector4<T>  operator + (const vector4<T> &v) const
			{
				vector4<T> res(*this);
				res += v;
				return res; 
			}
			
			inline vector4<T>  operator - (const vector4<T> &v) const
			{
				return vector4<T> res(*this);
				res -= v;
				return res; 
			}
			
			inline vector4<T>  operator * (const T value) const
			{
				return vector4<T> res ( x * value, y * value, z * value, w * value );	
			}
			
			inline vector4<T>  operator / (const T value) const
			{
				return vector4<T>( x/f, y/f, z/f, w/f );
			}

			inline vector4<T> &  operator += (const vector4<T> &v)
			{
				x += v.x;
				y += v.y;
				z += v.z;
				w += v.w;
				return *this; 
			}
			
			inline vector4<T> &  operator -= (const vector4<T> &v)
			{
				x -= v.x;
				y -= v.y;
				z -= v.z;
				w -= v.w;
				return *this; 
			}
			
			inline vector4<T> &  operator *= (const T value)
			{
				x *= value;	
				y *= value;	
				z *= value;	
				w *= value;
				return *this;
			}

			inline vector4<T> &  operator /= (const T value)
			{
				x /= value;	
				y /= value;	
				z /= value;	
				w /= value;
				return *this;
			}

			inline operator  const T*() const  { return &x; }
			inline operator        T*()        { return &x; }
 


			inline T operator [] (const size_t index) const
			{
				if(index>3)
				{
					throw std::bad_index("invalid index");
				}
				
				const T* _array = &x;
				return _array[index];
			}

			inline  T& operator [] (const size_t index) 
			{
				if(index>3)
				{
					throw std::bad_index("invalid index");
				}
				
				T* _array = &x;
				return *(_array + index);
			}




			// #ifdef __D3DX9MATH_H__
			// inline operator D3DXVECTOR4*() { return (D3DXVECTOR4*)&x; }
			// inline operator const D3DXVECTOR4*() const { return (D3DXVECTOR4*)&x; }
			// inline operator D3DXVECTOR4() const  {  return D3DXVECTOR4(x,y,z,w); }
		   	// inline void operator = (const D3DXVECTOR4& v) {	x=v.x; y=v.y; z=v.z; w=v.w; }	
			// #endif	


				
			
			//! \brief Обнулить все компоненты  old:  setzero
		    inline void set_zero()
			{ 
				x = y = z = w = T();
			}
			
			//! проверить равны ли все компоненты нулю   old :  empty
			inline bool is_zero() const
			{
				const T _ZERO = T();
				return (x == _ZERO) && (y == _ZERO) && (z == _ZERO) && (w == _ZERO); 
			}

			inline vector4<T>& set ( const T _x,  const T _y,  const T _z,  const T _w ) 
			{ 
				x = _x; 
				y = _y; 
				z = _z; 
				w = _w; 
				return *this; 
			}
 
			//! \brief  Все ли компоненты нулевые по эпсилону.    old:  isZero
			inline bool is_zero(const T epsilon) const
			{
				return( abs( x ) <= epsilon ) && ( abs( y ) <= epsilon ) && ( abs( z ) <= epsilon ) && ( abs( y ) <= epsilon );
			}

			//! \brief  получить длинну
			inline T length () const
			{
				return (T) sqrt( x*x + y*y + z*z + w*w );
			}
			
			//! \brief  получить квадрат длинны  old:  lengthSq
			inline T length_sq() const
			{
				return ( x*x + y*y + z*z + w*w );
			}

			//! \brief   Вернуть скалярное произведение с вектором v
			inline T   dot (const vector4<T>& a) const
			{
				return x * a.x + y * a.y + z * a.z + w * a.w;
			}

			
#pragma message ("KS777: MATH::vector4<T> >> NEED CHECK CROSS METHOD !!!"  __FILE__)

			//! \brief Получить векторное (перекрестное)  произведение с вектором v.
			inline vector4<T>  cross ( const vector4<T> & v) const
			{
				vector4<T> r;
				r.x = ( z * v.w - w * v.z) * y + ( w * v.y - y * v.w) * z + ( y * v.z - z * v.y) * w;
				r.y = ( w * v.z - z * v.w) * x + ( x * v.w - w * v.x) * z + ( z * v.x - x * v.z) * w;
				r.z = ( y * v.w - w * v.y) * x + ( w * v.x - x * v.w) * y + ( x * v.y - y * v.x) * w;
				r.w = ( z * v.y - y * v.z) * x + ( x * v.z - z * v.x) * y + ( y * v.x - x * v.y) * z;
				return r;
			}


			/*************************************************
			// НЕПРАВИЛЬНО !!!!
			void cross( const vector4<T>& U, const vector4<T>& V, const vector4<T>& W )   
			{
				assert(false && "bad code !");

				T a = V.x*W.y - V.y*W.x;
				T b = V.x*W.z - V.z*W.x;
				T c = V.x*W.w - V.w*W.x;
				T d = V.y*W.z - V.z*W.y;
				T e = V.y*W.w - V.w*W.y;
				T f = V.z*W.w - V.w*W.z;

				vector4<T> Out;
				Out.x = f*U.y - e*U.z + d*U.w ;
				Out.y = f*U.x + c*U.z - b*U.w ; // no valid
				Out.z = e*U.x - c*U.y + a*U.w ;
				Out.w = d*U.x + b*U.y - a*U.z ; // no valid

				*this = Out;
			}
			******************************************************/
			
			

			//! \brief  Инвертировать.
			inline vector4<T>&   invert()
			{ 
				x = -x; 
				y = -y; 
				z = -z; 
				w = -w; 
				return *this; 
			}
			
			//! \brief  Вернуть инвертированый.
			inline vector4<T>    inverted() const 
			{
				return vector4<T> ( -x, -y, -z, -w );
			}

			//! \brief  Вернуть вектор по линейной интерполяции между this и v  по коэффициенту k
			inline vector4<T>    lerp(const vector4<T>& v, const T k) 
			{
				vector4<T> r;
				r.x = x + (v.x - x) * k;
				r.y = y + (v.y - y) * k;
				r.z = z + (v.z - z) * k;
				r.w = w + (v.w - w) * k;
				return r;			
			}



			//! \brief  Получить минимальную компоненту.  old: minval
			inline T min_value() const 
			{ 	  
				T res = x;
				if(y < res) res = y;
				if(z < res) res = z;
				if(w < res) res = w;
				return res;
			}

			//! \brief Получить максимальную компоненту.  old: maxval
			inline T max_value() const
			{   
				T res = x;
				if(res < y) res = y;
				if(res < z) res = z;
				if(res < w) res = w;
				return res;
			}	
 
			/** \brief  вычисл. минимальной абсолютной компоненты.   old:  minAbsVal   */
			inline T min_abs_value() const 
			{ 
				T ax = abs(x); 
				T ay = abs(y); 
				T az = abs(z); 
				T aw = abs(w);
				T res = ax;    
				if(ay < res) res = ay; 
				if(az < res) res = az; 
				if(aw < res) res = aw; 
				return res; 
			}

			/** \brief  вычисл. максимальной абсолютной компоненты.    old:  maxAbsVal    */
			inline T max_abs_value() const 
			{ 
				T ax = abs(x); 
				T ay = abs(y); 
				T az = abs(z); 
				T aw = abs(w);
				T res = ax;
				if(ay > res) res = ay; 
				if(az > res) res = az;	 
				if(aw > res) res = aw;	
				return res;	
			}


			//! \brief Выполнить отсечение значений в диапазоне между vmin и vmax
			vector4<T>&  clump(const vector4<T>& vmin, const vector4<T>& vmax) 
			{
				if( x < vmin.x) x = vmin.x;  if(x > vmax.x) x = vmax.x;
				if( y < vmin.y) y = vmin.y;  if(y > vmax.y) y = vmax.y;
				if( z < vmin.z) z = vmin.z;  if(z > vmax.z) z = vmax.z;
				if( w < vmin.w) w = vmin.w;  if(w > vmax.w) w = vmax.w;
				return *this;
			}
 

			friend std::ostream &operator << (std::ostream &stream, const vector4<T>& v)
			{
				stream << v.x << " " << v.y << " " << v.z << " " << v.w;
				return stream;
			}



			friend std::istream &operator >> (std::istream &stream, vector4<T>& v)
			{
				stream >> v.x;
				stream >> v.y;
				stream >> v.z;
				stream >> v.w;
				return stream;
			}

			friend std::istringstream &operator >> (std::istringstream &stream, vector4<T>& v) throw (std::invalid_argument)
			{
				stream >> v.x; 
				stream >> v.y;
				stream >> v.z;
				stream >> v.w;

				if(stream.fail())
				{
					throw std::invalid_argument("cast error");
				}

				return stream;
			}



 
 

		}; 
 
 
	
	}

}





#endif // #ifdef __VECTOR4_H__