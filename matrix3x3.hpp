// matrix3x3.hpp


#ifndef __MATRIX_3X3_HPP__
#define __MATRIX_3X3_HPP__

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif

#include "matrix_quad.hpp"
 

namespace gb
{

	namespace fmath
	{
	
	

	

	template <typename T>
	struct matrix3x3 : public matrix_quad<T,3> {
	 
	};



	
	
	}
}

#endif // __MATRIX_3X3_HPP__