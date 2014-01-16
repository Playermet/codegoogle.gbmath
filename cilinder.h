/**  \file
 \brief  class cylinder
*
*
*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{



   //! \brief Class points on the cylinder base center coordinates and radius
   class cilinder 
   {
   public:
	    vec3  p1;  ///< The first coordinate in the center of the cylinder.
	    vec3  p2;  ///< The second coordinate in the center of the cylinder.

	   float      radius;  ///< radius of the cylinder.

	   cilinder() 
	   {

	   }

	   cilinder(const cilinder& c) 
	   { 
		   p1 = c.p1; 
		   p2 = c.p2; 
		   radius = c.radius;  
	   }

	   cilinder(const  vec3& _p1, const  vec3& _p2, float _radius)
	   {
		   p1 = _p1;
		   p2 = _p2;
		   radius = _radius;
	   }

	   operator std::string() const
	   {
		   std::ostringstream ss;
		   ss << p1;
		   ss << "  ";
		   ss << p2;
		   ss << "  ";
		   ss << radius;
	   }

	   void operator = (std::string& str)  throw (std::runtime_error)
	   {
		   std::istringstream iss(str);
		   iss >> p1;
		   iss >> p2;
		   iss >> radius;

		   if( iss.fail() )
		   {
			   throw std::runtime_error("bad argument");
		   }
	   }


	   friend std::ostream& operator << (std::ostream& os, const cilinder& a)
	   {
			os << a.p1;
			os << "   ";
			os << a.p2;
			os << "   ";
			os << a.radius;
			return os;
	   }


   };
 
 
}
