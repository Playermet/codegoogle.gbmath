/**  \file
 \brief   ray in 2d space


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{
 

	//! \brief  ray in 2d space 
	class ray2d 
	{
	public:
		 vec2   orig; ///< center ray
		 vec2   dir;  ///<  direction ray (most normalized)

		inline ray2d() {}
		inline ray2d(const ray2d& r) {orig=r.orig; dir=r.dir; }
		inline ray2d(const  vec2& _orig, const  vec2& _dir, bool bNeedNormalizeDir)
		{
			orig=_orig;
			dir=_dir;
			if(bNeedNormalizeDir) dir.normalize();
		}





	};

 
}