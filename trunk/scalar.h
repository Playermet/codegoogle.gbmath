﻿/** \file
* \brief   float/double operations .
*
*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



//#include </Config.h>
//#include </base/Constants.h>

/*******************************************************

 TODO:

  -- возможно переделать некоторые операции на шаблоны.
  -- убрать все шаблоны

STORY:
 --- добавлены ещё некоторые операции
 --- добавлена функция получения максимального по трём значениям
 -- round поправлена и перенесена в инлайн. Спасибо Zeux`у

********************************************************/



//! \brief   math operations and structures .
namespace gbmath
{
 

  //! \brief    fmath  constants .
  namespace constan
  {

   	static const float EPSILON	  =	1.0e-6f;

   	static const float PI       = 3.1415926536f; ///<   PI
   	static const float C1BYPI    = 0.3183098862f; ///<   1/PI

   	static const float PI2         =  6.283185307f; ///<  	2*PI
   	static const float PI_DIV_2      =  1.570796326f; ///<   PI/2
   	static const float PI_DIV_4      =  0.785398163f; ///<   PI/4
   	static const float PI_DIV_6      =  0.523598776f; ///<   PI/6

   	static const float PI_DIV_180    =  0.017453292f; ///<   PI/180
   	static const float C180DIVPI    =  57.29577951f; ///<   180/PI

   	static const float C3PIDIV4     = 2.35619449f;   ///<   3/4 PI
   	static const float PI2_INV      = 0.159154943f;  ///<   1/(2PI)
   	static const float CINV360      = 0.002777778f;  ///<   1/360
   	static const float C180         = 180.0f;
   	static const float C360         = 360.0f;
   	static const float HALF     = 0.5f;
   	static const float TWO         = 2.0f;
   	static const float LN10        = 2.302585093f;

   	static const float SQRT_2       = 1.4142135624f; ///< sqrt(2)
   	static const float SQRT_HALF    = 0.7071067812f; ///< sqrt(1/2)

   	static const float E           = 2.718281828459f; ///<  e


  }



    //! \brief   с  вещественными типами  (float/double).  
    namespace scalar
	{

	//---------------------------------------------------------------------



	//inline bool is_nan( float a )
	//{
	//	bool r = a==a;
	//	return !( a == a );
	//}

	inline bool compare(float a, float b, float epsilon)
	{
	   return fabs(a - b) < epsilon;
	}


	//! \brief Check the value the correct value
	inline bool check(float f)
	{
       if( f == 0.0f ) 
		   return true;

	   if(f < 0.0f) 
		   f = -f;

       if( (f <= FLT_MAX) && (f >= FLT_MIN) ) 
		   return true;

	   return false;
    }

	//! \brief Check the value the correct value
	inline bool check(double d)
	{
       if( d == 0.0 ) 
		   return true;

	   if(d < 0.0) 
		   d = -d;

       if( (d <= DBL_MAX) && (d >= DBL_MIN) ) 
		   return true;

	   return false;
    }


		//! \brief  Квадрат
		inline float sqr(float a) 
		{ 
			return a*a; 
		}

		inline float abs(float val)
		{
		    if(val<0.0f)
			{
				return -val;
			}

			return val;
		}


		template<typename T>
		//! \brief   Calculate the linear interpolation
		inline T lerp( float alpha, const T& v0, const T& v1 ) throw()
		{
			return( (T)(v0 + alpha * ( v1 - v0 )) );
		}


		template<class T>
		//! \brief   reduction in the range between
		inline T clamp( const T& v, const T& l, const T& u ) throw()
		{
			return min(u, max(l,v));
		}


		template<typename T>
		//! \brief   fill the buffer dest value val number num.
		inline void fill( T * dest, const T val, const int num ) throw()
		{
			for (int i = 0; i < num; i++)
			{
				dest[i] = val;
			}
		}

// 		template<typename T, const unsigned int num>
// 		//! \brief   copy
// 		inline void copy( T * dest, const T * val, const int num ) throw()
// 		{
// 			for (int i = 0; i < num; i++)
// 			{
// 				dest[i] = val[i];
// 			}
// 		}



	/**  \brief   Returns the sign of <br>
	     x>0 :  1   <br>
	     x=0 :  0   <br>
	     x<0 : -1	  */
    inline float  sign (const float val)
	{
	    if(val==0.0f)
		  return 0.0f;

		if(val>0.0f)
		  return 1.0f;

		return -1.0f;
	}

	/** \brief Returns the sign of  <br>
	 x>0 :  1   <br>
	 x=0 :  0   <br>
	 x<0 : -1	  */
	inline int sign2(float x)
	{
		return  (x>0)-(x<0);
	}


	//! \brief Отсечение значения в пределах между минимумом и максимумом включительно. 
	inline float clump(float value, float _min, float _max)
	{
	      float r = value;
	    if(r < _min) r=_min;
	    if(r > _max) r=_max;
	      return r;
	}

	//! \brief   sine and cosine.
	inline void sincos(const float a, float& outSin, float& outCos) 
	{  
		outSin = sin(a); 
		outCos = cos(a); 
	}

    #if defined (_MSC_VER)

	//! \brief ассемблерный способ получить синус и косинус 
	inline void sincosAsm (float a, float& s, float& c)
	{
		__asm  {
				fld a;
				fsincos;
				mov eax, [c];
				fstp [eax];
				mov eax, [s];
				fstp [eax];
			};
	};
	#endif

	//! \brief Calculate the arc cotangent 
    inline float arccot(float f) //throw()
	{
	   //if(0.0f==f)
	     // throw std::runtime_error("Inv arg");
	   return atan(1.0f / f);
	};

	//! \brief Calculate the arc tangent
	inline float arctg(float y, float x)
	{
			//#ifdef __BCPLUSPLUS__
			//	return atan2(y, x);
			//#else
				return atan2f(y, x);
			//#endif
	}

	/** \brief  Same as acos(x), but if x is out of range, it is "clamped"
	to the nearest valid value.  The value returned is in range 0...pi,
	the same as the standard C acos() function   
	*/
	inline float safeAcos(float x)
	{
		// Check limit conditions
		if (x <= -1.0f)
		{
			return gbmath::constan::PI; //   constPi <float>(); // kPi;
		}
		if (x >= 1.0f)
		{
			return 0.0f;
		}

		// Value is in the domain - use standard C function
		return acos(x);
	}


	//!  \brief   cotangent 
    inline float cotan(const float f) 
	{  
		return   1.0f / tanf(f); 
	}

	//! \brief   Angle in radians to degrees
	inline float radiansToDegree(float rad) 
	{ 
		return rad * ( 180.0f / gbmath::constan::PI ); 
	}


	//! \brief Angle in degrees to radians
	inline float degreeToRadians(float dgr)  
	{ 
		return dgr * ( gbmath::constan::PI / 180.0f); 
	}

	//! \brief Normalization of the angle of rotation angle.   Cast the value in the range -PI ... + PI .
	inline float normalize_angle( float angle )
	{
		static  const float _PI_ = 3.1415926535898f;
		static  const float TWO_PI = 6.2831853071795865f;

		return (angle - TWO_PI *  floor( ( angle + _PI_ ) / TWO_PI) );
	}


	//!  \brief  Linear interpolation  
    inline float lerp(const float f1, const float f2, const float k) 
	{ 
		return f1 + (f2 - f1) * k; 
	}

	//! \brief rounding . 
	inline int round(float f) 
	{  
		return (int)(f + (f > 0 ? 0.5f : -0.5f));  
	}

	#if defined (_MSC_VER)

	//! \brief rounding asm . 
	inline int roundAsm(float a)
	{
	   register int retval;
		 __asm fld a
		 __asm fistp retval
			   return retval;
	}

	#endif


    //! \brief Get an average of 3 values 
	inline float   max3 ( float a, float b, float c ) 
	{ 
		return a > b ? (a > c ? a : (b > c ? b : c)) : (b > c ? b : (a > c ? a : c));  
	}



	//! \brief  Compute and return the average (arithmetic) 
	inline float aver_a(const float* pf, const unsigned int num)
	{
		float r = 0.0f;
		if(num==0) 
			return r;

		for(unsigned int c=0; c<num; c++)
		{
			r +=  *( pf + c );
		}

		return r / (float)num;
	}

	//!  \brief  Compute and return the geometric mean 
	inline float aver_g(const float* pf, const unsigned int num)
	{
		float r = 1.0f;
		if(num==0) 
			return r;

		for(unsigned int c=0; c<num; c++)
		{
			r *=  *( pf + c );
		}

		return   pow( r, 1.0f/(float)num );
	}

	//! \brief Получение случайного значения в диапазоне ( 0.0f ... 1.0f )
	float random();



	//---------------------------------------------------------------------

	}

}
