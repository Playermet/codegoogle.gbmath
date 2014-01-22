
#include "common.h"

camera g_camera;



 

void OnRender(void) 
{
	clear();

	set_perspective_projection(); 
	g_camera.make_current();

	mat44 mt; mt.setTranslation( sin( time()) * 1 , sin( time() * 1.5f) * 1 , -5.0f );
	mat44 mr; mr.setRotationY( time() );
	mat44 ms; ms.setScaling( 0.3f*sin( time() * 1.2f )+1 , 0.6f*sin( time() * 0.6f )+1, 0.3f*sin( time() )+1 );

	mat44 m = ms * mr * mt;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	glutSolidTeapot(1.0);
 
	set_ortho_projection();
	draw_str(10, 20, "sample string");


	glutSwapBuffers();
}


void OnResize(int w, int h) 
{
	g_width = w; 
	if(!g_width)  g_width = 1;

	g_height = h;
	if(!g_height) g_height = 1;

	glViewport(0, 0, g_width, g_height);
}




int main(int argc, char* argv[] )
{
 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(1,1);
	glutInitWindowSize(800,600);
	glutCreateWindow("GLUT window");
 
	glutDisplayFunc(OnRender);
	glutIdleFunc(OnRender);
	glutReshapeFunc(OnResize);

 
	glutMainLoop();
 
	return 0;
}