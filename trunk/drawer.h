/**   \file
 \brief   render math objects throoth OPenGL

*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

#ifdef GBMATH_USE_OPENGL_DRAWER

#include <gl\gl.h>

namespace gbmath 
{

	class drawer {
	public:
	
		drawer();
		~drawer() {}	
			
			void set_transform_matrix_world (const mat44&);
			void set_transform_matrix_view  (const mat44&);	
			void set_transform_matrix_proj  (const mat44&);
			
			void mul_world(const mat44& m);

			void set_color(float r, float g, float b, float a) { glColor4f(r,g,b,a); }
			void set_color(const color4f& a) { set_color(a.r, a.g, a.b, a.a); }
			
			void set_color_red()   { glColor4f( 1.0f , 0.0f , 0.0f , 1.0f ); }
			void set_color_green() { glColor4f( 0.0f , 1.0f , 0.0f , 1.0f ); }
			void set_color_blue()  { glColor4f( 0.0f , 0.0f , 1.0f , 1.0f ); }
			void set_color_white() { glColor4f( 1.0f , 1.0f , 1.0f , 1.0f ); }
			void set_color_black() { glColor4f( 0.0f , 0.0f , 0.0f , 1.0f ); }

			// TODO: pink, yellow , ......


			void set_pointsize(int size) {  glPointSize( (GLfloat) size ); }
			
			void draw_points(const vec3* points, const int num);
			void draw_lines(const vec3* points, const int num);

			void draw_line(const vec3& p1, const vec3& p2);

			void draw_string(int x, int y, const char* _Format, ... ) ;
			
			void draw_rect(const Rectangle& r) ;		
		
			
		
		private:
			mat44 m_world;
			mat44 m_view;
	};

}

#endif // #ifdef GBMATH_USE_OPENGL_DRAWER
