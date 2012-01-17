/**  \file
 \brief vectors of observations.

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

namespace gbmath
{


   //! \brief vectors of observations..
   struct eyedata
   {
	 vec3   eye_position;  ///<	  position.
	 vec3   eye_at;        ///<   target.
	 vec3   eye_up;        ///<   up.


	 //! \brief   get the direction of observation.
	 vec3 direction() const
	 {
		 vec3 res(eye_at-eye_position);
		 res.normalize();
		 return res;
	 }

	 void decomposeInverseView(const mat44& mInverseView)
	 {

#pragma message(" eyedata::decomposeInverseView  need code . extract inverse view matrix")
		// assert(   false &&  "no code");
	  eye_position.x = mInverseView._41;
	  eye_position.y = mInverseView._42;
	  eye_position.z = mInverseView._43;

	  assert(false);

     // dir = *( (vec3*)&minv._31);


     // up  = *( (vec3*)&minv._21);

	 }

	 operator std::string() const
	 {
		 std::ostringstream oss;
		 oss << eye_position;
		 oss << "    ";

		 oss << eye_at;
		 oss << "    ";

		 oss << eye_up;
		 
		 return oss.str();
	 }

	 void operator = (const std::string& str) throw (std::runtime_error)
	 {
		 std::istringstream iss(str);
		 iss >> eye_position;
		 iss >> eye_at;
		 iss >> eye_up;

		 if( iss.fail() )
		 {
			 throw std::runtime_error("bad argument");
		 }
	 }

	 friend std::ostream& operator << (std::ostream& os, const eyedata& a)
	 {
		 os << a.eye_position << "\n";
		 os << a.eye_at << "\n";
		 os << a.eye_up << "\n";
		 return os;
	 }





   };
 
}

