﻿/**  \file
 \brief ?????? яяяяяяяяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


//	#error need this class ??


	//!  \brief Клас бесконечный прожектор по лучу (точка основания) и углу прожектора
	class  Projector {
	public:
		Ray3d ray;   ///< луч (центр и направление прожектора)
		float phi; ///< угол конуса

		Projector() {};
		Projector(const Projector& pr) {ray=pr.ray; phi=pr.phi;  };


	}; // Projector



 
}