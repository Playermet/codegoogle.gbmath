/**  \file
 \brief Three-standard color float.


*/



#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
 

namespace gbmath
{

	 

	//!  \brief      Three-standard color float. 
	class Color3f  
	{
	public:
	
		union
		{
			struct
			{
				float r, g, b;
			};

			float floats[3];
		};

 
		inline Color3f() {} // r = g = b = 0.0f; }
		inline Color3f(const Color3f& col)
		{
			r = col.r;   
			g = col.g;   
			b = col.b;
		}

		inline Color3f(float _r, float _g, float _b)
		{
			r=_r;
			g=_g;
			b=_b;
		}
 
 
		inline Color3f& set(float _r, float _g, float _b)
		{
			r=_r;
			g=_g;
			b=_b;
			return *this;
		}

		//! \brief  check each is zero. 
		inline bool empty() const { return (r==0.0f) && (g==0.0f) && (b==0.0f); }

		//! \brief set all to zero
		inline void setzero() { r=g=b=0.0f; }




 
		inline Color3f& setWhite( ) { r=g=b=1.0f;  return *this; }
 
		inline Color3f& setBlack( ) { r=g=b=0.0f;   return *this; }


		inline Color3f& scale(float f) { r*=f; g*=f; b*=f;  return *this; }


		//! \brief  clamp values 0.0 ... 1.0  
		inline Color3f& saturate()
		{
			if(r>1.0f) r=1.0f;   if(r<0.0f) r=0.0f;
			if(g>1.0f) g=1.0f;   if(g<0.0f) g=0.0f;
			if(b>1.0f) b=1.0f;   if(b<0.0f) b=0.0f;
			return *this;
		}


		//! \brief    linear interpolation between this and the color on the coefficients. k.
		inline Color3f lerp(const Color3f& c, const float k) const
		{
			Color3f res;
			res.r = c.r + k * ( r - c.r );
			res.g = c.g + k * ( g - c.g );
			res.b = c.b + k * ( b - c.b );
			return res;
		}



		//! \brief Scaling color. Changing the brightness.
		inline Color3f& modulate(const Color3f& color)
		{
			r *= color.r;
			g *= color.g;
			b *= color.b;
			return *this;
		}

		//! \brief return modulated
		inline Color3f modulated(const Color3f& c) const
		{
			Color3f res;
			res.r = r * c.r;
			res.g = g * c.g;
			res.b = b * c.b;
			return *this;
		}

		inline Color3f& negative()
		{
			r = 1 - r;
			g = 1 - g;
			b = 1 - b;
			return *this;
		}

		//! \brief return negatived
		inline Color3f negatived() const
		{
			Color3f res (*this);
			res.negative();
			return res;
		}


		//! \brief clamp 0.0 ... 1.0
		//inline Color3f& saturate()
		//{
		//	if(r>1) r=1;   if(r<0) r=0;
		//	if(g>1) g=1;   if(g<0) g=0;
		//	if(b>1) b=1;   if(b<0) b=0;
		//	return *this;
		//}

		//! \brief return clamped 0.0 ... 1.0
		inline Color3f saturated() const
		{
			Color3f res (*this);
			res.saturate();
			return res;
		}

		inline Color3f& average(const Color3f& c)
		{
			const float _two = 2.0f;
			r = (r + c.r) / _two;
			g = (g + c.g) / _two;
			b = (b + c.b) / _two;
			return *this;
		}

		inline Color3f averaged(const Color3f& col) const
		{
			Color3f res = *this;
			res.average(col);
			return res;
		}

		inline Color3f& adjust_contrast(const float k)
		{
			const float _half = 0.5f;
			r =  _half + k * ( r - _half);
			g =  _half + k * ( g - _half );
			b =  _half + k * ( b - _half );
			return *this;
		}

		inline Color3f adjusted_contrast(const float k) const
		{
			Color3f res(*this);
			res.adjust_contrast(k);
			return res;
		}

		inline Color3f& adjust_saturation( const float k )
		{
			const float grey  =  r *  0.2125f +  g *  0.7154f +  b *  0.0721f ;
			r  = grey + k * ( k - grey );
			g  = grey + k * ( k - grey );
			b  = grey + k * ( k - grey );
			return *this;
		}

		inline Color3f adjusted_saturation( const float k ) const
		{
			Color3f res (*this);
			res.adjust_saturation( k );
			return res;
		}

 

		inline bool operator == (const Color3f& c) const
		{
			return (r==c.r) && (g==c.g) && (b==c.b);
		}
		inline bool operator != (const Color3f& c) const
		{
			return (r!=c.r) && (g!=c.g) && (b!=c.b);
		}



		inline Color3f& operator *= (const Color3f& c)        { r*=c.r; g*=c.g;  b*=c.b;   return *this;  }
		inline Color3f& operator *= (float f)                 { r*=f;   g*=f;    b*=f;     return *this;  }

		
		inline Color3f& operator += (const Color3f& c)        { r+=c.r; g+=c.g;  b+=c.b;   return *this;  }
		inline Color3f& operator += (float f)                 { r+=f;   g+=f;    b+=f;     return *this;  }

		inline Color3f& operator -= (const Color3f& c)        { r+=c.r; g+=c.g;  b+=c.b;   return *this;  }
		inline Color3f& operator -= (float f)                 { r-=f;   g-=f;    b-=f;     return *this;  }


		inline Color3f operator *  (const Color3f& c) const  { Color3f res(r*c.r, g*c.g, b*c.b );   return res;  }
		inline Color3f operator *  (float f)   const         { Color3f res(r*f,   g*f,   b*f   );   return res;  }
		inline Color3f operator /  (const Color3f& c) const  { Color3f res(r/c.r, g/c.g, b/c.b );   return res;  }
		inline Color3f operator /  (float f)   const         { Color3f res(r/f,   g/f,   b/f   );   return res;  }		
		
		inline Color3f operator +  (const Color3f& c) const  { Color3f res(r+c.r, g+c.g, b+c.b );   return res;  }
		inline Color3f operator +  (float f) const           { Color3f res(r+f,   g+f,   b+f   );   return res;  }

		inline Color3f operator -  (const Color3f& c) const  { Color3f res(r-c.r, g-c.g, b-c.b );   return res;  }
		inline Color3f operator -  (float f) const           { Color3f res(r-f,   g-f,   b-f   );   return res;  }



		inline  operator float*()                { return &r; }
		inline  operator const float*() const    { return &r; }

 


		friend std::ostream &operator << (std::ostream &stream, const Color3f& c)
		{
			stream << c.r << " " << c.g << " " << c.b ;
			return stream;
		}

		friend std::istream &operator >> (std::istream &stream,  Color3f& c)
		{
			stream >> c.r;
			stream >> c.g;
			stream >> c.b;
			return stream;
		}

		friend std::ostringstream &operator << (std::ostringstream &stream, const Color3f& c)
		{
			stream << c.r << " " << c.g << " " << c.b ;
			return stream;
		}


		#if defined(_MSC_VER)
		#pragma warning( push )
		#pragma warning( disable : 4290 )
		#endif

		friend std::stringstream &operator >> (std::stringstream &stream, Color3f& c) throw (std::invalid_argument)
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
