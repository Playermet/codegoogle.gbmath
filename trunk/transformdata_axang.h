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
	
	





   //! \brief  Сборка трансформации , но для повотора импользуется ось и угол.
   struct TransformData2 
   {
	   vec3        scaling;
	   AxiesAngle  rotation;
	   vec3        translatiion;
   };
	
	
	
	
	
	
	
	
	
	}
}
