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
   class frustum  
   {
   public:

		plane_s  planes [6] ;


	   inline frustum() 
	   {

	   }

	   inline frustum(const frustum& f) 
	   { 
		   *this = f; 
	   }

	   //! \brief   construct and make
	   inline frustum(const  mat44& mViewProj)
	   {
		   make(mViewProj);
	   }


	   //! \brief   Build the matrix product of the view * proj 
	   void make(const  mat44& mViewProj);

	   //! \brief   Build the matrix product of the view and proj 
	   void make(const  mat44& mView, const  mat44& mProj)
	   {
		    mat44 mViewProj = mView * mProj;
		   make(mViewProj);
	   }

       //! \brief   Verification of the point of the pyramid
	   bool checkPoint(const  vec3& point) const;

       //! \brief   Hit Testing in the scope of the pyramid
	   bool checkSphere(const sphere& sphere)  const;

	   //! \brief   Hit Testing in the pyramid box
       bool checkAABB(const aabb& aabb) const;

	   
	   const plane_s& get_left() const
	   {
			return planes[0];
	   }
 
	   const plane_s& get_right() const
	   {
			return planes[1];
	   }

	   const plane_s& get_top() const
	   {
			return planes[2];
	   }

	   const plane_s& get_bottom() const
	   {
			return planes[3];
	   }

 	   const plane_s& get_back() const
	   {
			return planes[4];
	   }

 	   const plane_s& get_front() const
	   {
			return planes[5];
	   }


	 friend std::ostream& operator << ( std::ostream& os, const frustum& fr )
	 {

		os  << "front  = " << fr.get_front()   << "\n";
		os  << "back   = " << fr.get_back()    << "\n";
		os  << "left   = " << fr.get_left()    << "\n";
		os  << "right  = " << fr.get_right()   << "\n";
		os  << "top    = " << fr.get_top()     << "\n";
		os  << "bottom = " << fr.get_bottom()  << "\n";

		return os;
	 }



   };

}
