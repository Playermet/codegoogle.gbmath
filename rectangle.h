 /**   \file
  \brief  integer values rectangle.  


 */

#pragma once


#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{


	//! \brief integer values rectangle
	struct Rectangle
	{
		int  left; ///< position X.
		int  top;  ///< position Y.

		int  width;  ///< rect width.
		int  height; ///< rect height.

		Rectangle()
		{
			left = top = width = height = 0;
		}

		Rectangle(int w, int h)
		{
			width = w;
			height = h;
			top = left = 0;
		}

		Rectangle(const Rectangle& a)
		{
			left = a.left;
			top = a.top;
			width = a.width;
			height = a.height;
		}

		Rectangle(int _x, int _y, int _w, int _h)
		{
			left = _x;
			top =  _y;
			width = _w;
			height = _h;
		}

#ifdef _WINDOWS_
		Rectangle(const RECT& r)
		{
			*this = r;
		}
#endif

		Rectangle &operator = (const Rectangle &other)
		{
			init(other);
			return *this;
		}

		void init(int x, int y, int w, int h)
		{
			left = x;
			top  = y;
			width  = w;
			height = h;
		}

		//! \brief  set all to zero
		void set_zero()
		{
			left = top = width = height = 0;
		}

		//! \breif   is all zero ?
		bool empty() const
		{
			return left == top == width == height == 0;
		}

		bool operator < (const Rectangle& a) const
		{
			return width*height <  a.width*a.height;
		}

		inline bool  operator == (const Rectangle& a) const
		{
			return left==a.left && top==a.top && width==a.width && height && a.height;
		}

		inline bool  operator != (const Rectangle& a) const
		{
			return !(*this == a);
		}

#ifdef _WINDOWS_
		inline void operator = (const RECT& r)
		{
			left = r.left;
			top  = r.top;
			width  = r.right - r.left;
			height = r.bottom - r.top;
		}


		inline operator RECT() const
		{
			RECT r;
			r.top = top;
			r.left = left;
			r.bottom = top + height;
			r.right  = left + width;
			return r;
		}
#endif

		//! \brief Verification of finding a point in the rectangle. 
		inline bool check_point(int x, int y) const
		{
		  if( (x>left) && (x<left+width) && (y>top) && (y<top+height) ) return true;
		  return false;
		}

		//! \brief Verification of finding a point in the rectangle. 
		inline bool check_point(const point& p)  
		{
			return check_point( p.x , p.y );
		}

#ifdef _WINDOWS_

		//! \brief Verification of finding a point in the rectangle. 
		inline bool check_point(const POINT& p) 
		{
			return check_point( p.x , p.y );
		}
#endif

		//!  \brief   move rectangle
		inline void offset(int x, int y)
		{
			left += x;
			top  += y;
		}

#ifdef _WINDOWS_

		//!  \brief   move rectangle
		inline void offset(const POINT& p)
		{
			left  += p.x;
			top   += p.y;
		}

		//! \brief offset coord.
		inline void operator += (const POINT& p)
		{
			offset (p);
		}

		//! \brief  Get a central coordinate.
		inline POINT center() const
		{
			POINT res = { (left+width)/2 , (top+height)/2 };
			return res;
		}
		
#endif // _WINDOWS_



		friend std::ostream& operator << (std::ostream& os, const Rectangle& r)
		{
			os << r.left << " " << r.top << " " << r.width << " " << r.height;
			return os;
		}


		operator std::string() const
		{
			std::ostringstream ss;
			ss << left << " " << top << " " << width << " " << height;
			return ss.str();
		}

		void operator = (const std::string& str) throw (std::invalid_argument)
		{
			std::istringstream sstream(str);

			sstream >> left;
			sstream >> top;
			sstream >> width;
			sstream >> height;

			if( sstream.fail() ) 
			{
				throw std::invalid_argument("bad input string");
			}

		}
		
		//! \brief  contains the whole rectangle?
		bool is_contains_whole_rectangle(const Rectangle& r) const
		{
			//
			if( (r.left > left) && (r.top > top) )
			{
				if( 
					( (left + width) > (r.left + r.width)  ) 
					&& 
					( (top + height) > (r.top  + r.height) ) 
				  )
				{
					return true;
				}
			}
			
			return false;
		}


	};


}
