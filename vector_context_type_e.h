/**  \file
 \brief ?????xxxxяяяяя



*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{




	  //!  Роль вектора в контексте
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