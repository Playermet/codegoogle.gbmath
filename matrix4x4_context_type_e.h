﻿/**  \file
  \brief The role of matrix in the context of

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{

 

	  //!  \brief The role of matrix in the context of
	  struct matrix4x4_context_type_e
	  {
		  enum e
		  {
			  UNDEFINED  = 0,   ///<  undefined role .


			  VIEWPROJECTION   =  0x00010000,
			  VIEWPROJECTIONINVERSE,
			  VIEWPROJECTIONINVERSETRANSPONE,
			  VIEWPROJECTIONTRANSPONE,
			  VIEW,
			  VIEWTRANSPONE,
			  VIEWINVERSE,
			  VIEWINVERSETRANSPONE,
			  PROJECTION,
			  PROJECTIONINVERSE,
			  PROJECTIONTRANSPONE,
			  PROJECTIONINVERSETRANSPONE,
			  WORLDVIEWPROJECTION,
			  WORLDVIEWPROJECTIONTRANSPONE,
			  WORLDVIEWPROJECTIONINVERSE,
			  WORLDVIEWPROJECTIONINVERSETRANSPONE,
			  WORLD,
			  WORLDTRANSPONE,
			  WORLDINVERSE,
			  WORLDINVERSETRANSPONE,
			  WORLDVIEW,
			  WORLDVIEWTRANSPONE,
			  WORLDVIEWINVERSE,
			  WORLDVIEWINVERSETRANSPONE,



			  UNUSED_DECLARED_LAST, ///< UNUSED. declared last.

			  UNUSED_FORCE32  = 0x7f000000	///< НЕ UNUSED. allign 4 bytes.
		  };

		  static std::string tostr(const e);
		  static bool fromstr(e& valOut, const char* str);
	  };

}
