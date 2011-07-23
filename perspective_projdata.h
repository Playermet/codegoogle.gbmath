﻿/**  \file
 \brief яяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	#pragma message( "!!!!  rename this  "  __FILE__ )

	  //! \brief  Сборка из данных перспективной проекции.
	  struct perspective_projection_data
	  {
			float fovy;
			float aspect;
			float zn;
			float zf;

			//! \brief Извлечь проекционные данные из левосторонней перспективной матрицы .
			inline void extractProjPerspectLH(const mat44& mPerspectProjLH)
			{
				aspect = mPerspectProjLH._22/mPerspectProjLH._11;
				fovy   = 2.0f  * atan(1.0f/mPerspectProjLH._22);
				zn = -mPerspectProjLH._43/mPerspectProjLH._33;
				zf =  mPerspectProjLH._43/(1.0f-mPerspectProjLH._33);
			}


			friend std::ostream &operator << (std::ostream &stream, const perspective_projection_data& a)
			{
				stream << a.fovy << " " << a.aspect << " " << a.zn << " " << a.zf ;
				return stream;
			}

			operator std::string() const
			{
				std::ostringstream ss;
				ss << fovy << " " << aspect << " " << zn << " " << zf ;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				std::istringstream ss(str);
				ss >> fovy;
				ss >> aspect;
				ss >> zn;
				ss >> zf;
				if( ss.fail() )
					throw std::invalid_argument("bad input string");
			}


			friend std::istream &operator >> (std::istream &stream, perspective_projection_data& a)
			{
				stream >> a.fovy;
				stream >> a.aspect;
				stream >> a.zn;
				stream >> a.zf;
				return stream;
			}


			friend std::istringstream &operator >> (std::istringstream &ss, perspective_projection_data& a)
			{
				ss >> a.fovy;
				ss >> a.aspect;
				ss >> a.zn;
				ss >> a.zf;
				return ss;
			}








	  };


 
}