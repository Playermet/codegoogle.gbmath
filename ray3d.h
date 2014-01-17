/**  \file
 \brief  ray in 3d space




*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	//! \brief  ray in 3d space
	class ray3d 
	{
	public:
	    vec3   orig; 
	    vec3   dir; 

	   inline ray3d() {}
	   inline ray3d(const ray3d& r) {orig=r.orig; dir=r.dir; }

		//! \brief  may need to remove the option bNeedNormalizeDir
		inline ray3d(const  vec3& _orig, const  vec3& _dir, bool bNeedNormalizeDir=true)
		{
		  orig=_orig;
		  dir=_dir;
		  if(bNeedNormalizeDir)
			  dir.normalize();
		}

		//! \brief  transform ray 
		inline void transform(const  mat44& m)
		{
		     orig.transform_coord(m);
		     dir.transform_normal(m);
		}



		//!  http://netlib.narod.ru/library/book0032/ch15_04.htm
		bool  checkIntersectSphere(const sphere& sphere) const ;


		 /**   \brief  http://www.gamecoder.ru/2011/04/3d-3d.html    */
		bool checkIntersectSphere_2 (const sphere& sphere, float* result) ;


		//! \brief  Aslan.   
		bool checkIntersectSphere_3( const sphere& sph ) ;


		//
		//>>>>>>>>>>>>>>      checkIntersectAABB        >>>>>>>>>>>>>>>>>>>>>>>>>>>
		//


		// http://www.gamecoder.ru/2011/04/3d-3d.html
		bool checkIntersectAABB(const aabb& aabb,  float* result) ;



		//
		//>>>>>>>>>>>>>>>>>  checkIntersectPlane  >>>>>>>>>>>>>>>>>>>>>>>>>
		//

		/**
		//bool checkIntersectPlane(vec3& outContactCoord, const Plane& aabb) {....}
		// http://www.gamecoder.ru/2011/04/3d-3d.html   */
		bool checkIntersectPlane( const plane_s& plane , float* pfOutResult=NULL) const ;

		 //--------------------------------------------------------

		/** \brief  http://www.gamespp.com/algorithms/collisionDetectionTutorial02.html
		  find the distance between a ray and a plane.  */
		float distanceToPlane( plane_s& plane )   const ;




	};

 
}
