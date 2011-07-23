/**  \file
 \brief ??????


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{
	namespace fmath
	{

		//! \brief Треугольник по трём точкам . 
		class Triangle {
		public:
			 vec3   p1; ///< первая точка(вершина) треугольника 
			 vec3   p2; ///< вторая точка(вершина) треугольника   
			 vec3   p3; ///< третья точка(вершина) треугольника 


			inline Triangle() {}
			inline Triangle(const Triangle& t) 
			{ 
				*this = t; 
			}

			inline Triangle(const  vec3 _p1, const  vec3 _p2, const  vec3 _p3) 
			{
				p1 = _p1;	
				p2 = _p2;	
				p3 = _p3;	
			}

			inline void set(const  vec3 _p1, const  vec3 _p2, const  vec3 _p3) 
			{
				p1=_p1;	p2=_p2;	p3=_p3;	
			}

			/** \brief Вычислить и вернуть среднюю точку треугольника */
			inline  vec3 middle_point() const 
			{ 
				vec3 res;
				res.x = (p1.x + p2.x + p3.x) / 3.0f;
				res.y = (p1.y + p2.y + p3.y) / 3.0f;
				res.z = (p1.z + p2.z + p3.z) / 3.0f;
				return res;
			}

			//! \brief Вычислить и вернуть плоскость по точкам треугольника 
			plane_s get_plane() const
			{
				plane_s plane; 
				plane.make_from_points(p1,p2,p3); 	
				return plane;
			}


			#if ( defined(GB_OPENGL) && defined(__GL_H__)   )
			//! \brief Вывод вершин по OpenGL  по старинке.
			inline void glVertex()   
			{
				glVertex3f(p1.x, p1.y, p1.z);
				glVertex3f(p2.x, p2.y, p2.z);
				glVertex3f(p3.x, p3.y, p3.z); 
			}
			#endif



			friend std::ostream &operator << (std::ostream &stream, const Triangle& t)
			{
				stream << t.p1 << " " << t.p2 << " " << t.p3 ;
				return stream;
			}

			operator std::string() const 
			{
				std::ostringstream ss;
				ss << p1 << " " << p2 << " " << p3 ;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				assert(false);
				//std::istringstream ss(str);
				//ss >> p1 ;
				//ss >> p2 ;
				//ss >> p3 ;
				//if( ss.fail() ) throw std::invalid_argument("bad input string");
				/*
				std::string res;
				res += p1;
				res += " ";
				res += p2;
				res += " ";
				res += p3;
				return res;
				*/
			}





		};	
	}
}
