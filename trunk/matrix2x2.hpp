// matrix2x2.hpp


#ifndef __MATRIX_2X2_HPP__
#define __MATRIX_2X2_HPP__

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
	struct matrix2x2 : public matrix_quad<T,2> {
	  /// ....
	  
	  // rot. scale, transl, mul, settransform
	};





	
	
	}
}

#endif // __MATRIX_2X2_HPP__