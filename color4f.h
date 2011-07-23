﻿/**  \file 
 \brief яяяяяяяя
 
 
*/

#pragma once

/*
#include "color4.h"
#include "color_typedef.h" 
*/

namespace gb
{

	namespace fmath
	{



		//!   \brief   Класс  Четырёхкомпонентный стандартный цвет по float . 
		struct color4f : public color4<float> {
		public:
			//union 
			//{
				// struct 
				//{   
				//	float r, g, b, a;  
				//};

				// float floats[4];
			//};  

			inline color4f() 
			{ 
				r = g = b = a = 0.0f;
			}
 
			inline color4f(const color4f& col) 
			{ 
				r = col.r; 
				g = col.g; 
				b = col.b; 
				a = col.a;  
			}

			inline color4f(float _r, float _g, float _b) 
			{
				r = _r; 
				g = _g; 
				b = _b; 
				a = 1.0f; 
			} 

			inline color4f(float _r, float _g, float _b, float _a) 
			{
				r = _r; 
				g = _g; 
				b = _b; 
				a = _a; 
			}

			 /****************
			//!   \brief Конструктор по байтам ( 0->0.0f   ,  255->1.0f ) 
			inline color4f( byte_t _r,  byte_t _g,  byte_t _b,  byte_t _a ) 
			{
				r=(float)_r/255.5f; 
				g=(float)_g/255.0f; 
				b=(float)_b/255.0f; 
				a=(float)_a/255.0f; 
			}
			*********************/


			/**********************
			//! \brief установка значений из байт с переводом в float формат (0.0f ... 1.0f) 
			inline color4f& set_bytes(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) 
			{ 
				r=(float)_r/255.5f; 
				g=(float)_g/255.0f; 
				b=(float)_b/255.0f;
				a=(float)_a/255.0f; 
				return *this;
			}
			 ************************/


			/** \brief Построение цвета  из целочисленого 4-x  байтового цвета.  */
			void operator =  (const color4_32 val) ;

			/** \brief Установить белый цвет  */

			inline color4f& set_white(float _a=1.0f) {r=g=b=1.0f; a=_a;  return *this; }
			/** \brief Установить чёрный цвет  */
			inline color4f& set_black(float _a=1.0f) {r=g=b=0.0f; a=_a;  return *this; }

			operator color4_32() const ;

#pragma message ( "!!TEMP COMMENTED "  __FILE__ )
			/******************
			inline void  operator = (const color_rgba_s& color) 
			{ 
			r =  ( (float)color.r ) / 255.0f; 
			g =  ( (float)color.g ) / 255.0f; 
			b =  ( (float)color.b ) / 255.0f; 
			a =  ( (float)color.a ) / 255.0f;  
			}


			inline operator color_rgba_s() const   
			{  
			color_rgba_s res;   
			res.r=(uint8_t)(r * 255.0f); 
			res.g=(uint8_t)(g * 255.0f); 
			res.b=(uint8_t)(b * 255.0f); 
			res.a=(uint8_t)(a * 255.0f); 
			return res;  
			}
			***************/


#pragma message ( "!!TEMP COMMENTED "  __FILE__ )
			// inline void  operator = (const color_rgb24_s color)    
			// { 
			//	  r=((float)color.r) / 255.0f;      
			//     g=((float)color.g) / 255.0f;     
			//	  b=((float)color.b) / 255.0f;  
			// };

#pragma  message (  "!!TEMP COMMENTED "  __FILE__    )
			/* inline  operator color_rgb24_s() const   
			{ 
			color_rgb24_s res;   
			res.r=  (uint8_t)(r * 255.0f); 
			res.g=  (uint8_t)(g * 255.0f); 
			res.b=  (uint8_t)(b * 255.0f);  
			return res; 
			};*/

			// /** \brief сложение  */
			// inline color4f& add(const color4f& color)     
			// {
				// r+=color.r; 
				// g+=color.g; 
				// b+=color.b; 
				// a+=color.a;
				// return *this;
			// };

			// /** \brief сложение только rgb. альфа не изменятеся.  */
			// inline color4f& addRGB(const color4f& color)  
			// {
				// r+=color.r; 
				// g+=color.g; 
				// b+=color.b;
				// return *this;
			// };

			// /** \brief Вычитание  */
			// inline color4f& sub(const color4f& color)     
			// {
				// r-=color.r; 
				// g-=color.g; 
				// b-=color.b; 
				// a-=color.a; 
				// return *this;
			// };

			// /** \brief Вычитание только rgb. альфа не изменятеся.   */
			// inline color4f& subRGB(const color4f& color)  
			// {
				// r-=color.r; 
				// g-=color.g; 
				// b-=color.b; 
				// return *this;
			// };

			// /** \brief Масштабирование   
			// inline color4f& scale(float s)                
			// {
				// r*=s; 
				// g*=s; 
				// b*=s; 
				// a*=s; 
				// return *this;
			// };	*/




			///** \brief  установить по  c1 и c2 по  линейной  интерполяции. */
			//inline color4f& setLerp(const color4f& c1, const color4f& c2, float k) 
			//{
			//	r  = c1.r + k * (c2.r - c1.r);
			//	g  = c1.g + k * (c2.g - c1.g);
			//	b  = c1.b + k * (c2.b - c1.b);
			//	a  = c1.a + k * (c2.a - c1.a);
			//	return *this;
			//};
			
			

			///** \brief  установить: линейная интерполяция между this и color. */
			//inline color4f& setLerp(const color4f& color, float k) 
			//{
			//	r = color.r + k * ( r - color.r);
			//	g = color.g + k * ( g - color.g);
			//	b = color.b + k * ( b - color.b);
			//	a = color.a + k * ( a - color.a);
			//	return *this;
			//};


			///** \brief изменить насыщенность . Альфа игнорируется. */
			//inline color4f& setAdjustSaturation(const color4f& cSrc, float s)  
			//{
			//	const float grey  = cSrc.r * 0.2125f  +  cSrc.g * 0.7154f  +  cSrc.b * 0.0721f;
			//	r  = grey + s * (cSrc.r - grey);
			//	g  = grey + s * (cSrc.g - grey);
			//	b  = grey + s * (cSrc.b - grey);
			//	return *this;
			//};


			// /** \brief изменить насыщенность */
			// inline color4f& adjustSaturation( float s )  
			// {
				// const float grey  =  r * 0.2125f +  g * 0.7154f +  b * 0.0721f;
				// r  = grey + s * ( r - grey );
				// g  = grey + s * ( g - grey );
				// b  = grey + s * ( b - grey );
				// return *this;
			// };

 
			// /** \brief Масштабирование цвета. Изменение яркости. */
			// inline color4f& modulate(const Color3f& color) 
			// {
			//   r *= color.r;
			//   g *= color.g; 
			//   b *= color.b; 
			//return *this;
			// };


			///** \brief   Негатив. */
			//inline color4f& negative(bool bIncludeAlpha=true) 
			//{
			//	r = 1.0f - r;
			//	g = 1.0f - g;
			//	b = 1.0f - b;
			//	if(bIncludeAlpha) a = 1.0f - a;
			//	return *this;
			//}

			//inline color4f getNegatived() const 
			//{
			//	color4f res(*this);
			//	res.negative();
			//	return res;
			//}

			///** \brief  Установить  негативный. */
			//inline color4f& setNegative(const color4f& color) 
			//{
			//	r = 1.0f - color.r;
			//	g = 1.0f - color.g;
			//	b = 1.0f - color.b;
			//	a = 1.0f - color.a; 
			//	return *this;
			//};


			///** \brief получить негативный цвет */
			//inline color4f getNegative() const 
			//{
			//	color4f res(this); 
			//	res.negative();
			//	return res;  
			//};

			// /** \brief изменить контраст */
			// inline color4f& adjust_contrast(float s) 
			// {
				// r = 0.5f + s * ( r - 0.5f);
				// g = 0.5f + s * ( g - 0.5f);
				// b = 0.5f + s * ( b - 0.5f);
				// return *this;
			// }


			// /** \brief получить цвет с изменённым контрастом */
			// inline color4f adjusted_contrast(float s) const 
			// {
				// color4f res(*this);
				// res.adjustContrast(s);
				// return res;
			// }


			///** \brief Отсечение значений в пределах 0.0 ... 1.0  */
			//inline color4f saturate() {
			//	if(r>1.0f) r=1.0f;   if(r<0.0f) r=0.0f;
			//	if(g>1.0f) g=1.0f;   if(g<0.0f) g=0.0f; 
			//	if(b>1.0f) b=1.0f;   if(b<0.0f) b=0.0f;
			//	if(a>1.0f) a=1.0f;   if(a<0.0f) a=0.0f; 
			//	return *this;
			//};

			///** \brief Получить сатурированый цвет из this . */
			//inline color4f getSaturated() const 
			//{ 
			//	color4f res(*this); 
			//	res.saturate(); 
			//	return res;  
			//};

			///** \brief Установить как средний цвет между this и col  . */
			//inline color4f& setAverage(const color4f& col) 
			//{
			//	r = (r+col.r) / 2.0f;
			//	g = (g+col.g) / 2.0f;
			//	b = (b+col.b) / 2.0f;
			//	a = (a+col.a) / 2.0f;
			//	return *this;
			//};

			///** \brief Установить как средний цвет между  c1 и с2 . */
			//inline color4f& setAverage( const color4f& c1 , const color4f& c2 ) 
			//{
			//	r = (c2.r+c1.r) / 2.0f;
			//	g = (c2.g+c1.g) / 2.0f;
			//	b = (c2.b+c1.b) / 2.0f;
			//	a = (c2.a+c1.a) / 2.0f;
			//	return *this;
			//};

			///** \brief Получить как средний цвет между this и col  . */
			//inline color4f getAveraged(const color4f& col) const
			//{
			//	color4f res;
			//	res.setAverage(*this , col);
			//	return res;
			//};

			//inline  operator float*()                { return &r; };
			//inline  operator const float*() const    { return &r; };

			// inline const float* getFloats() const    { return &r; };
			// inline int size()                        { return sizeof(float) * 4; };

			// inline void operator = (const color4f& color) 
			// { 
			//    r = color.r; 
			//	 g = color.g; 
			//	 b = color.b; 
			//	 a = color.a;  
			//  }



			// inline void operator = (const color4f_s& color) 
			// { 
			//   r = color.r; 
			//	g = color.g; 
			//	b = color.b; 
			//	a = color.a;  
			// }

			//---------- operators  --------------------------
			//
			//
/*

			inline bool operator == (const color4f& c) const { return (r==c.r) && (g==c.g) && (b==c.b) && (a==c.a);  };
			inline bool operator != (const color4f& c) const { return (r!=c.r) && (g!=c.g) && (b!=c.b) && (a!=c.a);  };

			inline color4f& operator *= (const float s)    { r*=s; b*=s; g*=s; a*=s; return *this; };
			inline color4f& operator *= (const color4f& c) { r*=c.r; b*=c.b; g*=c.g; a*=c.a; return *this; };

			inline color4f& operator /= (const float s)    { r/=s; b/=s; g/=s; a/=s; return *this; };
			inline color4f& operator /= (const color4f& c) { r/=c.r; b/=c.b; g/=c.g; a/=c.a; return *this; };

			inline color4f& operator += (const float s)    { r+=s; b+=s; g+=s; a+=s; return *this; };
			inline color4f& operator += (const color4f& c) { r+=c.r; b+=c.b; g+=c.g; a+=c.a; return *this; };

			inline color4f& operator -= (const float s)    { r-=s; b-=s; g-=s; a-=s; return *this; };
			inline color4f& operator -= (const color4f& c) { r-=c.r; b-=c.b; g-=c.g; a-=c.a; return *this; };

			inline color4f  operator + (const color4f& color) const  
			{ 
				color4f res;
				res.r=r+color.r; 
				res.g=g+color.g; 
				res.b=b+color.b; 
				res.a=a+color.a;  
				return res;   
			};

			inline color4f  operator + (const float f) const  
			{ 
				color4f res;
				res.r=r+f; 
				res.g=g+f; 
				res.b=b+f; 
				res.a=a+f;  
				return res;   
			};


			inline color4f   operator - (const color4f& color) const  
			{ 
				color4f res;
				res.r=r-color.r; 
				res.g=g-color.g; 
				res.b=b-color.b; 
				res.a=a-color.a;  
				return res;   
			};

			inline color4f   operator - (const float f) const  
			{ 
				color4f res;
				res.r=r-f; 
				res.g=g-f; 
				res.b=b-f; 
				res.a=a-f;  
				return res;   
			};


			color4f   operator / (const color4f& color) const  
			{ 
				color4f res;
				res.r = r / color.r; 
				res.g = g / color.g; 
				res.b = b / color.b; 
				res.a = a / color.a;  
				return res;   
			};

			color4f   operator / (const float f) const  
			{ 
				color4f res;
				res.r = r / f; 
				res.g = g / f; 
				res.b = b / f; 
				res.a = a / f;  
				return res;   
			};


			color4f   operator * (const color4f& color) const  
			{ 
				color4f res;
				res.r = r*color.r; 
				res.g = g*color.g; 
				res.b = b*color.b; 
				res.a = a*color.a;  
				return res;   
			};

			color4f   operator * (const float f) const  
			{ 
				color4f res;
				res.r = r*f; 
				res.g = g*f; 
				res.b = b*f; 
				res.a = a*f;  
				return res;   
			};
*/

			//
			//
			// --------- end operators ----------------




// #pragma warning(push)
// #pragma warning (disable : 4996)


			// /** \brief Конвертация в строку.  Разделитель:  пробел */
			// const char* tostr() const {
				// static char ss[32];
				// ss[0] = 0;
				// sprintf(ss, "%f  %f  %f  %f", r, g, b, a );
				// return ss;
			// };

			// /** \brief   Чтение значений из строки разд. пробелами  */
			// bool fromstr(const char*  s) {
				// const int SCRES = sscanf(s, "%f  %f  %f  %f", &r, &g, &b, &a );
				// if( SCRES != 4  ) return false;
				// return true;
			// };


// #pragma warning(pop)



#ifdef _D3D9_H_
			inline void operator = (const D3DCOLORVALUE& val) { r=val.r; g=val.g; b=val.b; a=val.a; }
			inline operator const D3DCOLORVALUE*() const { return (D3DCOLORVALUE*)&r; }
			inline operator       D3DCOLORVALUE () const { D3DCOLORVALUE res;  res.a=a; res.r=r; res.g=g; res.b=b; return res; }
#endif   // GB_D3D9

#ifdef __D3DX9MATH_H__
			inline void operator = (const D3DXCOLOR& c) {r=c.r; g=c.g; b=c.b; a=c.a; }
			inline operator const D3DXCOLOR*() const { return (D3DXCOLOR*)&r; }
			inline operator       D3DXCOLOR () const { return D3DXCOLOR(r,g,b,a); }
#endif


		}; 
		// end class color4f
 


	}
}