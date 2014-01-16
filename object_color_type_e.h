/**    \file
 \brief  The role of color in the scene
 
 
 
 
 */

#pragma once


#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
 
namespace gbmath
{
 
	   //!  \brief  The role of color in the scene
		struct object_color_type_e
		{
			enum e
			{
				UNDEFINED = 0,  ///<  undefgined

				AMBIENT, 
				DIFFUSE,
				SPECULAR,
				EMISSIVE,
 				LIGHTSOURCECOLOR,
				LIGHTMAPCOLOR,


				UNUSED_DACLARED_LAST, ///< not used. Declare last.
				UNUSED_FROCE32 = 0xff000000  ///< not used. align 4 bytes.

			};

			//!  enum to string
			static std::string tostr(e) ;

			//!  enum from string
			static bool fromstr(e&, const std::string&) ;
		};	 
	 
	 

		struct object_colors
		{


				color4f  Ambien; 
				color4f  Diffuse;
				color4f  Specular;
				color4f  Emissive;
				color4f  LightSourceSolor;
				color4f  LightmapColor;


				object_colors() 
				{

				}
 
				const color4f*   getByType(const object_color_type_e::e value) const ;

		};
 
}
