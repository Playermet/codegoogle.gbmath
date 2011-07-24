/**  \file
 \brief яяяяяяяя

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

namespace gbmath
{


   //! \brief Сборка векторов вида.
   struct eyedata
   {
	 vec3   eye_position;  ///<	 Точка позиция наблюдателя.
	 vec3   eye_at;        ///<   Точка цель наблюдателя.
	 vec3   eye_up;        ///<   Верх  наблюдателя.

	 //! \brief  Получить вектор направления наблюдения.
	 vec3 direction() const
	 {
		 vec3 res(eye_at-eye_position);
		 res.normalize();
		 return res;
	 }

	 void decomposeInverseView(const mat44& mInvView)
	 {
		 assert(false);
	 // eye_position.x = minv._41;
	 // eye_position.y = minv._42;
	 // eye_position.z = minv._43;

     // dir = *( (vec3*)&minv._31);


     // up  = *( (vec3*)&minv._21);

	 }

   };





 
}

