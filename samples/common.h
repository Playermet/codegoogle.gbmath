


#pragma once

#pragma warning(disable : 4996)



#include "../_gbmath.h"
using namespace gbmath;


#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

#include <stdarg.h>
#include <assert.h>
#include <time.h>

#pragma comment(lib , "opengl32.lib")
#pragma comment(lib , "glu32.lib")
#pragma comment(lib , "freeglut.lib")



int g_width  = 0;
int g_height = 0;

float g_far = 1000.0f;
float g_fov = PI * 0.25f;

void * g_font = NULL;

 

struct Cgl
{
	void operator = ( const color4f& arg ) { glColor4f(arg.r,arg.g,arg.b,arg.a); }

}; Cgl ggl;

void draw_str(int x, int y, const char* str)
{
	glRasterPos3f( (GLfloat)x, (GLfloat)y, 0.0f);
	for( size_t c=0; str[c] != '\0'; c++ )
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[c] );
	}
}

void draw_strf(int x, int y, const char* _Format , ... )
{
	char buffer[2048];
	buffer[0] = '\0';
	va_list ap;
	va_start( ap, _Format );
	vsprintf( buffer, _Format, ap );
	va_end( ap );
	draw_str(  x,   y, buffer);
}



float time()
{
	static float st_tstart = 0.0f;
	if(st_tstart == 0.0f)
	{
		st_tstart = (float)clock() / (float)CLOCKS_PER_SEC ;
		return 0.0f;
	}
 
	float res = ( (float)clock() / (float)CLOCKS_PER_SEC ) - st_tstart;
	return res;
}

float delta()
{
	int tmp = glutGet(GLUT_ELAPSED_TIME);
	return  0.001f * (float)tmp;
}

void clearbuffer()
{
	glClear(GL_COLOR_BUFFER_BIT );
}

void cleardeph()
{
	glClear( GL_DEPTH_BUFFER_BIT);
}

void clear()
{
	glClearColor( 0.0f, 0.0f, 0.5f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

struct camera
{
	vec3 pos;
	vec3 at;

	camera()
	{
		pos = vec3( 0.0f , 0.0f , 0.0f );
		at  = vec3( 0.0f , 0.0f , 1.0f );
	}

	vec3 direction()
	{
		return (at-pos).normalize();
	}

	void make_current()
	{
		gluLookAt(  (GLdouble)pos.x, (GLdouble)pos.y, (GLdouble)pos.z,	(GLdouble)at.x, (GLdouble)at.y,  (GLdouble)at.z, (GLdouble)0, (GLdouble)1, (GLdouble)0    );
	}
};

//camera g_camera;

struct target_camera
{
	vec3 pos;
	vec3* at;

	target_camera() : at(NULL) {}

	vec3 direction()
	{
		return (*at - pos).normalize();
	}

	void make_current()
	{
		gluLookAt(  (GLdouble)pos.x, (GLdouble)pos.y, (GLdouble)pos.z,	(GLdouble)at->x, (GLdouble)at->y,  (GLdouble)at->z, (GLdouble)0, (GLdouble)1, (GLdouble)0    );
	}

};


void set_ortho_projection() 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, g_width, g_height, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void set_perspective_projection() 
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();;
	gluPerspective( radiansToDegree( g_fov ), (float)g_width / (float)g_height, g_far * 0.001f,  g_far);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void set_lokat( const vec3& eye, const vec3& center )
{
	gluLookAt( (GLdouble)eye.x,    (GLdouble)eye.y,     (GLdouble)eye.z,
			   (GLdouble)center.x, (GLdouble)center.y,  (GLdouble)center.z,
			   (GLdouble)0.0,      (GLdouble)1.0,       (GLdouble)0.0    );
}

void draw(const aabb& val)
{
	assert(false);
}

