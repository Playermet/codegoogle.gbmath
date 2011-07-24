/**  \file
 \brief   яяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{





		/** \brief Луч в 2d  по позиции  (исходной точке)  и  направлению  */
		class ray2d {
		public:
			 vec2   orig; ///< точка центр луча
			 vec2   dir;  ///< направление луча ( должен быть нормализован)

			inline ray2d() {}
			inline ray2d(const ray2d& r) {orig=r.orig; dir=r.dir; }
			inline ray2d(const  vec2& _orig, const  vec2& _dir, bool bNeedNormalizeDir)
			{
				orig=_orig;
				dir=_dir;
				if(bNeedNormalizeDir) dir.normalize();
			}


			// bool checkIntersectCircle(const CIrcle& c)
			// bool checkIntersectRect(const Rect& r)
			// bool checkIntersectRectContactPnts(const Rect& r)
			// bool checkIntersectLine


		};

 
}