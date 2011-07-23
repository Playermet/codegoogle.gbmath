/**  \file 
 \brief яяяяяяяя
 
 
*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
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
}
