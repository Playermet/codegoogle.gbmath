
#include "common.h"


camera g_camera;


 

void OnRender(void) 
{
	clear();
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	set_perspective_projection(); 
	g_camera.make_current();

	mat44 mt; mt.setTranslation( 0.0f, 0.0f, -5.0f );
	mat44 mr; mr.setRotationY( time() );
	mat44 m = mr * mt;
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(m);
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

void KeyboardFunc(unsigned char key, int xx, int yy) 
{

	switch (key) 
	{
	case 27:
	//case 'w': g_camera.pos += g_camera.direction() * delta() * 0.1f; break;
	//case 's': g_camera.pos -= g_camera.direction() * delta() * 0.1f; break; 



		break;
	}
}

void SpecialFunc(int key, int xx, int yy) 
{

	switch (key) 
	{
	case 'W': time();  break;

	case GLUT_KEY_UP : g_camera.pos += g_camera.direction() * delta() * 0.1f; break;
	case GLUT_KEY_DOWN : g_camera.pos -= g_camera.direction() * delta() * 0.1f; break;
	}
}

void UpFunc(int key, int x, int y) 
{

	switch (key) 
	{
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : /*deltaMove = 0; */ break;
	}
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

	glutKeyboardFunc(KeyboardFunc);
	glutSpecialFunc(SpecialFunc);
	glutSpecialUpFunc(UpFunc);

 
	glutMainLoop();
 
	return 0;
}