/**  \file
 \brief яяяяяяяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	#pragma message ("!!! need rename  " __FILE__  )

		//! \brief описание состояния пространственого  пересачения объектов
		enum  obj_contains_e
		{
			SC_NOOVERLAP, ///<   объект не касается другого объекта
			SC_CONTAINSFULLY, ///<   объект  полностью расположен  в другом
			SC_CONTAINSPARTIALLY  ///< объект частично содержится в другом
		};




 
}