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
		class Line2d {
		public:
			 vec2   src;
			 vec2   dest;


			inline Line2d() { src.setzero(); dest.setzero(); }
			inline Line2d(const Line2d& l) {src=l.src;  dest=l.dest; }
			inline Line2d(const  vec2& _src, const  vec2& _dest)
			{
			   src=_src;
			   dest=_dest;
			}

			Normal2 direction() const
			{
			    Normal2 res = (dest - src);
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