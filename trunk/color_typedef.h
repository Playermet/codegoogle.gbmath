/**  \file
* \brief  Mononhromnoe value
*
*
*/

#pragma once

 
#include "color3.h"
#include "color4.h"

//#include "color3f.h"
//#include "color4f.h"

 
namespace gbmath
{


 

/** \brief  Mononhromnoe value 1 byte . */
typedef uint8_t   color_mono_8b_t;


/** \brief  Mononhromnoe value    2  bytes .  */
struct color_mono16b_s
{
	  union
	  {
		struct 
		{ 
			uint8_t    _1, _0 ; 
		};

		uint8_t bytes[2];

		unsigned short ush;
	  };



};


		//typedef  color_rgb24_s    color_rgb_s;

		/** \brief float-цвет в виде структуры.
		Для выполнения операций использовать  статические методы класса Color4f.  */
		//struct color4f_s : public color4<float>
		//{
		//float r, g, b, a;
		//};
		// typedef  color4<float>  color4f_s;




		/** \brief  Обозначение целочисленого 4-х компонентного  цвета по байтам.   */
		//struct color_rgba_s
		//{
		//  uint8_t r, g, b, a;
		//};


// repl color4_32		typedef color4<uint8_t> color_rgba_s;







	 /** \brief  Целочисленый 3-х байтовый цвет  без альфа-компоненты .   */
	 //struct color_rgb24_s
	 //{
	 //  uint8_t r, g, b;
	 //};


// repl color3_24	 typedef color3<uint8_t> color_rgb_s;




	// /** \brief Целочисленый 4-х байтовый  цвет.   */
	// typedef uint32_t    color32_t;




}
