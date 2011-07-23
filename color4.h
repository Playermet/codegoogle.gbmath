/**  \file 
 \brief яяяяяяяя
 
 
*/

#pragma once


#ifndef __GB_FMATH_H__
#error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif

//#include "..\base\Types.h"
//#include "color_functions.h"
//#include "color3.h"

//#include <stdio.h>
//#include <stdlib.h>

#include <float.h>
#include <math.h>
#include <string>
#include <sstream>
#include <istream>

#include <assert.h>




namespace gb
{

 namespace fmath
 {
 

	 template <typename T>
	 struct color4
	 {
		 T   r, g, b, a;


		 color4()
		 {
			r = g = b = a = T();
		 }

		color4<T> (const color4<T>& c)
		{
			r = c.r;
			g = c.g;
			b = c.b;
			a = c.a;
		}

		inline color4<T>( T _r , T _g , T _b ) 
		{
			r = _r; 
			g = _g; 
			b = _b; 
			a = 1;
		} 

		inline color4<T>( T _r , T _g , T _b , T _a )
		{
			r = _r; 
			g = _g; 
			b = _b; 
			a = _a; 
		} 



		 inline  operator T*()                { return &r; }
		 inline  operator const T*() const    { return &r; }



		 inline bool operator == (const color4<T>& c) const 
		 { 
			 return (r==c.r) && (g==c.g) && (b==c.b) && (a==c.a);  
		 }

		 inline bool operator != (const color4<T>& c) const 
		 { 
			 return (r!=c.r) && (g!=c.g) && (b!=c.b) && (a!=c.a);  
		 }

		 inline color4<T>& operator *= (const T s)    
		 { 
			 r*=s; 
			 b*=s; 
			 g*=s; 
			 a*=s; 
			 return *this; 
		 }

		 inline color4<T>& operator *= (const color4<T>& c) 
		 { 
			 r *= c.r; 
			 b *= c.b; 
			 g *= c.g; 
			 a *= c.a; 
			 return *this; 
		 }

		 inline color4<T>& operator /= (const T s)    
		 { 
			 r /= s; 
			 b /= s; 
			 g /= s; 
			 a /= s; 
			 return *this; 
		 }

		 inline color4<T>& operator /= (const color4<T>& c) 
		 { 
			 r /= c.r; 
			 b /= c.b; 
			 g /= c.g; 
			 a /= c.a; 
			 return *this; 
		 }

		 inline color4<T>& operator += (const T s)    
		 { 
			 r += s; 
			 b += s; 
			 g += s; 
			 a += s; 
			 return *this; 
		 }

		 inline color4<T>& operator += (const color4<T>& c) 
		 { 
			 r += c.r; 
			 b += c.b; 
			 g += c.g; 
			 a += c.a; 
			 return *this; 
		 }

		 inline color4<T>& operator -= (const T s)    
		 { 
			 r -= s; 
			 b -= s; 
			 g -= s; 
			 a -= s; 
			 return *this; 
		 }

		 inline color4<T>& operator -= (const color4<T>& c) 
		 { 
			 r -= c.r; 
			 b -= c.b; 
			 g -= c.g; 
			 a -= c.a; 
			 return *this; 
		 }

		 inline color4<T>  operator + (const color4<T>& c) const  
		 { 
			 color4<T> res;
			 res.r = r + c.r; 
			 res.g = g + c.g; 
			 res.b = b + c.b; 
			 res.a = a + c.a;  
			 return res;   
		 }

		 inline color4<T>  operator + (const T f) const  
		 { 
			 color4<T> res;
			 res.r = r + f; 
			 res.g = g + f; 
			 res.b = b + f; 
			 res.a = a + f;  
			 return res;   
		 }


		 inline color4<T>   operator - (const color4<T>& color) const  
		 { 
			 Color4f res;
			 res.r=r-color.r; 
			 res.g=g-color.g; 
			 res.b=b-color.b; 
			 res.a=a-color.a;  
			 return res;   
		 }

		 inline color4<T>   operator - (const T f) const  
		 { 
			 color4<T> res;
			 res.r = r-f; 
			 res.g = g-f; 
			 res.b = b-f; 
			 res.a = a-f;  
			 return res;   
		 }


		 inline color4<T>   operator / (const color4<T>& color) const  
		 { 
			 color4<T> res;
			 res.r = r / color.r; 
			 res.g = g / color.g; 
			 res.b = b / color.b; 
			 res.a = a / color.a;  
			 return res;   
		 }

		 inline color4<T>   operator / (const T f) const  
		 { 
			 color4<T> res;
			 res.r = r / f; 
			 res.g = g / f; 
			 res.b = b / f; 
			 res.a = a / f;  
			 return res;   
		 }


		 color4<T>   operator * (const color4<T>& color) const  
		 { 
			 color4<T> res;
			 res.r = r*color.r; 
			 res.g = g*color.g; 
			 res.b = b*color.b; 
			 res.a = a*color.a;  
			 return res;   
		 }

		 color4<T>   operator * (const T f) const  
		 { 
			 color4<T> res;
			 res.r = r * f; 
			 res.g = g * f; 
			 res.b = b * f; 
			 res.a = a * f;  
			 return res;   
		 }


		 inline void init( T _r, T _g, T _b,  T _a )
		 {
			 r = _r;
			 g = _g;
			 b = _b;
			 a = _a;
		 }


		 //! \brief  проверка  каждый компонент ноль 
		 inline bool empty() const 
		 { 
			 const T _e = T();
			 return (r == _e) && (g == _e) && (b == _e) && (a == _e); 
		 }

		 //! \brief  занулить каждый компонент. 
		 inline void setzero() 
		 { 
			 r = g = b = a = T(); 
		 }

 

		 //! \brief    линейная интерполяция между this и color по коэф. k. 
		 inline color4<T> lerp(const color4<T>& color, const T k) const
		 {
			 color4<T> res;
			 res.r = color.r + k * ( r - color.r );
			 res.g = color.g + k * ( g - color.g );
			 res.b = color.b + k * ( b - color.b );
			 res.a = color.a + k * ( a - color.a );
			 return res;
		 }


		 //! \brief Масштабирование цвета. Изменение яркости. 
		 inline color4<T>& modulate(const color4<T>& color) 
		 {
			 r *= color.r;
			 g *= color.g; 
			 b *= color.b; 
			 a *= color.a; 
			 return *this;
		 }

		 //! \brief вернутб масштабирование цвета. Изменение яркости. 
		 inline color4<T> modulated(const color4<T>& color) const
		 {
			 color4<T> res;
			 res.r = r * color.r;
			 res.g = g * color.g; 
			 res.b = b * color.b; 
			 res.a = a * color.a; 
			 return *this;
		 }

		 //! \brief   Негатив. 
		 inline color4<T>& negative() 
		 {
			 r = 1 - r;
			 g = 1 - g;
			 b = 1 - b;
			 a = 1 - a;
			 return *this;
		 }

		 //! \brief   Негатив. 
		 inline color4<T> negatived() const 
		 {
			 color4<T> res (*this);
			 res.negative();
			 return res;
		 }


		 //! \brief Отсечение значений в пределах 0.0 ... 1.0  
		 inline color4<T>& saturate() 
		 {
			if(r>1) r=1;   if(r<0) r=0;
			if(g>1) g=1;   if(g<0) g=0; 
			if(b>1) b=1;   if(b<0) b=0;
			if(a>1) a=1;   if(a<0) a=0; 
			return *this;
		 }

		 //! \brief Отсечение значений в пределах 0.0 ... 1.0  
		 inline color4<T> saturated() const 
		 {
			 color4<T> res (*this);
			 res.saturate();
			 return res;
		 }

		 //! \brief Установить как средний цвет между this и col .
		 inline color4<T>& average(const color4<T>& c) 
		 {
			const T _two = (T)2;
			r = (r + c.r) / _two;
			g = (g + c.g) / _two;
			b = (b + c.b) / _two;
			a = (a + c.a) / _two;
			return *this;
		 }

		 //! \brief как средний цвет между this и col .
		 inline color4<T> averaged(const color4<T>& col) const
		 {
			 color4<T> res = *this;
			 res.average(col);
			 return res;
		 }


		 //! \brief Сложение только rgb. альфа не изменятеся.   
		 inline color4<T>& add_rgb(const T k)  
		 {
			 r += k; 
			 g += k; 
			 b += k; 
			 return *this;
		 }
 
 		  //! \brief Масштабирование только rgb. альфа не изменятеся.
		 inline color4<T>& scale_rgb(const T k)  
		 {
			 r *= k; 
			 g *= k; 
			 b *= k; 
			 return *this;
		 }

 

		 //! \brief изменить контраст 
		 inline color4<T>& adjust_contrast(const T k) 
		 {
			 const T _half = (T)0.5;
			 r =  _half + k * ( r - _half);
			 g =  _half + k * ( g - _half );
			 b =  _half + k * ( b - _half );
			 return *this;
		 }


		 //! \brief получить цвет с изменённым контрастом 
		 inline color4<T> adjusted_contrast(const T k) const 
		 {
			 color4<T> res(*this);
			 res.adjust_contrast(k);
			 return res;
		 }

 

		 //! \brief изменить насыщенность 
		 inline color4<T>& adjust_saturation( const T k )  
		 {
			 const T grey  =  r * (T)0.2125 +  g * (T)0.7154 +  b * (T)0.0721 ;
			 r  = grey + k * ( k - grey );
			 g  = grey + k * ( k - grey );
			 b  = grey + k * ( k - grey );
			 return *this;
		 }

		inline color4<T> adjusted_saturation( const T k ) const 
		{
			color4<T> res (*this);
			res.adjust_saturation( k );
			return res;
		}

		//! \brief Установить белый цвет  
		inline color4<T>& set_white( const T _a = (T)1 ) 
		{
			r = g = b = (T)1; 
			a =_a;  
			return *this; 
		}

		//! \brief Установить чёрный цвет  
		inline color4<T>& set_black( const T _a = (T)1 ) 
		{
			r = g = b = (T)0; 
			a=_a;  
			return *this; 
		}


 
		 friend std::ostream &operator << (std::ostream &stream, const color4<T>& c)
		 {
			 stream << c.r << " " << c.g << " " << c.b << " " << c.a ;
			 return stream;
		 }

		 friend std::istream &operator >> (std::istream &stream,   color4<T>& c)
		 {
			 stream >> c.r >> " " >> c.g >> " " >> c.b >> " " >> c.a ;
			 return stream;
		 }
		 
		 friend std::ostringstream &operator << (std::ostringstream &stream, const color4<T>& c)
		 {
			 stream << c.r << " " << c.g << " " << c.b << " " << c.a ;
			 return stream;
		 }

		#if defined(_MSC_VER)
		#pragma warning( push )
		#pragma warning( disable : 4290 )
		#endif

		 friend std::stringstream &operator >> (std::stringstream &stream, color4<T>& c) throw (std::invalid_argument)
		 {
			stream >> c.r; 
			stream >> c.g; 
			stream >> c.b; 
			stream >> c.a;
 
			if(stream.fail())
			{
				throw std::invalid_argument("cast error");
			}

			return stream;
		 }


		#if defined(_MSC_VER)
		#pragma warning( pop )
		#endif
		 

		 




	 };
 
 
 }
}
