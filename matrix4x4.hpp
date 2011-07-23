/**  \file
 \brief matrix 4x4 template .

*/
 
#ifndef __MATRIX_4X4_HPP__
#define __MATRIX_4X4_HPP__


#pragma once

/*
#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
*/

#include "matrix_quad.hpp"

//#include <boost/array.hpp>

 
namespace gbmath
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

#endif // __MATRIX_4X4_HPP__