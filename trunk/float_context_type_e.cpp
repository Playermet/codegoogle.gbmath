
#include "fmath.h"


//using namespace gb::fmath;

namespace gb
{
namespace fmath
{
 

	static void __str_touper(std::string& str)
	{
		for(size_t c=0; c<str.length(); c++)
		{
			char curr = str[c];
			curr = toupper(curr);
			str[c] = curr;
		}
	}






//=============================================================
std::string  float_context_type_e::tostr(const float_context_type_e::e val)
{

 assert(false);

 std::string res;
 switch(val)
	 {
	 case 1: {} break;
	 //case XXXXXX: {} break;


	 default: 
		 {

		 }

	 }

  return res;
}

//=============================================================
bool float_context_type_e::fromstr(float_context_type_e::e& valOut, 
								   const char* strarg)
{
std::string str = strarg;
   __str_touper(str);

	/***************************
   if("XXXXX" == str)
   {
	   valOut =  XXXXXX;
	   return true;
   } 
   ******************************/
 

   if( ("TIME" == str) || ("TIME0_X" == str) )
   {
	   valOut =  TIME;
	   return true;
   } 

   if( ("COSTIME" == str) || ("COSTIME0_1" == str))
   {
	   valOut =  COSTIME;
	   return true;
   } 

   if( ("SINTIME" == str) || ("SINTIME0_1" == str))
   {
	   valOut =  SINTIME;
	   return true;
   } 

   if( ("TANTIME" == str) || ("TANTIME0_1" == str))
   {
	   valOut =  TANTIME;
	   return true;
   } 

   /**************
   if("XXXXX" == str)
   {
	   valOut =  XXXXXX;
	   return true;
   } ****************/

 


		  //TIMESPEED,

		  //TAN0_2PI,
		  //COSTIME0_2PI,
		  //SINTIME0_PI,
		  //TANTIME0_2PI,
		  //TIMECYCLEPERIOD,

   if("FPS" == str)
   {
	 valOut = FPS;
     return true;
   }


   if(  ("TIMEELAPSED" == str)  || ("ELAPSED" == str) || ("DELTA" == str) )
   {
	 valOut = TIMEELAPSED;
     return true;
   }
 
   if("VIEWPORTWIDTH" == str)
   {
	   valOut =  VIEWPORTWIDTH;
	   return true;
   } 

   if("VIEWPORTHEIGHT" == str)
   {
	   valOut =  VIEWPORTHEIGHT;
	   return true;
   } 


   if("VIEWPORTWIDTHINVERSE" == str)
   {
	   valOut =  VIEWPORTWIDTHINVERSE;
	   return true;
   } 

   if("VIEWPORTHEIGHTINVERSE" == str)
   {
	   valOut =  VIEWPORTHEIGHTINVERSE;
	   return true;
   } 
 

   if("FOV" == str)
   {
	   valOut =  FOV;
	   return true;
   } 

   if( ("FARCLIPPLANE" == str) || ("FAR" == str))
   {
	   valOut =  FARCLIPPLANE;
	   return true;
   }  

   if( ("NEARCLIPPLANE" == str) || ("NEAR" == str))
   {
	   valOut =  NEARCLIPPLANE;
	   return true;
   } 


   if( ("ASPECT" == str) || ("ASP" == str) )
   {
	   valOut =  ASPECT;
	   return true;
   } 
 
 

			  /***********************************
		  RANDOMFRACTION1PERPASS,
		  RANDOMFRACTION2PERPASS,
		  RANDOMFRACTION3PERPASS,
		  RANDOMFRACTION4PERPASS,

		  RANDOMFRACTION1PEREFFECT,
		  RANDOMFRACTION2PEREFFECT,
		  RANDOMFRACTION3PEREFFECT,
		  RANDOMFRACTION4PEREFFECT,
			 ****************************************/
 
		  //PASSINDEX,


   if("RIGTHMOUSEBUTTON" == str)
   {
	 valOut = RIGTHMOUSEBUTTON;
     return true;
   }

   if("LEFTMOUSEBUTTON" == str)
   {
	 valOut = LEFTMOUSEBUTTON;
     return true;
   }

   if("MIDDLEMOUSEBUTTON" == str)
   {
	 valOut = MIDDLEMOUSEBUTTON;
     return true;
   }

   //-----------------------------------------
  
   if("MOUSECOORDINATEX" == str)
   {
	 valOut = MOUSECOORDINATEX;
     return true;
   }

 
   if("MOUSECOORDINATEY" == str)
   {
	 valOut = MOUSECOORDINATEY;
     return true;
   }

 
   if("MOUSECOORDINATEXNDC" == str)
   {
	 valOut = MOUSECOORDINATEXNDC;
     return true;
   }			 

  
   if("MOUSECOORDINATEYNDC" == str)
   {
	 valOut = MOUSECOORDINATEYNDC;
     return true;
   }

  
   if("MODELBOUNDINGSPHERERADIUS" == str)
   {
	 valOut = MODELBOUNDINGSPHERERADIUS;
     return true;
   }

  
 //  if("SPECULARPOWER" == str)
 //  {
//	 valOut = SPECULARPOWER;
 //    return true;
 //  }

 

		//  ROTATEZ,

		//  BRIGHTNESS,

		 // CONTRAST,

		  //ALPHA,
		  //LIGTHMAPINTENSITY,
		  //ANIMATESPEED,
 

 

 

  return false;
}
 
 
}
}

