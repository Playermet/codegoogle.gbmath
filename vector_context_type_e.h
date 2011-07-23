/**  \file
 \brief ??????
    


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
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
}
