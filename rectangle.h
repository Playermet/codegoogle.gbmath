 /**   \file  
  \brief  Simple rectangle  яяяяяяяяяяя   
 
 
 */
 
#pragma once

//#define __GB__BASE__RECTANGLE_H__ 

//#include "../Config.h"
//#include "Types.h"
#include "point.h"

/*
#include <ostream>
#include <sstream>
#include <string>
*/


namespace gb 
{

	namespace fmath
	{
	
		
		//! \brief Прямоугольник
		// Эта структура превратилась в кучу дерьма
		struct Rectangle
		{
			int left; //< позиция по X.
			int top;  //< позиция по Y.
			int width;  //< ширина.
			int height; //< высота.

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

			Rectangle(const Rectangle &other)
			{
				init(other);
			}

			Rectangle(int x, int y, int w, int h)
			{
				void init(int x, int y, int w, int h);
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

			void init(const Rectangle &rc)
			{
				init(rc.left, rc.top, rc.width, rc.height);
			}

			void set_zero()
			{
				left = top = width = height = 0;
			}

			bool operator < (const Rectangle &other) const
			{
				if (width < other.width)
					return true;
				if (width > other.width)
					return false;
				return height < other.height;
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

			// \brief Проверка нахождения точки в прямоугольнике.  // old name: checkPoint
			inline bool check_point(int x, int y) const 
			{
			  if( (x>left) && (x<left+width) && (y>top) && (y<top+height) ) return true;
			  return false;			
			}

			inline bool check_point(const Point& p) // old name :  checkPoint
			{
				return check_point( p.x , p.y );
			}

#ifdef _WINDOWS_
			inline bool check_point(const POINT& p)  // old name :  checkPoint
			{
				return check_point( p.x , p.y );
			}
#endif

			inline void offset(int x, int y)
			{
				left += x;
				top  += y;
			}

#ifdef _WINDOWS_
			inline void offset(const POINT& p)
			{
				left  += p.x;
				top   += p.y;
			}
#endif

#ifdef _WINDOWS_
			//! \brief offset coord.
			inline void operator += (const POINT& p)
			{
				offset (p);
			}

 #endif

			//! \brief offset coord.
// 			inline void operator += (const Point& p)
// 			{
// 				offset (p);
// 			}


#ifdef _WINDOWS_
			//! \brief  Получить центральную координату.
			inline POINT center() const 
			{
				POINT res = { (left+width)/2 , (top+height)/2 };
				return res;
			}
#endif



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
				std::istringstream ss(str);
				ss >> left;
				ss >> top;
				ss >> width;
				ss >> height;
				if( ss.fail() ) throw std::invalid_argument("bad input string");
			}
 


		};
		
	}
}
