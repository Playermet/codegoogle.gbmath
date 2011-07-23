// matrix4x4.hpp

#ifndef __MATRIX_4X4_HPP__
#define __MATRIX_4X4_HPP__


#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif

#include "matrix_quad.hpp"


#include <boost/array.hpp>

namespace gb
{

	namespace fmath
	{
	
 

	template <typename T>
	struct matrix4x4 : public matrix_quad<T,4> {
	 /// ....
	 
	 
		inline matrix4x4<T> () {}
		
		inline matrix4x4<T> (const  matrix4x4<T>& a) 
		{
			*this = a;
		}
	 
		inline vector4<T> get_row_vector() const 
		{
			inline vector4<T> res;
			assert(false);	/// ????? xxxxx
			return res;
		}
		
		
		inline vector4<T> get_column_vector() const
		{
			inline vector4<T> res;
			assert(false);  /// ????? xxxxx
			return res;
		}

	 
	};

 


	
	
	}
}

#endif // __MATRIX_4X4_HPP__