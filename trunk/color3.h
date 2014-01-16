/** \file
 \brief template color3
*/

#pragma once
 
#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{


	
	template <typename T>
	//! \brief  template color3
	struct color3
	{
		T   r, g, b;


		color3()
		{
			r = g = b = T();
		}

		color3<T> (const color3<T>& c)
		{
			r = c.r;
			g = c.g;
			b = c.b;
		}

		inline color3<T>( T _r , T _g , T _b )
		{
			r = _r;
			g = _g;
			b = _b;
		}

		inline  operator T*()                { return &r; }
		inline  operator const T*() const    { return &r; }



		inline bool operator == (const color3<T>& c) const
		{
			return (r==c.r) && (g==c.g) && (b==c.b) ;
		}

		inline bool operator != (const color3<T>& c) const
		{
			return (r!=c.r) && (g!=c.g) && (b!=c.b) ;
		}

		inline color3<T>& operator *= (const T s)
		{
			r*=s;
			b*=s;
			g*=s;
			return *this;
		}

		inline color3<T>& operator *= (const color3<T>& c)
		{
			r *= c.r;
			b *= c.b;
			g *= c.g;
			return *this;
		}

		inline color3<T>& operator /= (const T s)
		{
			r /= s;
			b /= s;
			g /= s;
			return *this;
		}

		inline color3<T>& operator /= (const color3<T>& c)
		{
			r /= c.r;
			b /= c.b;
			g /= c.g;
			return *this;
		}

		inline color3<T>& operator += (const T s)
		{
			r += s;
			b += s;
			g += s;
			return *this;
		}

		inline color3<T>& operator += (const color3<T>& c)
		{
			r += c.r;
			b += c.b;
			g += c.g;
			return *this;
		}

		inline color3<T>& operator -= (const T s)
		{
			r -= s;
			b -= s;
			g -= s;
			return *this;
		}

		inline color3<T>& operator -= (const color3<T>& c)
		{
			r -= c.r;
			b -= c.b;
			g -= c.g;
			return *this;
		}

		inline color3<T>  operator + (const color3<T>& c) const
		{
			color3<T> res;
			res.r = r + c.r;
			res.g = g + c.g;
			res.b = b + c.b;
			return res;
		}

		inline color3<T>  operator + (const T f) const
		{
			color3<T> res;
			res.r = r + f;
			res.g = g + f;
			res.b = b + f;
			return res;
		}


		inline color3<T>   operator - (const color3<T>& c) const
		{
			color3f res;
			res.r = r - c.r;
			res.g = g - c.g;
			res.b = b - c.b;
			return res;
		}

		inline color3<T>   operator - (const T f) const
		{
			color3<T> res;
			res.r = r - f;
			res.g = g - f;
			res.b = b - f;
			return res;
		}


		inline color3<T>   operator / (const color3<T>& c) const
		{
			color3<T> res;
			res.r = r / c.r;
			res.g = g / c.g;
			res.b = b / c.b;
			return res;
		}

		inline color3<T>   operator / (const T f) const
		{
			color3<T> res;
			res.r = r / f;
			res.g = g / f;
			res.b = b / f;
			return res;
		}


		color3<T>   operator * (const color3<T>& c) const
		{
			color3<T> res;
			res.r = r * c.r;
			res.g = g * c.g;
			res.b = b * c.b;
			return res;
		}

		color3<T>   operator * (const T f) const
		{
			color3<T> res;
			res.r = r * f;
			res.g = g * f;
			res.b = b * f;
			return res;
		}


		inline void init( T _r, T _g, T _b )
		{
			r = _r;
			g = _g;
			b = _b;
		}


		//! \brief  checked each component zero:  
		inline bool empty() const
		{
			const T _e = T();
			return (r == _e) && (g == _e) && (b == _e) && (a == _e);
		}

		inline void setzero()
		{
			r = g = b = a = T();
		}

		//! \brief    linear interpolation between this and the color on the coefficients. k.
		inline color3<T> lerp(const color3<T>& c, const T k) const
		{
			color3<T> res;
			res.r = c.r + k * ( r - c.r );
			res.g = c.g + k * ( g - c.g );
			res.b = c.b + k * ( b - c.b );
			res.a = c.a + k * ( a - c.a );
			return res;
		}


		//! \brief Scaling color. Changing the brightness.
		inline color3<T>& modulate(const color3<T>& color)
		{
			r *= color.r;
			g *= color.g;
			b *= color.b;
			return *this;
		}

		//! \brief return modulated
		inline color3<T> modulated(const color3<T>& c) const
		{
			color3<T> res;
			res.r = r * c.r;
			res.g = g * c.g;
			res.b = b * c.b;
			return *this;
		}

		inline color3<T>& negative()
		{
			r = 1 - r;
			g = 1 - g;
			b = 1 - b;
			return *this;
		}
	
		//! \brief return negatived
		inline color3<T> negatived() const
		{
			color3<T> res (*this);
			res.negative();
			return res;
		}


		//! \brief clamp 0.0 ... 1.0
		inline color3<T>& saturate()
		{
			if(r>1) r=1;   if(r<0) r=0;
			if(g>1) g=1;   if(g<0) g=0;
			if(b>1) b=1;   if(b<0) b=0;
			return *this;
		}

		//! \brief return clamped 0.0 ... 1.0
		inline color3<T> saturated() const
		{
			color3<T> res (*this);
			res.saturate();
			return res;
		}

		inline color3<T>& average(const color3<T>& c)
		{
			const T _two = (T)2;
			r = (r + c.r) / _two;
			g = (g + c.g) / _two;
			b = (b + c.b) / _two;
			return *this;
		}

		inline color3<T> averaged(const color3<T>& col) const
		{
			color3<T> res = *this;
			res.average(col);
			return res;
		}

		inline color3<T>& adjust_contrast(const T k)
		{
			const T _half = (T)0.5;
			r =  _half + k * ( r - _half);
			g =  _half + k * ( g - _half );
			b =  _half + k * ( b - _half );
			return *this;
		}

		inline color3<T> adjusted_contrast(const T k) const
		{
			color3<T> res(*this);
			res.adjust_contrast(k);
			return res;
		}

		inline color3<T>& adjust_saturation( const T k )
		{
			const T grey  =  r * (T)0.2125 +  g * (T)0.7154 +  b * (T)0.0721 ;
			r  = grey + k * ( k - grey );
			g  = grey + k * ( k - grey );
			b  = grey + k * ( k - grey );
			return *this;
		}

		inline color3<T> adjusted_saturation( const T k ) const
		{
			color3<T> res (*this);
			res.adjust_saturation( k );
			return res;
		}

		inline color3<T>& set_white()
		{
			r = g = b = (T)1;
			return *this;
		}

		inline color3<T>& set_black()
		{
			r = g = b = (T)0;
			return *this;
		}





		friend std::ostream &operator << (std::ostream &stream, const color3<T>& c)
		{
			stream << c.r << " " << c.g << " " << c.b ;
			return stream;
		}

		friend std::istream &operator >> (std::istream &stream, const color3<T>& c)
		{
			stream >> c.r >> " " >> c.g >> " " >> c.b ;
			return stream;
		}

		friend std::ostringstream &operator << (std::ostringstream &stream, const color3<T>& c)
		{
			stream << c.r << " " << c.g << " " << c.b ;
			return stream;
		}

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


	};


 
}