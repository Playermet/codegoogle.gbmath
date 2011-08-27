/**  \file
 \brief frustum


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
 
namespace gbmath
{

   //! \brief   frustum. Standard frustum
   class frustum  {
   public:

	   union {
		   struct 
		   {
			   plane_s  front;
			   plane_s  back;
			   plane_s  left;
			   plane_s  right;
			   plane_s  top;
			   plane_s  bottom;
		   };

		   plane_s  planes[6] ;
	   };

	   inline frustum() 
	   {

	   }

	   inline frustum(const frustum& f) 
	   { 
		   *this = f; 
	   }


	   //! \briefBuild the matrix product of the view * proj 
	   void make(const  mat44& mViewProj);

	   //! \brief Build the matrix product of the view and proj 
	   void make(const  mat44& mView, const  mat44& mProj)
	   {
		    mat44 mViewProj = mView * mProj;
		   make(mViewProj);
	   }

       //! \brief Verification of the point of the pyramid
	   bool checkPoint(const  vec3& point) const;

       //! \brief Hit Testing in the scope of the pyramid
	   bool checkSphere(const sphere& sphere)  const;

	   //! \brief Hit Testing in the pyramid box
       bool checkAABB(const aabb& aabb) const;

 

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