/**  \file
 \brief Assembling the transformation

 
 
*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{
 

   //! \brief Assembling the transformation    (scaling + rotation (axis and angle) + Position)
   struct TransformData2
   {
	   vec3            scaling;
	   axies_angle     rotation;
	   vec3            translatiion;





	   friend std::ostream& operator << (std::ostream& os, 
											const TransformData2& a)
	   {
			os << a.scaling;
			os << "\n";

			os << a.rotation;
			os << "\n";

			os << a.translatiion;
			os << "\n";

			return os;
	   }

   };



 
}