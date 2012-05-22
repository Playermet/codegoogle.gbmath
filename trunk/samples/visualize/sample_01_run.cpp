
#ifndef GBMATH_USE_OPENGL_DRAWER
#define GBMATH_USE_OPENGL_DRAWER
#endif

#ifndef GBMATH_USE_VISUALIZE_APPLICATION
#define GBMATH_USE_VISUALIZE_APPLICATION
#endif

#include <gbmath/_gbmath.h>





bool __cdecl OnDrawFrame(void* user_ptr, gbmath::visualize_application::DrawFrameParams* const dfp )
{


	return true;
}


void __cdecl OnResize(void* user_ptr, int w, int y)
{




}





int main()
{
	gbmath::visualize_application::Run(OnDrawFrame, OnResize, NULL);


	return 0;
}