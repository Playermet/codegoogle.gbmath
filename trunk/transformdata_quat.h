/**  \file
* \brief ??????
*
*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gbmath
{

  #pragma message("!!need add operatiions  >> << to from string  "  __FILE__ )



   //! \brief Сборка из данных трансформации: скалирование(вектор) + поворот(кват.) + позиция(вектор).
   struct TransformData
   {
	    vec3         vScaling;      ///< масштабирование
	    Quaternion   qRotation;     ///< вращение
	    vec3         vTranslation;  ///<  позиция
   };



 
}