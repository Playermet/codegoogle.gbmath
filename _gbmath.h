﻿/** \file
* \brief MAIN INCLUDE HEADER.
*
*
*/

#pragma once
#define __GBMATH_H__

#include "__todo.h"
 
#define _USE_MATH_DEFINES


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>
#include <float.h>


#include <limits>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>



 
#ifdef _WIN32
	#if _MSC_VER<1600
		 #include <xmath.h>
	#endif
#endif
 
#ifdef _MSC_VER
	#pragma  warning(push)
	#pragma  warning(disable : 4995 4996 4290 4297)
#endif

//---------------------------------------------------------------------

#include "config.h"

// base types

namespace gbmath
{
	
	typedef  unsigned char    byte_t;


//
// lib assert
//

#ifdef _DEBUG

	#define GBMATH_ASSERT(condition,msge) if( !(condition) ) { gbmath_assert_failed(__FUNCTION__, __FILE__,__LINE__,(msge)); }
	void gbmath_assert_failed( const char* srcfunc, const char* srcfile, const int srcline, const char* msg );

#else

	#define GBMATH_ASSERT(condition,msge)

#endif


}

// new 

namespace gbmath
{

	//! \brief axies data enum x y z 
	struct axies_e
	{
		enum e
		{
			undefined = 0,
			
			ax,
			ay,
			az,
			
			__UNUSED_DECLLAST,
			__UNUSED_FORCE32 = 0x7f000000
		
		};
		
		e value;
	
 
		axies_e()
		{
			value = undefined;
		}

		axies_e(const e val)
		{
			value = val;
		}

		axies_e(const axies_e& val)
		{
			value = val.value;
		}

		void operator = (const e val)
		{
			value = val;
		}
	




	
	};


}


// math const

namespace gbmath
{


	static const float EPSILON	     = 1.0e-6f;

	static const float PI            = 3.1415926536f; ///<   PI
	static const float C1BYPI        = 0.3183098862f; ///<   1/PI

	static const float PI2           =  6.283185307f; ///<   2*PI
	static const float PI_DIV_2      =  1.570796326f; ///<   PI/2
	static const float PI_DIV_4      =  0.785398163f; ///<   PI/4
	static const float PI_DIV_6      =  0.523598776f; ///<   PI/6

	static const float PI_DIV_180    =  0.017453292f; ///<   PI/180
	static const float C180DIVPI     =  57.29577951f; ///<   180/PI

	static const float C3PIDIV4     = 2.35619449f;    ///<   3/4 PI
	static const float PI2_INV      = 0.159154943f;   ///<   1/(2PI)
	static const float CINV360      = 0.002777778f;   ///<   1/360
	static const float C180         = 180.0f;
	static const float C360         = 360.0f;
	static const float HALF         = 0.5f;
	static const float TWO          = 2.0f;
	static const float LN10         = 2.302585093f;

	static const float SQRT_2       = 1.4142135624f;   ///<   sqrt(2)
	static const float SQRT_HALF    = 0.7071067812f;   ///<   sqrt(1/2)

	static const float E            = 2.718281828459f; ///<  e


}

 

#include "point.h"
#include "rectangle.h"

#include "scalar.h"

#include "forward_decl.h"

// color
 
#include "color3f.h"
#include "color3_24.h"
 
#include "color4f.h"
#include "color4_32.h"
#include "object_color_type_e.h"
#include "color_functions.h"

 
#include "color_const.h"



#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
 
#include "mat22.h"
#include "mat33.h"
#include "mat44.h"

#include "matrix_stack.h"
#include "quaternion.h"

// 2d
#include "normal2.h"
#include "point2.h"
#include "size2d.h"
#include "ray2d.h"
#include "line2d.h"
#include "circle.h"
#include "rect.h"
#include "segment2.h"


// 3d
#include "normal3.h"
#include "point3.h"
#include "size3d.h"

#include "obj_contains_e.h"
#include "plane.h"    
#include "sphere.h"
#include "aabb.h"
#include "oobb.h"
 
 
#include "ray3d.h"
	 
#include "axies_angle.h"
#include "cilinder.h"
#include "euler_angles.h"
#include "frustum.h"		  
#include "eyedata.h" 
#include "line3d.h"
#include "transformdata_quat.h"
#include "transformdata_axang.h"
#include "triangle_2d.h"
#include "triangle.h"
#include "projector.h"
#include "segment3.h"

// proj
#include "clip_values.h"
#include "orthographic_projection_data.h"
#include "perspective_projection_data.h"
#include "related_coord.h"
 
 
#include "matrix4x4_context_type_e.h"
#include "vector_context_type_e.h"
 

// camera
#include "arc_ball.h"
#include "base_camera.h"
 
#include "first_person_camera.h"
#include "model_view_camera.h"

// math dependence
#include "dependence_on_function.h"

 
#include "drawer.h"

  

#ifdef _MSC_VER
	#pragma  warning(pop)
#endif

 