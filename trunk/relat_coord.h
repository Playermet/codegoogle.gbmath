/**  \file
 \brief яяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	

		//! \brief Относительные экранные координаты.
		struct RelatCoord 
		{

			  float x;
			  float y; 

			/** \brief Конвертация абсолютных экранных координат в 
				   относительные экранные координаты, 
				    по размеру экрана (vpWidth и vpHeight)  ПРОВЕРЕНО !  */
			inline void   fromScreenCoord( // ScreenCoord_To_RelatCoord(
									            const  vec2& vScrCoord, 
									            const int vpWidth, const int vpHeight ) 
			{
				  x = - ( ((float)vpWidth /2.0f) - vScrCoord.x ) / ((float)vpWidth /2.0f);
				  y = - ( ((float)vpHeight/2.0f) - vScrCoord.y ) / ((float)vpHeight/2.0f);
			}


			/** \brief Конвертация относительных  экранных координат в  абсолютные
				  экранные координаты, 
				  по размеру экрана (vpWidth и vpHeight) ПРОВЕРЕНО !    */
			inline  vec2  toScreenCoord(const int vpWidth, const int vpHeight ) const
			{
				    vec2 res;
				   res.x =  ((float)vpWidth /2.0f) +   x * ((float)vpWidth /2.0f);
				   res.y =  ((float)vpHeight/2.0f) +   y * ((float)vpHeight/2.0f);
				   return res; 
			}


		};
			
	}
}
