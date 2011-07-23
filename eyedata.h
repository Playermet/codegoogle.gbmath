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
   struct EyeData
   {
	 vec3   eyePosition;  ///<	 Точка позиция наблюдателя.
	 vec3   eyeAt;        ///<   Точка цель наблюдателя.
	 vec3   eyeUp;        ///<   Верх  наблюдателя.

	 //! \brief  Получить вектор направления наблюдения.
	 vec3 direction() const
	 {
		 vec3 res(eyeAt-eyePosition);
		 res.normalize();
		 return res;
	 }

	 void decomposeInverseView(const mat44& mInvView)
	 {
		 assert(false);
	 // eyePosition.x = minv._41;
	 // eyePosition.y = minv._42;
	 // eyePosition.z = minv._43;

     // dir = *( (vec3*)&minv._31);


     // up  = *( (vec3*)&minv._21);

	 }

   };





 
}

