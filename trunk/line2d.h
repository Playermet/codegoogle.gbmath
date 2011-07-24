/**  \file
 \brief яяячччччч


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{



		//! Линия в 2d по двум точкам
		class line2d {
		public:
			 vec2   src;
			 vec2   dest;


			inline line2d() { src.setzero(); dest.setzero(); }
			inline line2d(const line2d& l) {src=l.src;  dest=l.dest; }
			inline line2d(const  vec2& _src, const  vec2& _dest)
			{
			   src=_src;
			   dest=_dest;
			}

			normal2 direction() const
			{
			    normal2 res = (dest - src);
			    return res;
			}


			inline void set(const  vec2& _src,  vec2& _dest)
			{
			 src  = _src;
			 dest = _dest;
			}


			// vec2 projectPoint(const vec2& pnt) const

			// checkIntersect......




		};


 
}