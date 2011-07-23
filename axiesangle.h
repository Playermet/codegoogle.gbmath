/**  \file
 \brief  яяяяяяяяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	

		//! \brief  Сборка  ось повотора и угол
		struct AxiesAngle {
		
				vec3   axies;  ///< ось повотора (должен быть нормализован)
				float   angle; ///< угол поворота		
		
			AxiesAngle() { axies.x = axies.y = axies.z = angle = 0.0f;  }



		};
		
	
	
	
	
	
	
	
	
	
	}
}
