/**  \file
 \brief matrix 2x2 template .

*/
 

#ifndef __MATRIX_2X2_HPP__
#define __MATRIX_2X2_HPP__

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

#include "matrix_quad.hpp"

 
namespace gbmath
{




	template <typename T>
	struct matrix2x2 : public matrix_quad<T,2> {
	  /// ....

	  // rot. scale, transl, mul, settransform
	};



 
}

#endif // __MATRIX_2X2_HPP__