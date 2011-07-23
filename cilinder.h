/**  \file
 \brief  яяяяяяяяяяяяя
*
*
*
*/


#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{




   //! \brief Класс цилиндр по точкам координатам центров основания и радиусу
   class Cilinder {
   public:
	    vec3  p1;  ///< Первая центральная координата в основании цилиндра.
	    vec3  p2;  ///< Вторая центральная координата в основании цилиндра.

	   float      radius; ///< Радиус цилиндра

	   Cilinder() {}
	   Cilinder(const Cilinder& c) { p1=c.p1; p2=c.p2; radius=c.radius;  }
	   Cilinder(const  vec3& _p1, const  vec3& _p2, float _radius)
	   {
		   p1=_p1;
		   p2=_p2;
		   radius = _radius;
	   }


	   /*
	   //! \brief Вывод значений на консоль.
	   void print() const
	   {
	     printf("\n");
		 printf("p1= "); p1.print(); printf("\n");
		 printf("p2= "); p2.print(); printf("\n");
		 printf("r= %f", radius);    printf("\n");
	   }
		  */



   };
   //  end class Cilinder





 
}