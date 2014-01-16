/**  \file
 \brief This data perspective projection.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	

	  //! \brief   This data perspective projection.
	  struct perspective_projection_data
	  {
			float fovy;
			float aspect;
			float zn;
			float zf;
 

			perspective_projection_data()
			{
				fovy = aspect = zn = zf = 0.0f;
			}

			perspective_projection_data(float _fovy, float _aspect, float _zn, float _zf)
			{
				fovy   = _fovy;
				aspect = _aspect;
				zn     = _zn;
				zf     = _zf;
			}

			perspective_projection_data(const perspective_projection_data& a)
			{
				fovy   = a.fovy;
				aspect = a.aspect;
				zn     = a.zn;
				zf     = a.zf;		
			}
 
 

			inline mat44 makePerspectiveMatrixLH() const 
			{
				mat44 res;
				res.setPerspectiveFovLH(fovy, aspect, zn, zf);
				return res;
			}

			inline mat44 makePerspectiveMatrixRH() const 
			{
				mat44 res;
				res.setPerspectiveFovRH(fovy, aspect, zn, zf);
				return res;
			}


 
			//! \brief Extract the projection data of left-sided perspective of the matrix.
			inline void extractProjPerspectLH(const mat44& mPerspectProjLH)
			{
				aspect = mPerspectProjLH._22/mPerspectProjLH._11;
				fovy   = 2.0f  * atan(1.0f/mPerspectProjLH._22);
				zn = -mPerspectProjLH._43/mPerspectProjLH._33;
				zf =  mPerspectProjLH._43/(1.0f-mPerspectProjLH._33);
			}

 			inline void extractProjPerspectRH(const mat44& mPerspectProjLH)
			{
				assert(false);
				throw std::runtime_error( " none code ");
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
