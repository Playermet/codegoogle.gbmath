/** \file
  \brief   simple point. яяяяяяяяяяяяяяя


*/

#pragma once

//#include "../Config.h"
//#include "config.h"
//#include "Types.h"

#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

 
namespace gbmath {


	//! \brief   simple point.
	struct point {
	public:

		union 
		{
			int x;
			int left;
		};

		union 
		{
			int y;
			int top;
		};

		//int x;
		//int y;

		inline point() { x=y=0; }
		inline point(const point& p) { x=p.x; y=p.y; }
		inline point(int _x, int _y) { init(_x,_y);  }

		#ifdef _WINDOWS_
		inline point(const POINT& p) { *this = p; }
		#endif


		inline void init(int _x, int _y) { x=_x; y=_y; }


		#ifdef _WINDOWS_

		inline void operator = (const POINT& p)
		{
			x = p.x;
			y = p.y;
		}

		inline operator POINT() const
		{
			POINT res = {x,y};
			return res;
		}

		#endif


		inline point operator + (const point& p) const
		{
			return point( x+p.x , y+p.y );
		}

		inline point& operator += (const point& p)
		{
			x += p.x;
			y += p.y;
			return *this;
		}

		inline point operator - (const point& p) const
		{
			return point( x-p.x , y-p.y );
		}

		inline point& operator -= (const point& p)
		{
			x -= p.x;
			y -= p.y;
			return *this;
		}

		friend std::ostream& operator << (std::ostream& os, const point& p)
		{
			os << p.x << " " << p.y ;
			return os;
		}


		operator std::string() const
		{
			std::ostringstream ss;
			ss << x << " " << y;
			return ss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream sstream(str);
			sstream >> x;
			sstream >> y;
			if( sstream.fail() )
			{
				throw std::invalid_argument("bad input string");
			}
		}




	};



}
 
 

// end file