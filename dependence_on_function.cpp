
#include "dependence_on_function.h"


namespace gbmath
{

dependence_on_function::operator std::string() const
{
	assert(  __UNUSED_DCLARED_LAST == 7 );
	 switch(_e)
	 {
 
	 case linear: { return std::string("linear"); } break;
	 case linear_inverse: { return std::string("linear_inverse"); } break;
	 case squared: { return std::string("squared"); } break;
	 case squared_a_inverse: { return std::string("squared_a_inverse"); } break;
	 case cubic: { return std::string("cubic"); } break;
	 case cubic_a_inverse: { return std::string("cubic_a_inverse"); } break;

	 //case xxxxxxx: { return std::string("xxxxxxxx"); } break;	 
	 
	 default:
		 {
			 // 
		 }
	 
	 }

	 assert(  false  &&  "invalid enum value" );
	 return std::string("");
}

void dependence_on_function::operator = (const std::string& argstr)
{
		assert(  __UNUSED_DCLARED_LAST == 7 );

		std::string str = argstr;
		// set to lower

		for( size_t c=0; c<str.length(); c++ )
		{
			str[c] = tolower( str[c] );
		}
 
		// compare

		if( str == "linear" )
		{
			_e =  linear;
			return ;
		}

		if( str == "linear_inverse" )
		{
			_e =  linear_inverse;
			return ;
		}

		if( str == "squared" )
		{
			_e =  squared;
			return ;
		}

 		if( str == "squared_a_inverse" )
		{
			_e =  squared_a_inverse;
			return ;
		}

 		if( str == "cubic" )
		{
			_e =  cubic;
			return ;
		}

		if( str == "cubic_a_inverse" )
		{
			_e =  cubic_a_inverse;
			return ;
		}

	//	if( str == "xxxxxxxxx" )
	//	{
	//		_e =  xxxxxxxxxx;
	//		return ;
	//	}

 

		assert(  false  &&  "invalid enum value" );

}


float dependence_on_function::formula( float x, const e depend ) 
{
	  float y = 0.0f; /// result
	  
	  // clump 0...1
	  {
		if(x < 0.0f) { x=0.0f; }
		if(x > 1.0f) { x=1.0f; }
	  }

		 switch(depend) 
		 {
			 
			   case linear: { y = x;  } break;  
			   case linear_inverse: { y = 1.0f-x; } break;
			   
			   case squared: { y=x*x; } break;
			   case squared_a_inverse: { y = 1.0f-x*x; } break;
			  
			   case cubic: { y=x*x*x; } break;
			   case cubic_a_inverse: { y = 1.0f - x*x*x; } break;  
			   
 
			 //  case xxx: {  } break;   
			 //  case xxx: {  } break;   
			 //  case xxx: {  } break; 
 

			   default: 
				   {  
						
				   }


		 }
		  
  


	return y;
};


}
