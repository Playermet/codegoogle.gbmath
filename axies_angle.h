/**  \file
 \brief  Assembly: The axis of rotation and angle


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
 

	namespace gbmath
	{
 

		//! \brief   The axis of rotation and angle
		struct axies_angle {

				vec3   axies;  ///< axis of rotation  (should be normalized)
				float   angle; ///< rotation  angle

			axies_angle() { axies.x = axies.y = axies.z = angle = 0.0f;  }

 
			operator std::string() const
			{
				std::stringstream ss;
				ss << axies;
				ss << " ";
				ss << angle;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::runtime_error)
			{
				std::istringstream iss(str);
				iss >> axies;
				iss >> angle;
				if( iss.fail() )
				{
					throw std::runtime_error("bad argument");
				}
			}

			friend std::ostream& operator << (std::ostream& os, const axies_angle& a)
			{
				os << a.axies << " " << a.angle ;
				return os;
			}



		};










	}

	