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
	class Color3f  : public  color3<float> 
	{
	public:
		//union
		//{
		//	struct
		//	{
		//		float r, g, b;
		//	};

			//float floats[3];
		//};

		/***************************
		inline Color3f() {} // r = g = b = 0.0f; }
		inline Color3f(const Color3f& col)
		{
			r=col.r;   g=col.g;   b=col.b;
		}

		inline Color3f(float _r, float _g, float _b)
		{
			r=_r;
			g=_g;
			b=_b;
		}
		*****************************/

		//  inline Color3f(const color4f_s& col )         { r=col.r;   g=col.g;   b=col.b;   }

	//	Color3f& operator = (const color32_t col) ;


		//inline Color3f& set(float _r, float _g, float _b)
		//{
		//	r=_r;
		//	g=_g;
		//	b=_b;
		//	return *this;
		//}

		///** \brief Проверка каждого на ноль. */
		//inline bool empty() const { return (r==0.0f) && (g==0.0f) && (b==0.0f); }
		///** \brief обнулить */
		//inline void setzero() { r=g=b=0.0f; }




	//	/** \brief Установить как белый цвет */
	//	inline Color3f& setWhite( ) { r=g=b=1.0f;  return *this; }
	//	/** \brief Установить как чёрный цвет */
	//	inline Color3f& setBlack( ) { r=g=b=0.0f;   return *this; }


	//	/** \brief  масштабирование . Изменение яркости. */
	//	inline Color3f& scale(float f) { r*=f; g*=f; b*=f;  return *this; }


	//	/** \brief Отсечение значений в пределах 0.0 ... 1.0  */
	//	inline Color3f& saturate()
	//	{
	//		if(r>1.0f) r=1.0f;   if(r<0.0f) r=0.0f;
	//		if(g>1.0f) g=1.0f;   if(g<0.0f) g=0.0f;
	//		if(b>1.0f) b=1.0f;   if(b<0.0f) b=0.0f;
	//		return *this;
	//	}


		//inline bool compare(const Color3f& c) const
		//{
		//	return (r==c.r) && (g==c.g) && (b==c.b) ;
		//}



		//  inline Color3f& operator = (const color_rgb24_s col)
		//  {
		//	  r = ( (float)col.r ) / 255.0f ;
		//	  g = ( (float)col.g ) / 255.0f ;
		//	  b = ( (float)col.b ) / 255.0f ;
		//	   return *this;
		// }

		/* ******
		inline bool operator == (const Color3f& c) const
		{
			return (r==c.r) && (g==c.g) && (b==c.b);
		}
		inline bool operator != (const Color3f& c) const
		{
			return (r!=c.r) && (g!=c.g) && (b!=c.b);
		}
		******************/

		/******************
		inline Color3f& operator *= (const Color3f& c)        { r*=c.r; g*=c.g;  b*=c.b;   return *this;  }
		inline Color3f& operator *= (float f)                 { r*=f;   g*=f;    b*=f;     return *this;  }
		inline Color3f& operator += (const Color3f& c)        { r+=c.r; g+=c.g;  b+=c.b;   return *this;  }
		inline Color3f& operator += (float f)                 { r+=f;   g+=f;    b+=f;     return *this;  }

		inline Color3f operator *  (const Color3f& c) const  { Color3f res(r*c.r, g*c.g, b*c.b );   return res;  }
		inline Color3f operator *  (float f)   const         { Color3f res(r*f,   g*f,   b*f   );   return res;  }
		inline Color3f operator +  (const Color3f& c) const  { Color3f res(r+c.r, g+c.g, b+c.b );   return res;  }
		inline Color3f operator +  (float f) const           { Color3f res(r+f,   g+f,   b+f   );   return res;  }

		 **************/

	//
	//
	//#pragma warning (push)
	//#pragma warning (disable : 4996)
	//
	//
	//	/** \brief Конвертация в строку.  Разделитель:  пробел */
	//	std::string tostr() const
	//	{
	//		std::string r;
	//		char ss[32];
	//		ss[0] = 0;
	//		sprintf(ss, "%f  %f  %f", r, g, b );
	//		r = ss;
	//		return r;
	//	}
	//
	//	/** \brief   Чтение значений из строки разд. пробелами  */
	//	inline bool fromstr(const std::string&  s)
	//	{
	//		const int SCRES = sscanf(s.c_str(), "%f  %f  %f", &r, &g, &b );
	//		if( SCRES != 3  ) return false;
	//		return true;
	//	}
	//
	//
	//#pragma warning (pop)
	//
	//
	//	/** \brief печать значений на консоль */
	//	inline void print() const { printf( "%f  %f  %f", r, g, b);  }
	//



	};
	// end class


}

