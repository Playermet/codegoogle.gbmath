/**  \file
 \brief  яяяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



	namespace gbmath
	{


#pragma message("!!!  Need add operators:  << >> to from str "  __FILE__   )

		//! \brief  Сборка  ось повотора и угол
		struct axies_angle {

				vec3   axies;  ///< ось повотора (должен быть нормализован)
				float   angle; ///< угол поворота

			axies_angle() { axies.x = axies.y = axies.z = angle = 0.0f;  }



		};










	}

	