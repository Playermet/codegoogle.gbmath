/**  \file
 \brief mathematical dependence of the function

 
 
 
*/

#pragma once

#include <float.h>
#include <string>

 
namespace gbmath
{

	//! \brief    mathematical dependence of the function
	struct dependence_on_function 
	{
	
		enum e
		{
			undef = 0,
			
			
			linear,   ///<  y=x;
			linear_inverse,   ///<  y=1-x; 

			squared,            ///<  y=x*x; 
			squared_a_inverse,  ///<  y= 1 - x*x; 

			cubic,    ///< y=x*x*x;
			cubic_a_inverse, ///< 1- x*x*x 
			
			
		
			__UNUSED_DCLARED_LAST,
			__UNUSED_ALIGN32 = 0x7f000000
		};
		
		e _e;
	
		inline dependence_on_function() 
		{
			_e = undef; 
		}

		inline dependence_on_function(const e value) 
		{
			_e = value; 
		}

		inline dependence_on_function(const dependence_on_function& value)
		{
			_e = value._e; 
		}
 		
		
		inline void operator = (const e value) 
		{ 
			_e = value; 
		}

		inline operator e() const 
		{ 
			return _e; 
		}
		
 
		operator std::string() const;
 
		void operator = (const std::string& str);

		friend std::ostream& operator << (std::ostream& os, const dependence_on_function& a)
		{
			os << (std::string)a;
			return os;
		}
		
			
		static  float formula(float x, const e depend ) ;
	
	};

 

}
