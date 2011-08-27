/**  \file
 \brief context types


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{




#pragma message("ks777: gbmath::context  ПРОВЕРЯТЬ И ДОБАВЛЯТЬ ПО СЕМАНТИКАМ RENDER MONKEY  "  __FILE__)

      //! \brief    semantics of a parameter of type float
      struct float_context_type_e
      {
	      enum e
		  {
		  UNDEFINED  =  0,   ///<  no defined !



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
