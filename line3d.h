/**  \file
 \brief яяяяяяяяччччч

*/


#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
 

	//! \brief   Линия(Прямая) в трёхмерном пространстве по двум точкам  
	class Line3d {
	public:
		 vec3   src; 
		 vec3   dest;

		inline Line3d() {};
		inline Line3d(const Line3d& l) {src=l.src; dest=l.dest; };	
		inline Line3d(const  vec3& _src, const  vec3& _dest) {src=_src; dest=_dest; };

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
}
