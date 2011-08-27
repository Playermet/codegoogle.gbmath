/**  \file
 \brief description of spatial objects crossing


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	#pragma message ("!!! need rename  " __FILE__  )

		//! \brief  description of spatial objects crossing
		enum  obj_contains_e
		{
			SC_NOOVERLAP, ///<   object does not apply to another object
			SC_CONTAINSFULLY, ///<   the object is fully located in another
			SC_CONTAINSPARTIALLY  ///< object is partially contained in the other
		};

 
}
