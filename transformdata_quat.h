/**  \file
 \brief ??????


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	
	


   //! \brief Сборка из данных трансформации: скалирование(вектор) + поворот(кват.) + позиция(вектор).
   struct TransformData
   {
	    vec3         vScaling;      ///< масштабирование
	    Quaternion   qRotation;     ///< вращение
	    vec3         vTranslation;  ///<  позиция
   };
	
	
	
	
	
	
	
	
	}
}
