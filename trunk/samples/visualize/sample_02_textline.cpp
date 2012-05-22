
#ifndef GBMATH_USE_OPENGL_DRAWER
#define GBMATH_USE_OPENGL_DRAWER
#endif

#ifndef GBMATH_USE_VISUALIZE_APPLICATION
#define GBMATH_USE_VISUALIZE_APPLICATION
#endif

#include <gbmath/_gbmath.h>

using namespace gbmath;




bool __cdecl OnDrawFrame(void* user_ptr, 
						 gbmath::visualize_application::DrawFrameParams* const dp )
{
	drawer dr;
	dr.set_color_white();
	//dr.draw_str(10, 10, "sample line");


	 visualize_application::Draw_line(30, 30,  "draw line");

	return true;
}


void __cdecl OnResize(void* user_ptr, int w, int y)
{




}





int main()
{
	gbmath::visualize_application::Run(OnDrawFrame, NULL, OnResize, NULL);


	return 0;
}