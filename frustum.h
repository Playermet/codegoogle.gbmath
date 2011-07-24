/**  \file
 \brief яяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
 
namespace gbmath
{

   //! \brief Стандартная пирамида видимости
   class frustum  {
   public:

	   union {
		   struct {
			   plane_s  front;
			   plane_s  back;
			   plane_s  left;
			   plane_s  right;
			   plane_s  top;
			   plane_s  bottom;
		   };

		   plane_s  planes[6] ;
	   };

	   inline frustum() {}
	   inline frustum(const frustum& f) { *this=f; }


	   /** \brief Выполнить построение из матричного произведения view * proj */
	   void make(const  mat44& mViewProj);

	   /** \brief Выполнить построение из матриц   view и proj */
	   void make(const  mat44& mView, const  mat44& mProj)
	   {
		    mat44 mViewProj = mView * mProj;
		   make(mViewProj);
	   }

       //! \brief Проверка попадания точки в пирамиду
	   bool checkPoint(const  vec3& point) const;

       //! \brief Проверка попадания сферы в пирамиду
	   bool checkSphere(const sphere& sphere)  const;

	   //! \brief Проверка попадания бокса в пирамиду
       bool checkAABB(const aabb& aabb) const;



	 //  #pragma message("delete  print()  "   __FILE__ )

  //   //! \brief Отладочный вывод на консоль
  //   inline void print() const
	 //{
		// printf("\n");
		// printf("front=");  front.print();  printf("\n");
		// printf("back=");   back.print();   printf("\n");
		// printf("left= ");  left.print();   printf("\n");
		// printf("right=");  right.print();  printf("\n");
		// printf("top=");    top.print();    printf("\n");
		// printf("bottom="); bottom.print(); printf("\n");
 	// }

	 friend std::ostream &operator << ( std::ostream &stream, const frustum& fr )
	 {
		 stream  << "front  = " << fr.front << "\n"
				 << "back   = " << fr.back << "\n"
				 << "left   = " << fr.left << "\n"
				 << "right  = " << fr.right << "\n"
				 << "top    = " << fr.top << "\n"
				 << "bottom = " << fr.bottom << "\n" ;
		 return stream;
	 }



   };









 
}