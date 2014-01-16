/** \file
 \brief  forward-declaration


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{


namespace scalar
{


}


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

class  Quaternion;

 

struct size2d;

class normal2;
class point2;
class Rect;
class Circle;
class line3d;
class ray3d;

 
//-------------------------------------------------------------------------

 

struct size3d;
class normal3;
class point3;

struct axies_angle;
class sphere;
class aabb;
class ray3d;
class line3d;
class euler_angles;
class triangle;

struct plane_s;

class  projector;
class  Frustum;
class  Cilinder;

struct TransformData;

 

//-------------------------------------------------------------------------
 

struct PerspectiveProjData;
struct related_coord;

struct vieport_s;
class ViewportZ;

 

//-------------------------------------------------------------------------

 

struct float_context_type_e;
class float_context;
struct vector_context_type_e;
struct matrix4x4_context_type_e;
class geometry_context;


 

//-------------------------------------------------------------------------


}
