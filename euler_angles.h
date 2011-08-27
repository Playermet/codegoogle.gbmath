﻿/**  \file
 \brief Ehler angles. Angles of rotation along all three axes.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 

namespace gbmath
{

 

	//! \brief  Ehler angles. Angles of rotation along all three axes.
	class euler_angles {
	public:
		float yaw;    ///<   Yaw around the y-axis, in radians.
		float pitch;  ///<   Pitch around the x-axis, in radians.
		float roll;   ///<   Roll around the z-axis, in radians.

		inline euler_angles()
		{
			yaw = pitch = roll = 0.0f;
		}

		inline euler_angles(const euler_angles& ea  )
		{
			yaw   = ea.yaw;
			pitch = ea.pitch;
			roll  = ea.roll;
		}

		inline euler_angles(float _yaw, float _pitch, float _roll)
		{
			yaw   = _yaw;
			pitch = _pitch;
			roll  = _roll;
		}


		friend std::ostream &operator << (std::ostream &stream, const euler_angles& ea)
		{
			stream << ea.yaw << " " << ea.pitch << " " << ea.roll ;
			return stream;
		}

		operator std::string() const
		{
			std::ostringstream ss;
			ss << yaw << " " << pitch << " " << roll ;
			return ss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream ss(str);
			ss >> yaw;
			ss >> pitch;
			ss >> roll;
			if( ss.fail() )
			{
				throw std::invalid_argument("bad input string");
			}
		}




	};


 
}