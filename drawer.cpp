

#include "_gbmath.h"


#ifdef GBMATH_USE_OPENGL_DRAWER

#include "drawer.h"  



namespace gbmath
{
 
 
	drawer::drawer() 
	{
		m_world.setIdentity();
		m_view.setIdentity();

		set_pointsize(2);
	
	}
	
	


	void drawer::set_transform_matrix_world (const mat44& m) 
	{
		GLint  emode;
		glGetIntegerv(GL_MATRIX_MODE, &emode );
		glMatrixMode(GL_MODELVIEW_MATRIX);
		m_world = m;
		mat44 mmv = m_world  *  m_view;
		glLoadMatrixf(&mmv._11); 
		glMatrixMode( emode );
	}
	
	void drawer::set_transform_matrix_view  (const mat44& m) 
	{  
		GLint  emode;
		glGetIntegerv(GL_MATRIX_MODE, &emode );
		glMatrixMode(GL_MODELVIEW_MATRIX);
		m_view = m;
		mat44 mmv = m_world  *  m_view;
		glLoadMatrixf(&mmv._11);
		glMatrixMode( emode );
	}
	
	void drawer::set_transform_matrix_proj  (const mat44& m) 
	{  
		GLint  emode;
		glGetIntegerv(GL_MATRIX_MODE, &emode );
		glMatrixMode(GL_PROJECTION_MATRIX );
		glLoadMatrixf(&m._11); 
		glMatrixMode( emode );
	}	

	void drawer::mul_world(const mat44& m)
	{
		m_world *= m;
		glMatrixMode(GL_MODELVIEW_MATRIX);	
		mat44 mmv = m_world  *  m_view;
		glLoadMatrixf(&mmv._11); 
	}

	void drawer::draw_points(const vec3* points, const int num)
	{
		assert(false);
		glBegin(GL_POINTS);
		for(int c=0; c<num; c++)
		{
			const vec3* pcurr = points + c;
			vec3 pos = *pcurr;
			glVertex3f( pos.x , pos.y , pos.z );		
		}		
		glEnd();
	}
	
	
	void drawer::draw_lines(const vec3* points, const int num) 
	{
		assert(false);
		glBegin(GL_LINES);
		for(int c=0; c<num; c++)
		{
			const vec3* pcurr = points + c;
			vec3 pos = *pcurr;
			glVertex3f( pos.x , pos.y , pos.z );		
		}		
		glEnd();
	}

	void drawer::draw_line(const vec3& p1, const vec3& p2)
	{
	/*
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP 
	*/

		glBegin(GL_LINES);    // GL_LINES
			glVertex3f( p1.x , p1.y , p1.z );
			glVertex3f( p2.x , p2.y , p2.z );
		glEnd();
	}

	void drawer::draw_string(int x, int y, const char* _Format, ... ) 
	{
		assert(false);
		
		
	}

	void drawer::draw_rect(const Rectangle& r) 
	{
		assert(false);
			//int left; //< позиция по X.
			//int top;  //< позиция по Y.
			//int width;  //< ширина.
			//int height; //< высота.
	
		// 5 points
		glBegin(GL_LINES);
		for(int c=0; c<5; c++)
		{
			glVertex2i( r.left , r.top );
			glVertex2i( r.left + r.width , r.top );			
			glVertex2i( r.left + r.width , r.top + r.height );			
			glVertex2i( r.left , r.top + r.height );			
			glVertex2i( r.left , r.top ); // last is first			
		}
		glEnd();	
	}
	
	void drawer::draw_str(int x, int y, const char* _Format, ... )
	{
		assert(false);
	
	
	}
	
	void drawer::draw_box(const vec3& min, const vec3& max)
	{
	assert(false);
	}
	
	void drawer::draw_sphere(const vec3& center, const float radius)
	{
	assert(false);
	}

	

}

#endif // GBMATH_USE_OPENGL_DRAWER

