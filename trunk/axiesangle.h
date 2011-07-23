/**  \file
 \brief  яяяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



	namespace gbmath
	{



		//! \brief  Сборка  ось повотора и угол
		struct AxiesAngle {

				vec3   axies;  ///< ось повотора (должен быть нормализован)
				float   angle; ///< угол поворота

			AxiesAngle() { axies.x = axies.y = axies.z = angle = 0.0f;  }



		};










	}

	