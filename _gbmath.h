/** \file
* \brief MAIN HEADER.
*
*
*

\todo  Поменять ассерты на исключения  
\todo  Поправить операторы для сравнения по эпсилону.
\todo  Перенести в cpp методы матрицы 4x4 .
\todo  Тяжелые методы матриц перенести в cpp
\todo  удалить собственные #ifdef XXXXXX
\todo  Поправить макрозащиту на типы RECT и POINT
 
*
*
*/

#pragma once
#define __GBMATH_H__
 
#define _USE_MATH_DEFINES

#include <math.h>
#include <float.h>

#include <limits>

//#include <stdlib.h>
//#include <cstdio>

#include <string>
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>

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
	#pragma  warning(disable : 4995 4996 4290)
#endif



#include "config.h"

namespace gbmath
{
	// base types
	typedef  unsigned char    byte_t;
}

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
#include "color_const/color_const.h"




#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

// new vectors  template
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

// new matrix template
#include "matrix.hpp"
#include "matrix_quad.hpp"
#include "matrix2x2.hpp"
#include "matrix3x3.hpp"
#include "matrix4x4.hpp"



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
#include "objcontainse.h"
#include "plane.h"
#include "sphere.h"
#include "aabb.h"
#include "oobb.h"
#include "aabbtree.h"
#include "ray3d.h"
#include "axiesangle.h"
#include "cilinder.h"
#include "euler_angles.h"
#include "frustum.h"
#include "eyedata.h"
#include "line3d.h"

#include "transformdata_quat.h"
#include "transformdata_axang.h"

#include "triangle.h"
#include "projector.h"


// proj
#include "perspective_projdata.h"
#include "relat_coord.h"
#include "viewport.h"


// context
#include "float_context_type_e.h"
#include "float_context.h"
#include "matrix4x4_context_type_e.h"
#include "vector_context_type_e.h"
#include "geometry_context.h"




#ifdef _MSC_VER
	#pragma  warning(pop)
#endif

// do include static lib for VC
#if GB_LIB
	#ifndef _LIB_GB_FMATH
		#ifdef _DEBUG
				#pragma comment( lib , "gb_fmath_d.lib" )
		#else
				#pragma comment( lib , "gb_fmath.lib" )
		#endif
	#endif
#endif


// end file