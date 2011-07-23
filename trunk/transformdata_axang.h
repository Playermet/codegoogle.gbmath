/**  \file
 \brief ??????

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

#pragma message ("!!! NEDD operators >> << to/from string "  __FILE__ )
 
namespace gbmath
{
 

   //! \brief  Сборка трансформации , но для повотора импользуется ось и угол.
   struct TransformData2
   {
	   vec3        scaling;
	   AxiesAngle  rotation;
	   vec3        translatiion;
   };



 
}