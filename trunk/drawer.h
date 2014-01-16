/**   \file
 \brief   Drawing of mathematical objects through OpenGL .

*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


#ifdef GBMATH_USE_OPENGL_DRAWER

#include <gl/gl.h>


namespace gbmath 
{

	//!  \brief  Drawing of mathematical objects through OpenGL .
	class drawer 
	{
	public:
	
		drawer();
		~drawer() { }	
		
		void set_transform_matrix_world (const mat44&);
		void set_transform_matrix_view  (const mat44&);	
		void set_transform_matrix_proj  (const mat44&);
		
		void mul_world(const mat44& m);



		void drawer::set_color(float r, float g, float b, float a) 
		{ 
			glColor4f(r,g,b,a); 
		}

		void drawer::set_color(const color4f& a) 
		{ 
			set_color(a.r, a.g, a.b, a.a); 
		}

		void drawer::set_pointsize(int size) 
		{  
			glPointSize( (GLfloat) size ); 
		}


		
		void set_color_red()   { set_color( 1.0f , 0.0f , 0.0f , 1.0f ); }
		void set_color_green() { set_color( 0.0f , 0.6f , 0.0f , 1.0f ); }
		void set_color_blue()  { set_color( 0.0f , 0.0f , 1.0f , 1.0f ); }
		void set_color_white() { set_color( 1.0f , 1.0f , 1.0f , 1.0f ); }
		void set_color_black() { set_color( 0.0f , 0.0f , 0.0f , 1.0f ); }

		void set_color_gray()    { set_color( 0.752941f,  0.752941f,  0.752941f,  1.0f ); }
		void set_color_coral()   { set_color( 1.0f,       0.498039f,  0.0f,       1.0f ); }
		void set_color_aqua()    { set_color(  0.0f,       1.0f,       1.0f,      1.0f ); }
		void set_color_yellow()  { set_color( 1.0f,      1.0f,       0.0f,        1.0f ); }
		void set_color_fuchsia() { set_color( 1.0f,       0.0f,       1.0f,       1.0f ); }
		void set_color_lime()    { set_color( 0.0f,       1.0f,       0.0f,       1.0f ); }
		void set_color_brown()   { set_color( 0.647059f,  0.164706f,  0.164706f,  1.0f ); }


		
		void draw_points(const vec3* points, const int num);
		void draw_lines(const vec3* points, const int num);

		void draw_line(const vec3& p1, const vec3& p2);

		void draw_string(int x, int y, const char* _Format, ... ) ;
		
		void draw_rect(const Rectangle& r) ;	

		void draw_str(int x, int y, const char* _Format, ... );
		void draw_box(const vec3& min, const vec3& max);
		void draw_sphere(const vec3& center, const float radius);
		
		
	
				
		private:
			mat44 m_world;
			mat44 m_view;
	};

}
 

#endif // #ifdef GBMATH_USE_OPENGL_DRAWER
