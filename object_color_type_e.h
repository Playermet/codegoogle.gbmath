/**    \file
 \brief  яяяяяяяя
 
 */

#pragma once


#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


//#include <string>


 
namespace gbmath
{
 
		struct object_color_type_e
		{
			enum e
			{
				UNDEFINED = 0,  ///< не определено


				AMBIENT, 
				DIFFUSE,
				SPECULAR,
				EMISSIVE,


				UNUSED_DACLARED_LAST, ///< не используется . Декларировать последним
				UNUSED_FROCE32 = 0xff000000  ///< не используется. Для выравнивания по 4 байтам

			};

			//! перечисление в строку. Вернёт пустую строку, если _enum некорректно.
			static std::string tostr(e) ;

			//! перечисление из строки. Вернёт false, если строка некорректна
			static bool fromstr(e&, const std::string&) ;
		};	 
	 
	 
 
}
