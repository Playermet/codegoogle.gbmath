/**  \file
 \brief ?????? яяяяяяяяяяяяяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
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
}
