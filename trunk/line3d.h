/**  \file
 \brief Line (Direct) in the three-dimensional space by two points

*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{


	//! \brief  Line (Direct) in the three-dimensional space by two points
	class line3d 
	{
	public:
		vec3   src;
		vec3   dest;

		inline line3d()  { }

		inline line3d(const line3d& l) 
		{
		src  = l.src; 
		dest = l.dest; 
		}

		inline line3d(const  vec3& _src, const vec3& _dest) 
		{
		src  = _src; 
		dest = _dest; 
		}

		//! \brief Get used to the direction  src ->  dest
		inline  vec3 direction() const 
		{  
			vec3 r (dest - src); 
			r.normalize(); 
			return r; 
		}



		#if ( defined(GB_OPENGL) &&  defined(__GL_H__) )
		//! \brief draw via OpenGL
		inline void glVertex() 
		{ 
			glVertex3f(src.x, src.y, src.z); 
			glVertex3f(dest.x, dest.y, dest.z);   
		}
		#endif

		inline void operator += (const vec3& v)
		{
			src  += v;
			dest += v;
		}

		inline void operator -= (const vec3& v)
		{
			src  -= v;
			dest -= v;
		}

		operator std::string() const
		{
			std::ostringstream oss;
			oss << src;
			oss << "    ";
			oss << dest;
			return oss.str();
		}

		void operator = (const std::string& str) throw(std::runtime_error)
		{
			std::istringstream iss(str);
			iss >> src;
			iss >> dest;

			if( iss.fail() )
			{
				throw std::runtime_error("bad argument");
			}
		}


		friend  std::ostream& operator << (std::ostream& os, const line3d& a)
		{
			os << a.src;
			os << "   ";
			os << a.dest;
			return os;
		}




	};

 
}
