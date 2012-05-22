/** \file
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

#include <math.h>
#include <float.h>

#include <limits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include <assert.h>
 
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
	
		//

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


	static const float EPSILON	  =	1.0e-6f;

	static const float PI       = 3.1415926536f; ///<   PI
	static const float C1BYPI    = 0.3183098862f; ///<   1/PI

	static const float PI2         =  6.283185307f; ///<  	2*PI
	static const float PI_DIV_2      =  1.570796326f; ///<   PI/2
	static const float PI_DIV_4      =  0.785398163f; ///<   PI/4
	static const float PI_DIV_6      =  0.523598776f; ///<   PI/6

	static const float PI_DIV_180    =  0.017453292f; ///<   PI/180
	static const float C180DIVPI    =  57.29577951f; ///<   180/PI

	static const float C3PIDIV4     = 2.35619449f;   ///<   3/4 PI
	static const float PI2_INV      = 0.159154943f;  ///<   1/(2PI)
	static const float CINV360      = 0.002777778f;  ///<   1/360
	static const float C180         = 180.0f;
	static const float C360         = 360.0f;
	static const float HALF     = 0.5f;
	static const float TWO         = 2.0f;
	static const float LN10        = 2.302585093f;

	static const float SQRT_2       = 1.4142135624f; ///< sqrt(2)
	static const float SQRT_HALF    = 0.7071067812f; ///< sqrt(1/2)

	static const float E           = 2.718281828459f; ///<  e


}


// include lib headers



#include "point.h"
#include "rectangle.h"

#include "scalar.h"

#include "forward_decl.h"

// color
#include "color3.h"
#include "color3f.h"
#include "color3_24.h"
#include "color4.h"
#include "color4f.h"
#include "color4_32.h"
#include "object_color_type_e.h"
#include "color_functions.h"

//#include "color_const/color_const.h"
#include "color_const.h"



#include "vec2.h"
#include "vec3.h"
#include "vec4.h"


 
// // new vectors  template
//#include "vector2.hpp"
//#include "vector3.hpp"
//#include "vector4.hpp"
 



 
//	// new matrix template
//#include "matrix.hpp"
//#include "matrix_quad.hpp"
//#include "matrix2x2.hpp"
//#include "matrix3x3.hpp"
//#include "matrix4x4.hpp"
 


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



// 3d
#include "normal3.h"
#include "point3.h"
#include "size3d.h"

#include "obj_contains_e.h"
#include "plane.h"    
#include "sphere.h"
#include "aabb.h"
#include "oobb.h"
#include "aabb_tree.h"
 
#include "ray3d.h"
	 
#include "axies_angle.h"
#include "cilinder.h"
#include "euler_angles.h"
#include "frustum.h"		  
#include "eyedata.h" 
#include "line3d.h"
#include "transformdata_quat.h"
#include "transformdata_axang.h"
#include "triangle.h"
#include "projector.h"

 ///

// proj
#include "clip_values.h"
#include "orthographic_projection_data.h"
#include "perspective_projection_data.h"
#include "related_coord.h"
#include "viewport.h"


// context
#include "valueserver.h"
#include "float_context_type_e.h"
#include "float_context.h"

#include "matrix4x4_context_type_e.h"

#include "vector_context_type_e.h"

#include "geometry_context.h"


// camera
#include "arc_ball.h"
#include "base_camera.h"
#include "target_camera.h"
#include "first_person_camera.h"
#include "model_view_camera.h"

// math dependence
#include "dependence_on_function.h"



 

//! render math opt
#define  GBMATH_USE_OPENGL_DRAWER    0 
 
#include "drawer.h"


#define  GBMATH_USE_VISUALIZE_APPLICATION    0

#include "visualize_application.h"




//-------------------------------------------------------------


#ifdef _MSC_VER
	#pragma  warning(pop)
#endif


 
//// do include static lib for VC
//#if GB_LIB
//	#ifndef _LIB_GB_FMATH
//		#ifdef _DEBUG
//				#pragma comment( lib , "gb_fmath_d.lib" )
//		#else
//				#pragma comment( lib , "gb_fmath.lib" )
//		#endif
//	#endif
//#endif
 


// end file