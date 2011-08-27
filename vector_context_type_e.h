/**  \file
 \brief  Role of vector in the context of



*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{




	  //! \brief   Role of vector in the context of
	  struct vector_context_type_e
	  {
		  enum e
		  {

			  UNDEFINED = 0,

			  VIEWPOSITION,
			  VIEWDIRECTION,
			  VIEWUP,
			  VIEWSIDE,

			  UNUSED_DECLARED_LAST,
			  UNUSED_FORCE32 = 0x7f000000
		  };

		  static std::string tostr(const e);
		  static bool fromstr(e& valOut, const char* str);

	  };
 
}
