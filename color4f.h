/**  \file
 \brief Standard four-color float

 
*/

#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{



	//!   \brief  Standard four-color float .
	struct color4f   
	{
	public:
	
		union
		{
			struct
			{
				float r, g, b, a;
			};

			 float floats[4];
		};

		static color4f MakeWhite()
		{
			return color4f(1.0f , 1.0f , 1.0f , 1.0f);
		}

		static color4f MakeBlack()
		{
			return color4f(0.0f , 0.0f , 0.0f , 1.0f);
		}

		static color4f MakeRed()
		{
			return color4f(1.0f , 0.0f , 0.0f , 1.0f);
		}

		static color4f MakeGreen()
		{
			return color4f(0.0f , 1.0f , 0.0f , 1.0f);
		}

		static color4f MakeBlue()
		{
			return color4f(0.0f , 0.0f , 1.0f , 1.0f);
		}

		static color4f MakeAqua()
		{
			return color4f(0.0f,   1.0f,   1.0f, 1.0f );
		}			

		static color4f MakeYellow()
		{
			return color4f(  1.0f, 1.0f, 0.0f,  1.0f  );
		}

		static color4f MakeViolet()
		{
			return color4f(  0.309804f, 0.184314f,  0.309804f,  1.0f);
		}

		static color4f MakePink()
		{
			return color4f(  0.737255f,  0.560784f,  0.560784f,  1.0f  );
		}

		static color4f MakeMaroon()
		{
			return color4f( 0.556863f,  0.137255f,  0.419608f,  1.0f);
		}

		static color4f MakeCoral()
		{
			return color4f( 1.0f,       0.498039f,  0.0f,       1.0f );
		}

		static color4f MakeGray()
		{
			return color4f( 0.752941f,  0.752941f,  0.752941f,  1.0f );
		}






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

		color4f(int _r, int _g, int _b)
		{
			r = (float)_r;
			g = (float)_g;
			b = (float)_b;
			a = 1.0f;
		}




		//!   \brief construct bytes( 0->0.0f   ,  255->1.0f )
		inline color4f( byte_t _r,  byte_t _g,  byte_t _b,  byte_t _a )
		{
			r = (float)_r/255.5f;
			g = (float)_g/255.0f;
			b = (float)_b/255.0f;
			a = (float)_a/255.0f;
		}

		inline  operator float*()                { return &r; }
		inline  operator const float*() const    { return &r; }



		inline unsigned int to_uint32_rgba() const
		{ 

			unsigned int nr = ( ((unsigned int)( r*255.0f )<<24) | 0x00ffffff );
			nr ^= 0x00ffffff;

			unsigned int ng = ( ((unsigned int)( g*255.0f )<<16) | 0xff00ffff );
			ng ^= 0xff00ffff;

			unsigned int nb = ( ((unsigned int)( b*255.0f )<< 8) | 0xffff00ff );
			nb ^= 0xffff00ff;

			unsigned int na = ( ((unsigned int)( a*255.0f )    ) | 0xffffff00 );
			na ^= 0xffffff00;

			return nr | ng | nb | na ;
		}


		inline unsigned int to_uint32_argb() const   
		{
			unsigned int nr = ( ((unsigned int)( a*255.0f )<<24) | 0x00ffffff );
			nr ^= 0x00ffffff;

			unsigned int ng = ( ((unsigned int)( r*255.0f )<<16) | 0xff00ffff );
			ng ^= 0xff00ffff;

			unsigned int nb = ( ((unsigned int)( g*255.0f )<< 8) | 0xffff00ff );
			nb ^= 0xffff00ff;

			unsigned int na = ( ((unsigned int)( b*255.0f )    ) | 0xffffff00 );
			na ^= 0xffffff00;

			return nr | ng | nb | na ;
		}

		void from_uint32_argb(unsigned int val)
		{
			{
				unsigned int temp = val | 0x00ffffff;
				temp ^= 0x00ffffff;
				temp = temp >> 24;
				a = ((float)temp) / 255.0f ;
			}

			{
				unsigned int temp = val | 0xff00ffff;
				temp ^= 0xff00ffff;
				temp = temp >> 16;
				r = ((float)temp) / 255.0f ;
			}


			{
				unsigned int temp = val | 0xffff00ff;
				temp ^= 0xffff00ff;
				temp = temp >> 8;
				g = ((float)temp) / 255.0f ;
			}				

			{
				unsigned int temp = val | 0xffffff00;
				temp ^= 0xffffff00;
				temp = temp >> 0;
				b = ((float)temp) / 255.0f ;
			}

		}



		inline unsigned int to_uint32_as_d3d9color() const 
		{
			return to_uint32_argb();
		}


		inline void from_uint32_as_d3d9color(unsigned int val) 
		{
			from_uint32_argb( val );
		}



		/** \brief   Построение цвета  из целочисленого 4-x  байтового цвета.  */
		void operator =  (const color4_32 val) ;


		//! \brief set as white color
		inline color4f& set_white(float _a=1.0f) 
		{
			r = g = b = 1.0f; 
			a = _a;  
			return *this; 
		}

		//! \brief  set as black color
		inline color4f& set_black(float _a=1.0f) 
		{
			r = g = b = 0.0f; 
			a = _a;  
			return *this; 
		}

		operator color4_32() const ;

//#pragma message ( "!!TEMP COMMENTED "  __FILE__ )
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


//#pragma message ( "!!TEMP COMMENTED "  __FILE__ )
		// inline void  operator = (const color_rgb24_s color)
		// {
		//	  r=((float)color.r) / 255.0f;
		//     g=((float)color.g) / 255.0f;
		//	  b=((float)color.b) / 255.0f;
		// };

//#pragma  message (  "!!TEMP COMMENTED "  __FILE__    )
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

 
		 inline void operator = (const color4f& color)
		 {
		     r = color.r;
			 g = color.g;
			 b = color.b;
			 a = color.a;
		 }

 

		//---------- operators  --------------------------
		//
		//

 

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
		}


		inline color4f   operator - (const color4f& color) const
		{
			color4f res;
			res.r=r-color.r;
			res.g=g-color.g;
			res.b=b-color.b;
			res.a=a-color.a;
			return res;
		}

		inline color4f   operator - (const float f) const
		{
			color4f res;
			res.r=r-f;
			res.g=g-f;
			res.b=b-f;
			res.a=a-f;
			return res;
		}


		color4f   operator / (const color4f& color) const
		{
			color4f res;
			res.r = r / color.r;
			res.g = g / color.g;
			res.b = b / color.b;
			res.a = a / color.a;
			return res;
		}

		color4f   operator / (const float f) const
		{
			color4f res;
			res.r = r / f;
			res.g = g / f;
			res.b = b / f;
			res.a = a / f;
			return res;
		}


		color4f   operator * (const color4f& color) const
		{
			color4f res;
			res.r = r*color.r;
			res.g = g*color.g;
			res.b = b*color.b;
			res.a = a*color.a;
			return res;
		}

		color4f   operator * (const float f) const
		{
			color4f res;
			res.r = r*f;
			res.g = g*f;
			res.b = b*f;
			res.a = a*f;
			return res;
		}
 


		//
		//
		// --------- end operators ----------------



 

#ifdef _D3D9_H_
		inline void operator = (const D3DCOLORVALUE& val) { r=val.r; g=val.g; b=val.b; a=val.a; }
		inline operator const D3DCOLORVALUE*() const { return (D3DCOLORVALUE*)&r; }
		inline operator       D3DCOLORVALUE () const { D3DCOLORVALUE res;  res.a=a; res.r=r; res.g=g; res.b=b; return res; }
#endif 


#ifdef __D3DX9MATH_H__
		inline void operator = (const D3DXCOLOR& c) {r=c.r; g=c.g; b=c.b; a=c.a; }
		inline operator const D3DXCOLOR*() const { return (D3DXCOLOR*)&r; }
		inline operator       D3DXCOLOR () const { return D3DXCOLOR(r,g,b,a); }
#endif



		operator std::string() const
		{
			std::ostringstream oss;
			oss << r << " " << g << " " << b << " " << a;
			return oss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream ss(str);
			ss >> r;
			ss >> g;
			ss >> b;
			ss >> a;
			if( ss.fail() )
			{
				throw std::invalid_argument("bad input string");
			}
		}

		//-----------------------------------------------------------------




		//! \brief  test each component of zero
		inline bool empty() const
		{
			const float _e = float();
			return (r == _e) && (g == _e) && (b == _e) && (a == _e);
		}

		//! \brief  set to zero each component.
		inline void setzero()
		{
			r = g = b = a = float();
		}



		//! \brief    linear interpolation between this and the color on k.
		inline color4f lerp(const color4f& color, const float k) const
		{
			color4f res;
			res.r = color.r + k * ( r - color.r );
			res.g = color.g + k * ( g - color.g );
			res.b = color.b + k * ( b - color.b );
			res.a = color.a + k * ( a - color.a );
			return res;
		}


		//! \brief Scaling of color. Changing the brightness.
		inline color4f& modulate(const color4f& color)
		{
			r *= color.r;
			g *= color.g;
			b *= color.b;
			a *= color.a;
			return *this;
		}

		//! \brief get color scale. Changing the brightness.
		inline color4f modulated(const color4f& color) const
		{
			color4f res;
			res.r = r * color.r;
			res.g = g * color.g;
			res.b = b * color.b;
			res.a = a * color.a;
			return *this;
		}


		inline color4f& negative()
		{
			r = 1 - r;
			g = 1 - g;
			b = 1 - b;
			a = 1 - a;
			return *this;
		}

		//! \brief   a negative.
		inline color4f negatived() const
		{
			color4f res (*this);
			res.negative();
			return res;
		}


		//! \brief Pruning values ​​within 0.0 ... 1.0
		inline color4f& saturate()
		{
			if(r>1) r=1;   if(r<0) r=0;
			if(g>1) g=1;   if(g<0) g=0;
			if(b>1) b=1;   if(b<0) b=0;
			if(a>1) a=1;   if(a<0) a=0;
			return *this;
		}

		//! \brief get clipping values ​​within 0.0 ... 1.0
		inline color4f saturated() const
		{
			color4f res (*this);
			res.saturate();
			return res;
		}

		//! \brief Set as the average color between this and col.
		inline color4f& average(const color4f& c)
		{
			const float _two = (float)2;
			r = (r + c.r) / _two;
			g = (g + c.g) / _two;
			b = (b + c.b) / _two;
			a = (a + c.a) / _two;
			return *this;
		}

		//! \brief  get   as the average color between this and col.
		inline color4f averaged(const color4f& col) const
		{
			color4f res = *this;
			res.average(col);
			return res;
		}


		//! \brief Addition of only rgb. alpha does not change.
		inline color4f& add_rgb(const float k)
		{
			r += k;
			g += k;
			b += k;
			return *this;
		}

		//! \brief scaling of only rgb. alpha does not change.
		inline color4f& scale_rgb(const float k)
		{
			r *= k;
			g *= k;
			b *= k;
			return *this;
		}



		//! \brief change contrast
		inline color4f& adjust_contrast(const float k)
		{
			const float _half = (float)0.5;
			r =  _half + k * ( r - _half);
			g =  _half + k * ( g - _half );
			b =  _half + k * ( b - _half );
			return *this;
		}


		//! \brief  get a change contrast
		inline color4f adjusted_contrast(const float k) const
		{
			color4f res(*this);
			res.adjust_contrast(k);
			return res;
		}



		//! \brief change the saturation
		inline color4f& adjust_saturation( const float k )
		{
			const float grey  =  r * (float)0.2125 +  g * (float)0.7154 +  b * (float)0.0721 ;
			r  = grey + k * ( k - grey );
			g  = grey + k * ( k - grey );
			b  = grey + k * ( k - grey );
			return *this;
		}

		inline color4f adjusted_saturation( const float k ) const
		{
			color4f res (*this);
			res.adjust_saturation( k );
			return res;
		}

 

		friend std::ostream& operator << (std::ostream &stream, const color4f& c)
		{
			stream << c.r << " " << c.g << " " << c.b << " " << c.a ;
			return stream;
		}

		friend std::istream& operator >> (std::istream &stream,   color4f& c)
		{
			stream >> c.r; 
			stream >> c.g; 
			stream >> c.b; 
			stream >> c.a;
			return stream;
		}

		friend std::ostringstream &operator << (std::ostringstream &stream, const color4f& c)
		{
			stream << c.r << " " << c.g << " " << c.b << " " << c.a ;
			return stream;
		}

		#if defined(_MSC_VER)
		#pragma warning( push )
		#pragma warning( disable : 4290 )
		#endif

		friend std::stringstream &operator >> (std::stringstream &stream, color4f& c) throw (std::invalid_argument)
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
