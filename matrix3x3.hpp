/**  \file
 \brief matrix 3x3 template .

*/


#ifndef __MATRIX_3X3_HPP__
#define __MATRIX_3X3_HPP__

#pragma once

/*
#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
*/

#include "matrix_quad.hpp"

 
namespace gbmath
{





	template <typename T>
	struct matrix3x3 : public matrix_quad<T,3> {

	};


 
}

#endif // __MATRIX_3X3_HPP__