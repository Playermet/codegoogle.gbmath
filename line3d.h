/**  \file
 \brief яяяяяяяяччччч

*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{


	//! \brief   Линия(Прямая) в трёхмерном пространстве по двум точкам
	class line3d {
	public:
		 vec3   src;
		 vec3   dest;

		inline line3d() {};
		inline line3d(const line3d& l) {src=l.src; dest=l.dest; };
		inline line3d(const  vec3& _src, const  vec3& _dest) {src=_src; dest=_dest; };

		//! \brief Получить направление от src к dest
		inline  vec3 direction() const {  vec3 r (dest - src); r.normalize(); return r; }



      #if ( defined(GB_OPENGL) &&  defined(__GL_H__) )
		//! \brief Вывод вершин для OpenGl по старинке.
		inline void glVertex() { glVertex3f(src.x, src.y, src.z); glVertex3f(dest.x, dest.y, dest.z);   };
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


		//! вывод на консоль.
		//inline void print() const
		//{
		//	src.print(); printf("  ");
		//	dest.print(); printf("  \n");
		//};

	}; // Line





 
}

