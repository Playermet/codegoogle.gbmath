/** \file
* \brief Операции с   float/double
*
*
*
*
*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif



//#include <gb/Config.h>
//#include <gb/base/Constants.h>

/*******************************************************

 TODO:

  -- возможно переделать некоторые операции на шаблоны.
  -- убрать все шаблоны
 
STORY:
 --- добавлены ещё некоторые операции
 --- добавлена функция получения максимального по трём значениям
 -- round поправлена и перенесена в инлайн. Спасибо Zeux`у

********************************************************/

namespace gb 
{

  //! \brief  Математические операции
  namespace fmath
  {




    // прошу их (константы) никуа не переносить
	// так как возможно в будущем будет исключен так же и math.h

  //! \brief  Константы  для  fmath
  namespace constan 
  {

   	static const float CEPSILON	  =	1.0e-6f;

   	static const float CPI       = 3.1415926536f; ///<   PI
   	static const float C1BYPI    = 0.3183098862f; ///<   1/PI	

   	static const float C2PI         =  6.283185307f; ///<  	2*PI
   	static const float CPIDIV2      =  1.570796326f; ///<   PI/2
   	static const float CPIDIV4      =  0.785398163f; ///<   PI/4
   	static const float CPIDIV6      =  0.523598776f; ///<   PI/6
   
   	static const float CPIDIV180    =  0.017453292f; ///<   PI/180
   	static const float C180DIVPI    =  57.29577951f; ///<   180/PI
   
   	static const float C3PIDIV4     = 2.35619449f;   ///<   3/4 PI
   	static const float CINV2PI      = 0.159154943f;  ///<   1/(2PI)
   	static const float CINV360      = 0.002777778f;  ///<   1/360
   	static const float C180         = 180.0f;
   	static const float C360         = 360.0f;
   	static const float CONEHALF     = 0.5f;
   	static const float CTWO         = 2.0f;
   	static const float CLN10        = 2.302585093f;
   
   	static const float CSQRT2       = 1.4142135624f; ///< sqrt(2)
   	static const float CSQRTHALF    = 0.7071067812f; ///< sqrt(1/2)
   	
   	static const float CE           = 2.718281828459f; ///<  e


  }

 
  
    /** \brief  Операции  с  вещественными типами  (float/double).  */
    namespace scalar
	{
	
	//---------------------------------------------------------------------

	
 
	//inline bool is_nan( float a ) 
	//{
	//	bool r = a==a;
	//	return !( a == a );
	//}
 
	inline bool compare(float a, float b, float eps)
	{
	   return fabs(a - b) < eps;
	}


 
	
	/** \brief Проверка float f   на корректное значение  */
	inline bool check(float f) 
	{
       if( f == 0.0f ) return true;
	   if(f < 0.0f) f = -f;
       if( (f <= FLT_MAX) && (f >= FLT_MIN) ) return true;
	       return false;
    };

	/** \brief Проверка double d   на корректное значение  */
	inline bool check(double d) 
	{
       if( d == 0.0 ) return true;
	   if(d < 0.0) d = -d;
       if( (d <= DBL_MAX) && (d >= DBL_MIN) ) return true;
	       return false;
    };
	
	
	
	
	
		//! \brief  Квадрат
		inline float sqr(float a) { return a*a; }

		inline float abs(float val)
		{
		    if(val<0.0f) 
			{
				return -val;
			}

			return val;
		}


		template<typename T> 
		//! \brief   Вычислить линейную интерполяцию
		inline T lerp( float alpha, const T& v0, const T& v1 ) throw()
		{
			return( (T)(v0 + alpha * ( v1 - v0 )) );
		}

		template<class T> 
		//! \brief   отсечение
		inline T clamp( const T& v, const T& l, const T& u ) throw()
		{
			return min(u, max(l,v));
		}

		template<typename T>
		//! \brief   заполнение буфера dest значением val   количеством num
		inline void fill( T * dest, const T val, const int num ) throw()
		{
			for (int i = 0; i < num; i++)
			{
				dest[i] = val;
			}
		}

// 		template<typename T, const unsigned int num>
// 		//! \brief  Копирование массива val в dest   количество  num
// 		inline void copy( T * dest, const T * val, const int num ) throw()
// 		{
// 			for (int i = 0; i < num; i++)
// 			{
// 				dest[i] = val[i];
// 			}
// 		}


	
	/**  \brief   Возвращает  знак числа  <br>  
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

	/** \brief Возвращает  знак числа  <br>  
	 x>0 :  1   <br>
	 x=0 :  0   <br>
	 x<0 : -1	  */
	inline int sign2(float x)
	{
		return  (x>0)-(x<0);
	}


	/** \brief Отсечение значения в пределах между минимумом и максимумом включительно. */
	inline float clump(float value, float _min, float _max)
	{
	      float r = value;
	    if(r < _min) r=_min;
	    if(r > _max) r=_max;
	      return r;
	}

	inline void sincos(const float a, float& outSin, float& outCos) {  outSin = sin(a); outCos = cos(a); };
	
    #if defined (_MSC_VER)	
	/** \brief ассемблерный способ получить синус и косинус */
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
	
	/** \brief Вычислить арк котангенс */
    inline float arccot(float f) //throw() 
	{ 
	   //if(0.0f==f) 
	     // throw std::runtime_error("Inv arg"); 
	   return atan(1.0f / f); 
	};
	
	//! \brief Вычислить арк тангенс 
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
	the same as the standard C acos() function   */
	inline float safeAcos(float x) 
	{
		// Check limit conditions
		if (x <= -1.0f) 
		{
			return gb::fmath::constan::CPI; //   gb::constPi <float>(); // kPi;
		}
		if (x >= 1.0f) 
		{
			return 0.0f;
		}

		// Value is in the domain - use standard C function
		return acos(x);
	}

	/**  \brief Вычислить котангенс  */
    inline float cotan(const float f) {  return   1.0f / tanf(f); };
	
	//! \brief Угол в радианах в градусы 
	inline float radiansToDegree(float rad)  { return rad * ( 180.0f / gb::fmath::constan::CPI ); };
	//! \brief Угол в градусах в радианы 	
	inline float degreeToRadians(float dgr)  { return dgr * ( gb::fmath::constan::CPI / 180.0f); };
	
	//! \brief Нормализация угла поворота angle. Приведение значения в пределах -PI...+PI  .
	inline float normalize_angle( float angle ) 
	{
		static  const float _PI_ = 3.1415926535898f;
		static  const float TWO_PI = 6.2831853071795865f;

		return (angle - TWO_PI *  floor( ( angle + _PI_ ) / TWO_PI) );
	}

	
	/**  \brief  Вычисленить линейную интерполяцию между f1 и f2 по коэф. k */
    inline float lerp(const float f1, const float f2, const float k) { return f1 + (f2 - f1) * k; };
	
	/** \brief Округление . */
	inline int round(float f) {  return (int)(f + (f > 0 ? 0.5f : -0.5f));  };
	
	#if defined (_MSC_VER)
	/** \brief ассемблерный способ округления.  */
	inline int roundAsm(float a) 
	{
	   register int retval;
		 __asm fld a
		 __asm fistp retval
			   return retval;
	};
	#endif	
	

    /** \brief Получить среднее из 3-х  значений */
	inline float   max3 ( float a, float b, float c ) { return a > b ? (a > c ? a : (b > c ? b : c)) : (b > c ? b : (a > c ? a : c));  }
	
	

	/** \brief  Вычислить и вернуть среднее АРИФМЕТИЧЕСКОЕ массива pf размером num */
	inline float aver_a(const float* pf, const unsigned int num) 
	{
		float r = 0.0f;
		if(num==0) return r;
		for(unsigned int c=0; c<num; c++) 
		{
			r +=  *( pf + c );
		}

		return r/(float)num;  
	}

	//!  \brief  Вычислить и вернуть среднее ГЕОМЕТРИЧЕСКОЕ массива pf размером num 
	inline float aver_g(const float* pf, const unsigned int num) 
	{
		float r = 1.0f;
		if(num==0) return r;
		for(unsigned int c=0; c<num; c++) 
		{
			r *=  *( pf + c );
		}

		return   pow(r, 1.0f/(float)num);  
	}

	//! \brief Получение случайного значения в диапазоне ( 0.0f ... 1.0f )
	float random();


	
	//---------------------------------------------------------------------

	}
	
  }

}

// end file