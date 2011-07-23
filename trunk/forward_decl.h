/** \file fmath_forward_decl.h
 \brief Для gb::fmath форвард-декларации.


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif
 

namespace gb
{
namespace fmath
{

//---------------------------------------------------------------

namespace scalar
{


}
//---------------------------------------------------------------
 
// color

template <typename T>
struct color3;

template <typename T>
struct color4;

struct color4_32;

struct color4f;
struct color3_24;



struct vec2;
struct vec3;
struct vec4;

struct mat22;
struct mat33;
struct mat44;

template <typename T>
struct matrix2x2;

template <typename T>
struct matrix3x3;

template <typename T>
struct matrix4x4;


class  Quaternion;

 
//namespace geom2d  {

struct Size2d;

class Normal2;
class Point2;
class Rect;
class Circle;
class Line3d;
class Ray3d;

//}

//---------------------------------------------------------------

//namespace geom3d {

struct Size3d;
class Normal3;
class Point3;

struct AxiesAngle;
class Sphere;
class AABB;
class Ray3d;
class Line3d;
class euler_angles;
class Triangle;

struct plane_s;

class  Projector;
class  Frustum;
class  Cilinder;

struct TransformData;

//}


//---------------------------------------------------------------


//namespace proj {

struct PerspectiveProjData;
struct RelatCoord;

struct vieport_s;
class ViewportZ;

// }

//---------------------------------------------------------------

namespace context 
{

struct float_context_type_e;
class float_context;
struct vector_context_type_e;
struct matrix4x4_context_type_e;
class GeometryContext;
 

}


//---------------------------------------------------------------
}
// end namespace fmath

}
// end namespace gb

// end file