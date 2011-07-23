/**  \file 
 \brief ÿÿÿÿÿÿÿÿ
 
 
*/

#pragma once

#ifndef __GB_FMATH_H__
#error ÍÅ ÂÊËŞ×ÀÉÒÅ İÒÎÒ ÔÀÉË. ÂÊËŞ×ÀÉÒÅ:   #include <gb/fmath/math.h>  
#endif

//#include "../base/Types.h"
//#include "color4.h"

namespace gb
{

	namespace fmath
	{
	
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

}