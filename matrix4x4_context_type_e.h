/**  \file
 \brief яяяяяяяяя
    



*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	


	  //!  \brief Роль матрицы в контексте   
	  struct matrix4x4_context_type_e
	  {
		  enum e
		  { 	
			  UNDEFINED  = 0,   ///< тип НЕ ОПРЕДЕЛЁН.


			  VIEWPROJECTION,
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



			  UNUSED_DECLARED_LAST, ///< НЕ ИСПОЛЬЗУЕТСЯ.   Декларируется последним.

			  UNUSED_FORCE32  = 0x7f000000	///< НЕ ИСПОЛЬЗУЕТСЯ. Для выравнивания по 4 байтам.
		  };

		  static std::string tostr(const e);
		  static bool fromstr(e& valOut, const char* str);
	  };



	
	
	}
}
