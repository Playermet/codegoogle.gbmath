/**   \file
 \brief   Visualize math values through OpenGL .

*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


#ifdef WIN32
#if GBMATH_USE_VISUALIZE_APPLICATION


#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#pragma  comment(lib , "opengl32.lib")
#pragma  comment(lib , "glu32.lib")


 

namespace gbmath
{


	//! \brief  visualize application   (WIN32 only)
	class visualize_application {
	public:

		struct DrawFrameParams {

			HWND	hWnd;
		
			float  time;
			float  delta;

			drawer* const dr;


			DrawFrameParams(drawer* const _dr) : dr(_dr) 
			{
			
			}

		};


		typedef bool (__cdecl *OnDrawFrame)(void* user_ptr, DrawFrameParams* const dfp );
		typedef void (__cdecl *OnResize)(void* user_ptr, int w, int y);
 


		static int Run( OnDrawFrame onDraw,  OnResize onResize, void* user_ptr);
	
	
	};




	namespace test 
	{
		void do_test_visualize_application();
	}

}


#endif // GBMATH_USE_VISUALIZE_APPLICATION
#endif // WIN32
