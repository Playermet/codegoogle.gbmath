/**  \file
 \brief Triangle by three points


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{

		//! \brief Triangle by three points.
		class triangle_2d {
		public:
		
			 vec2   p1; ///< the first  point (vertex) triangular
			 vec2   p2; ///< the second point (vertex) triangular
			 vec2   p3; ///< the second point (vertex) triangular 


			inline triangle_2d() 
			{

			}

			inline triangle_2d(const triangle_2d& t)
			{
				*this = t;
			}

			inline triangle_2d(const  vec2 _p1, const  vec2 _p2, const  vec2 _p3)
			{
				p1 = _p1;
				p2 = _p2;
				p3 = _p3;
			}

			inline void set(const  vec2 _p1, const  vec2 _p2, const  vec2 _p3)
			{
				p1 = _p1;	
				p2 = _p2;	
				p3 = _p3;
			}

			//! \brief Compute and return the middle point of the triangle
			inline  vec2 middle_point() const
			{
				vec2 res;
				res.x = (p1.x + p2.x + p3.x) / 3.0f;
				res.y = (p1.y + p2.y + p3.y) / 3.0f;
				return res;
			}


			inline triangle_2d& offset(float x, float y)
			{
				p1 += vec2(x,y);
				p2 += vec2(x,y);
				p3 += vec2(x,y);
				return *this;
			}

			inline triangle_2d& offset(const vec2& val)
			{
				p1 += val;
				p2 += val;
				p3 += val;
				return *this;
			}


			operator const float*() const 
			{
				return &p1.x;
			}

			operator  float*()  
			{
				return &p1.x;
			}


			/*
			//! \brief Compute and return the plane to the points of the triangle
			plane_s get_plane() const
			{
				plane_s plane;
				plane.make_from_points(p1,p2,p3);
				return plane;
			}
			*/


			#if ( defined(GB_OPENGL) && defined(__GL_H__)   )

			
			/*
			//! \brief rendering via OpenGL
			inline void glVertex()
			{
				glVertex3f(p1.x, p1.y, p1.z);
				glVertex3f(p2.x, p2.y, p2.z);
				glVertex3f(p3.x, p3.y, p3.z);
			}
			*/

			#endif



			friend std::ostream &operator << (std::ostream &stream, const triangle_2d& t)
			{
				stream << t.p1 << " " << t.p2 << " " << t.p3 ;
				return stream;
			}

			operator std::string() const
			{
				std::ostringstream ss;
				ss << p1 << " " << p2 << " " << p3;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				std::istringstream ss(str);
				ss >> p1;
				ss >> p2;
				ss >> p3;
				if( ss.fail() )
				{
					throw std::invalid_argument("bad input string");
				}

			}
 
		};
 
}

