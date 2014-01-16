/**  \file
 \brief Three-standard color byte.


 */

#pragma once

#ifndef __GBMATH_H__
	#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{


	//! \brief  Three-standard color byte.
	struct color3_24 : public color3<byte_t> 
	{

		inline color3_24() 
		{  
			r = g = b = 0; 
		}

		inline color3_24(const color3_24& a)
		{
			*this = a;
		}

		color3_24( byte_t _r, byte_t _g, byte_t _b )
		{
			r = _r;
			g = _g;
			b = _b;
		}






	};



}
