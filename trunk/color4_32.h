/**  \file
 \brief яяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

//#include "../base/Types.h"
//#include "color4.h"


namespace gbmath
{

	struct color4_32_s
	{
		byte_t r, g, b, a;
	};

	//template <typename T>
	struct color4_32 : public color4<byte_t> {

		  inline color4_32() {  r = g = b = a = 0; }


		  inline operator int() const
		  {
			  int res =0;
			  res = (r<<24) | (g<<16) | (b<<8) | (a) ;
			  return res;
		  }



	};







}