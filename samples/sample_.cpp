
#include "../common.h"





 

void OnRender(void) 
{
	clear();

	set_perspective_projection(); 
	g_camera.make_current();

	mat44 mt; mt.setTranslation(0.0f,0.0f, -5.0f);
	mat44 mr; mr.setRotationY( time() );
	mat44 m = mr * mt;
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(m);
	glutSolidTeapot(1.0);
 
	set_ortho_projection();
	draw_str(10, 20, color4f::MakeWhite(), "sample string");


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