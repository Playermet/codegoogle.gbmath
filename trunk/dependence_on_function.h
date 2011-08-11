

#pragma once

#include <float.h>
#include <string>

namespace gbmath
{

	struct dependence_on_function {
	
		enum e
		{
			undef = 0,
			
			
			linear,   ///<  y=x;
			linear_inverse,   ///<  y=1-x; 

			squared,            ///<  y=x*x; 
			squared_a_inverse,  ///<  y= 1 - x*x; 

			cubic,    ///< y=x*x*x;
			cubic_a_inverse, ///< 1- x*x*x 
			
			
		
			__UNUSED_DCLARED_LAST,
			__UNUSED_ALIGN32 = 0x7f000000
		};
	
		inline dependence_on_function() { _e = undef; }
		inline dependence_on_function(const e value) { _e = value; }
		inline dependence_on_function(const dependence_on_function& value) { _e = value._e; }
 		
		
		inline void operator = (const e value) { _e = value; }
		inline operator e() const { return _e; }
		
		// TODO: to/ from str <<

		//void operator = (const std::string& str)
		//{
		//}
		
			
			static  float formula(float x, const e depend ) 
			{
				  float y = 0.0f; /// result
				  
				  // clump 0...1
				  {
					if(x<0.0f) { x=0.0f; }
					if(x>1.0f) { x=1.0f; }
				  }

					 switch(depend) 
					 {
						 
						   case linear: { y = x;  } break;  
						   case linear_inverse: { y = 1.0f-x; } break;
						   
						   case squared: { y=x*x; } break;
						   case squared_a_inverse: { y = 1.0f-x*x; } break;
						  
						   case cubic: { y=x*x*x; } break;
						   case cubic_a_inverse: { y = 1.0f - x*x*x; } break;  
						   
						   /*
						   case xxx: {  } break;   
						   case xxx: {  } break;   
						   case xxx: {  } break; 

						   case xxx: {  } break;   
						   case xxx: {  } break;   
						   case xxx: {  } break; 

						   case xxx: {  } break;   
						   case xxx: {  } break;   
						   case xxx: {  } break; 
						   
						   case xxx: {  } break;   
						   case xxx: {  } break;   
						   case xxx: {  } break;    
						   */
 
						   default: {  }

					 }
					  
			  
	  

				return y;
			};

		
	private:
		e _e;		
		

	};

 

}
