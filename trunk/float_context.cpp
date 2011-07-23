
#include "_gbmath.h"


#ifdef _MSC_VER
	#pragma  warning(push)
	#pragma  warning(disable : 4290)
#endif


 
namespace gbmath
{




//=============================================================
float float_context::getValue_by_context_type(
						 const float_context_type_e::e val
									   ) const    throw(std::runtime_error&)
{

switch(val)
	{

case float_context_type_e::TIME : { return time;} break;

case float_context_type_e::COSTIME : { return cos(time); } break;
case float_context_type_e::SINTIME : { return sin(time); } break;
case float_context_type_e::TANTIME : { return tan(time); } break;

//
//case float_context_type_e::TIME0_1 : {XXXXXXXX} break;
//case float_context_type_e::COSTIME0_1 : {XXXXXXXX} break;
//case float_context_type_e::SINTIME0_1 : {XXXXXXXX} break;
//case float_context_type_e::TANTIME0_1 : {XXXXXXXX} break;
//
//case float_context_type_e::TIMESPEED : {XXXXXXXX} break;
//
//case float_context_type_e::TAN0_2PI : {XXXXXXXX} break;
//case float_context_type_e::COSTIME0_2PI : {XXXXXXXX} break;
//case float_context_type_e::SINTIME0_PI : {XXXXXXXX} break;
//case float_context_type_e::TANTIME0_2PI : {XXXXXXXX} break;
//case float_context_type_e::TIMECYCLEPERIOD : {XXXXXXXX} break;
//

case float_context_type_e::FPS : { return (float)fps; } break;

case float_context_type_e::TIMEELAPSED : { return timeElapsed;} break;


case float_context_type_e::VIEWPORTWIDTH : { return (float)viewport.width;  } break;
case float_context_type_e::VIEWPORTHEIGHT : {return (float)viewport.height; } break;
case float_context_type_e::VIEWPORTWIDTHINVERSE :  { return 1.0f/(float)viewport.width;  } break;
case float_context_type_e::VIEWPORTHEIGHTINVERSE : { return 1.0f/(float)viewport.height; } break;

case float_context_type_e::FOV : { return projData.fovy; } break;


case float_context_type_e::FARCLIPPLANE  : { return projData.zf; } break;
case float_context_type_e::NEARCLIPPLANE : { return projData.zn; } break;

//
//case float_context_type_e::RANDOMFRACTION1PERPASS : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION2PERPASS : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION3PERPASS : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION4PERPASS : {XXXXXXXX} break;
//
//case float_context_type_e::RANDOMFRACTION1PEREFFECT : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION2PEREFFECT : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION3PEREFFECT : {XXXXXXXX} break;
//case float_context_type_e::RANDOMFRACTION4PEREFFECT : {XXXXXXXX} break;
//
//case float_context_type_e::PASSINDEX : {XXXXXXXX} break;
//case float_context_type_e::MIDDLEMOUSEBUTTON : {XXXXXXXX} break;
//

case float_context_type_e::RIGTHMOUSEBUTTON :
	{
	 if(mouseData.bRIghtButtonDown)
		 {
		 return 1.0f;
		 }
	 else
		 {
		 return 0.0f;
		 }
	} break;
case float_context_type_e::LEFTMOUSEBUTTON :
	{
	if(mouseData.bLeftButtonDown)
		{
		return 1.0f;
		}
	else
		{
		return 0.0f;
		}
	} break;

case float_context_type_e::MOUSECOORDINATEX : { return (float)mouseData.x; } break;
case float_context_type_e::MOUSECOORDINATEY : { return (float)mouseData.y; } break;

//case float_context_type_e::MOUSECOORDINATEXNDC : {XXXXXXXX} break;
//case float_context_type_e::MOUSECOORDINATEYNDC : {XXXXXXXX} break;
case float_context_type_e::MODELBOUNDINGSPHERERADIUS :
	{
	         return modelBoundingSphereRadius;
	} break;

case float_context_type_e::ASPECT : {  return  projData.aspect; } break;

//case float_context_type_e::SPECULARPOWER : {XXXXXXXX} break;
//case float_context_type_e::ROTATEZ : {XXXXXXXX} break;
//case float_context_type_e::BRIGHTNESS : {XXXXXXXX} break;
//case float_context_type_e::CONTRAST : {XXXXXXXX} break;
//case float_context_type_e::ALPHA : {XXXXXXXX} break;
//case float_context_type_e::LIGTHMAPINTENSITY : {} break;
//case float_context_type_e::ANIMATESPEED : {} break;



			default:
				{

				}


	 }

throw std::runtime_error("value not found");
	return 0.0f;
}


}

#ifdef _MSC_VER
	#pragma  warning(pop)
#endif