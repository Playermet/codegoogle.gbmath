

#include "fmath.h"
//#include "color4_32.h"
//#include "color4f.h"



#ifdef _MSC_VER
	#pragma  warning(push)
	#pragma  warning(disable : 4244)
#endif


namespace gb
{

namespace  fmath
{


			void color4f::operator =  (const color4_32 val) 
			{
				a =  (float)  (val >> 24)         / 255.0f;
				r =  (float)( (val << 8 ) >> 24 ) / 255.0f;
				g =  (float)( (val << 16) >> 24 ) / 255.0f;
				b =  (float)( (val << 24) >> 24 ) / 255.0f;
			}



			
			inline color4f::operator  color4_32() const   
			{ 
				color4_32 res ;
				 res.r = (byte_t) r * 255.0f;
				 res.g = (byte_t) g * 255.0f;
				 res.b = (byte_t) b * 255.0f;
				 res.a = (byte_t) a * 255.0f;

				 /*
				res = 
					(color4_32) 
					( 

							( (color4_32) (a * 255.0f) << 24 ) 
						|   ( (color4_32) (r * 255.0f) << 16 ) 
						|   ( (color4_32) (g * 255.0f) << 8  )  
						|   ( (color4_32) (b * 255.0f) ) 

					); 	 */

				return res;
			}


}
}


#ifdef _MSC_VER
	#pragma  warning(pop)
#endif

