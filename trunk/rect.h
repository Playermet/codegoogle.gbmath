/**  \file
 \brief Rectangle on the minimum and maximum coordinate.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{

		//! \brief  Rectangle on the minimum and maximum coordinate.
		class Rect 
		{
		public:
 
			vec2 min;
			vec2 max;


			//! \brief The corners of the rectangle
			struct Corners
			{
				 vec2 points[4];
			};

			inline Rect() 
			{ 
				min = max = vec2( 0.0f , 0.0f );
			}

			inline Rect(const Rect& r)
			{
				min = r.min;
				max = r.max;
			}

			inline Rect(float _x1, float _y1, float _x2, float _y2) 
			{ 
				min = vec2( _x1 , _y1 );
				max = vec2( _x2 , _y2 );
			}

#if ( defined(_WINDOWS_)  )

			Rect(const POINT p1, const POINT p2)
			{
				min = vec2( (float)p1.x , (float)p1.y );
				max = vec2( (float)p2.x , (float)p2.y );
			}

			Rect(const RECT& rec) 
			{  
				*this = rec; 
			}

#endif

			Rect(const Rectangle& rec)
			{
			   *this = rec;
			}


			inline void set(float _x1, float _y1, float _x2, float _y2) 
			{ 
				min = vec2( _x1 , _y1 );
				max = vec2( _x2 , _y2 );
			}




#if ( defined(_WINDOWS_) )

			inline void set(const POINT& np1, const POINT& np2) 
			{ 
				min = vec2( (float)np1.x , (float)np1.y );
				max = vec2( (float)np2.x , (float)np2.y );
			}

			inline void operator = (const RECT& rec)
			{
				min = vec2( (float)rec.left ,  (float)rec.top );
				max = vec2( (float)rec.right , (float)rec.bottom );
			}


			inline operator RECT () const
			{
				RECT res;
				res.left   = (long)min.x;
				res.top    = (long)min.y;
				res.right  = (long)max.x;
				res.bottom = (long)max.y;
				return res;
			}

#endif


			inline void operator = (const Rectangle& rec)
			{
				min = vec2( (float)rec.left , (float)rec.top );
				max = vec2(  (float)rec.width,  (float)rec.height );
			}

			inline operator Rectangle() const
			{
				return Rectangle( 
					(int)min.x, (int)min.y, 
					(int)(max.x-min.x), (int)(max.y-min.y)
					);
			}


			//! \brief set to zero all
			inline void setzero() 
			{ 
				min = max = vec2( 0.0f , 0.0f );
			}
			
			//! \brief  check of all components to zero
			inline bool is_zero() const 
			{ 
				return  min.x == 
					0.0f && min.y == 
					0.0f && max.x == 
					0.0f && max.y == 0.0f;
			}

			//! \brief The shift of origin. The motion of the rectangle
			inline void translate(float x, float y)	
			{ 
				min.x += x;
				max.x += x;
				min.y += y;
				max.y += y;
			}

			//! \brief  The shift of origin. The motion of the rectangle
			inline void translate(const  vec2& val) 
			{ 
				translate( val.x , val.y );
			}

			#if ( defined(_WINDOWS_) )

			//! \brief The shift of origin. The motion of the rectangle
			inline void translate(const POINT& p)
			{
				translate( (float)p.x, (float)p.y );
			}

			#endif


			//! \brief Getting the width of the rectangle
			inline float get_width()  const 
			{ 
				return max.x - min.x; 
			} 

			//! \brief Getting the height of the rectangle
			inline float get_height() const 
			{ 
				return max.y - min.y; 
			}

			//! \brief    get rectangle 2d size
			inline size2d get_size() const 
			{
				size2d res;
				res.width  = max.x - min.x;
				res.height = max.y - min.y;
			}

 
			//! \brief  Extract all the four vertices of the rectangle.
			void extract_corners(Corners& _outCorners) const
			{
				_outCorners.points[0] =  vec2( min.x , min.y );
				_outCorners.points[2] =  vec2( max.x , min.y );
				_outCorners.points[3] =  vec2( max.x , max.y );
				_outCorners.points[4] =  vec2( min.x , max.y );
			}



			//! \brief Put a new position on the top left corner of the rectangle. Dimensions remain unchanged.
			inline void set_position_topleft(float x, float y)
			{
				float w = get_width();
				float h = get_height();

				min.x = x;
				min.y = y;

				max.x = min.x + w; 
				max.y = min.y + h;
			}

			inline void set_position_topleft(const vec2& v) 
			{ 
				set_position_topleft( v.x , v.y ); 
			}

			
			#if ( defined(_WINDOWS_) )

			//! \brief new position at the top left edge of the rectangle. The dimensions are not changed. 
			inline void set_position_topleft(const POINT& pnt)
			{
				set_position_topleft( (float)pnt.x , (float)pnt.y );
			}

			#endif


			//! \brief  Get the point coordinate of the upper-left corner of the rectangle.  
			inline point get_position_topleft() const
			{
				point res;
				res.x = (long)min.x;
				res.y = (long)min.y;
				return res;
			}


	 
		  inline void set_width(float fWidth)   
		  { 
			  max.x = min.x + fWidth;  
		  }

	 
		  inline void set_height(float fHeight) 
		  { 
			  max.y = min.y + fHeight; 
		  }

	 
		  inline void set_width_height(float fWidth, float fHeight)
		  {
				max.x = min.x + fWidth;
				max.y = min.y + fHeight;
		  }



		inline point get_topleft() const
		{
			point res = point( (long)min.x , (long)min.y );
			return res;
		}


		inline point get_bottomright() const
		{
			point res = point(  (long)max.x , (long)max.y );
			return res;
		}

		inline  vec2 get_center() const 
		{
			vec2 res;
			point pTpLft = get_topleft();
			point pBtRt  = get_bottomright();
			res.x = ( (float)pTpLft.x + (float)pBtRt.x ) / 2.0f;
			res.y = ( (float)pTpLft.y + (float)pBtRt.y ) / 2.0f;
			return res;
		}

	 
		inline void  set_center(const  vec2& pnt) 
		{
			float nw = get_width();
			float nh = get_height();

			min.x = (float)pnt.x - nw / 2.0f;
			min.y = (float)pnt.y - nh / 2.0f;

			max.x = min.x + nw;
			max.y = min.y + nh;
		}


		  //! \brief Отсечение координат точки p в пределах прямоугольника 
		  inline void clump_coord( point& pntTobeClump ) const
		  {
			  if( (float)pntTobeClump.x < min.x ) { pntTobeClump.x = (long)min.x; };
			  if( (float)pntTobeClump.x > max.x ) { pntTobeClump.x = (long)max.x; };
			  if( (float)pntTobeClump.y < min.y ) { pntTobeClump.y = (long)min.y; };
			  if( (float)pntTobeClump.y > max.y ) { pntTobeClump.y = (long)max.y; };
		  }



		//! \brief Clipping coordinate point p within the rectangle  
		inline void clump_coord( vec2& pntTobeClump ) const
		{
		  if( pntTobeClump.x < min.x ) { pntTobeClump.x = min.x; };
		  if( pntTobeClump.x > max.x ) { pntTobeClump.x = max.x; };
		  if( pntTobeClump.y < min.y ) { pntTobeClump.y = min.y; };
		  if( pntTobeClump.y > max.y ) { pntTobeClump.y = max.y; };
		}


		inline bool check_contain_point(int x, int y) const
		{
			if( (x>min.x) && (y>min.y) && (x<max.x) && (y<max.y) ) 
				return true;
			return false;
		}

		inline bool check_contain_point(const point& pnt) const 
		{ 
			return check_contain_point(pnt.x, pnt.y); 
		}

	  
#if ( defined(_WINDOWS_) )

		  inline bool check_contain_point(const POINT& pnt) const 
		  { 
			  return check_contain_point(pnt.x, pnt.y); 
		  }

#endif



		//!   \brief Calculate the area.
		inline float compute_square() 
		{ 
			return  get_width() * get_height();  
		}

		void operator = (const std::string& str)
		{
			std::istringstream ss(str);
			ss >> min;
			ss >> max;
			if( ss.fail() )  throw std::invalid_argument("bad input string");
		}


		operator std::string() const
		{
			std::ostringstream sstrm;
			sstrm << min << "   " << max;
			return sstrm.str();
		}



		#ifdef _D3D9_H_

		  void operator = (const D3DRECT&  rc) 
		  { 
			min.x = (float)rc.x1; 
			min.y = (float)rc.y1; 
			
			max.x = (float)rc.x2; 
			max.y = (float)rc.y2; 
		  }


	 
		  inline operator D3DRECT() const 
		  { 
			D3DRECT r; 
			r.x1 = (LONG)min.x;
			r.y1 = (LONG)min.y;
			r.x2 = (LONG)max.x;
			r.y2 = (LONG)max.y;
			return r; 
		  }
	 


		inline void operator =  ( const D3DVIEWPORT9& vp )
		{
			min.x = (float)vp.X;
			min.y = (float)vp.Y;
			max.x = min.x + (float)vp.Width;
			max.y = min.y + (float)vp.Height;
		}


		void to_viewport(D3DVIEWPORT9& vpInOut) const
		{
			vpInOut.X = (DWORD)min.x;
			vpInOut.Y = (DWORD)min.y;
			vpInOut.Width = (DWORD)get_width();
			vpInOut.Height = (DWORD)get_height();
		}


#endif   // #ifdef _D3D9_H_


		 
			friend std::ostream &operator << (std::ostream &stream, const Rect& r)
			{
				stream << r.min << "    " << r.max;
				return stream;
			}
			

			inline void offset(float x, float y)
			{
				min.x += x;
				min.y += y;

				max.x += x;
				max.y += y;
			}
		
		
		
	};



}
