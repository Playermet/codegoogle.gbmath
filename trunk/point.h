/** \file
  \brief   simple point. яяяяяяяяяяяяяяя


*/

#pragma once

//#include "../Config.h"

//#include "config.h"

//#include "Types.h"

#include <ostream>
#include <sstream>
#include <string>

 
namespace gbmath
{




	//! \brief   simple point.
	class Point {
	public:

		int x;
		int y;

		inline Point() { x=y=0; }
		inline Point(const Point& p) { x=p.x; y=p.y; }

		#ifdef _WINDOWS_
		inline Point(const POINT& p) { *this = p; }
		#endif

		inline Point(int _x, int _y) { init(_x,_y);  }

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


		inline Point operator + (const Point& p) const
		{
			return Point( x+p.x , y+p.y );
		}

		inline Point& operator += (const Point& p)
		{
			x += p.x;
			y += p.y;
			return *this;
		}

		inline Point operator - (const Point& p) const
		{
			return Point( x-p.x , y-p.y );
		}

		inline Point& operator -= (const Point& p)
		{
			x -= p.x;
			y -= p.y;
			return *this;
		}

		friend std::ostream& operator << (std::ostream& os, const Point& p)
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
			std::istringstream ss(str);
			ss >> x;
			ss >> y;
			if( ss.fail() ) throw std::invalid_argument("bad input string");
		}




	};



}
 
 

// end file