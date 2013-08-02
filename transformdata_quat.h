/**  \file
* \brief Data transformation (rotation by quaternion).




*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gbmath
{





   //! \brief The assembly of data transformation: 
					// scaling (vector) + rotation (quaternion) + position (vector).

	//! \brief  Data transformation (rotation by quaternion).
   struct TransformData
   {
	    vec3         vScaling;      ///< scaling
	    Quaternion   qRotation;     ///< rotation
	    vec3         vTranslation;  ///<  position
 

		void operator = (const std::string& str)   throw (std::runtime_error)
		{
			std::stringstream ss(str);
			ss >> vScaling;
			ss >> qRotation;
			ss >> vTranslation;

			if( ss.fail() )
			{
				throw std::runtime_error("bad argument");
			}
		}

		operator std::string() const
		{
			std::ostringstream ss ;
			ss << vScaling.x << " " << vScaling.y << " " << vScaling.z;
		    ss << "   ";

			ss << qRotation << " " << qRotation << " " << qRotation;
			ss << "   ";

			ss << vTranslation;

			return ss.str();
		}

		friend std::ostream& operator << (std::ostream& os, const TransformData& a)
		{
			os << a.vScaling;	 // a.
			os << "  ";
			os << a.qRotation;
			os << "  ";
			os << a.vTranslation;
			return os;
		}



   };



 
}