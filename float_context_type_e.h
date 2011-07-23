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
	
	


#pragma message("ks777: gb::fmath::context  ПРОВЕРЯТЬ И ДОБАВЛЯТЬ ПО СЕМАНТИКАМ RENDER MONKEY  "  __FILE__)

      //!  семантика параметра типа  float
      struct float_context_type_e
      {
	      enum e
		  {
		  UNDEFINED  =  0,   ///< не определено !


 
		  TIME,
 
		  COSTIME,
		  SINTIME,
		  TANTIME,

		  //TIME0_1,
		  //COSTIME0_1,
		  //SINTIME0_1,
		  //TANTIME0_1,
 
		  //TIMESPEED,

		  //TAN0_2PI,
		  //COSTIME0_2PI,
		  //SINTIME0_PI,
		  //TANTIME0_2PI,
		  //TIMECYCLEPERIOD,

		  FPS,

		  TIMEELAPSED,


		  VIEWPORTWIDTH,
		  VIEWPORTHEIGHT,

		  VIEWPORTWIDTHINVERSE,
		  VIEWPORTHEIGHTINVERSE,

		  FOV,

		  FARCLIPPLANE,
		  NEARCLIPPLANE,

		  ASPECT,

			  /*
		  RANDOMFRACTION1PERPASS,
		  RANDOMFRACTION2PERPASS,
		  RANDOMFRACTION3PERPASS,
		  RANDOMFRACTION4PERPASS,

		  RANDOMFRACTION1PEREFFECT,
		  RANDOMFRACTION2PEREFFECT,
		  RANDOMFRACTION3PEREFFECT,
		  RANDOMFRACTION4PEREFFECT,
			 */
 
		  //PASSINDEX,

		  RIGTHMOUSEBUTTON,
		  LEFTMOUSEBUTTON,
		  MIDDLEMOUSEBUTTON,

		  //MIDDLEMOUSEBUTTON,
			 

		  MOUSECOORDINATEX,
		  MOUSECOORDINATEY,

		  MOUSECOORDINATEXNDC,
		  MOUSECOORDINATEYNDC,
		  MODELBOUNDINGSPHERERADIUS,



		//  SPECULARPOWER,

		//  ROTATEZ,

		//  BRIGHTNESS,

		 // CONTRAST,

		  //ALPHA,
		  //LIGTHMAPINTENSITY,
		  //ANIMATESPEED,
 


		  UNUSED_DECLARED_LAST,	///< Этот пункт не используется. Декларируется последним.
		  UNUSED_FORCE32 = 0xff000000

		  };



		 static std::string tostr(const float_context_type_e::e);
		 static bool fromstr(float_context_type_e::e&, const char*);


	  }; 

	
	
	
	
	
	
	
	
	
	}
}
