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
		class Rect {
		public:

			/************************************
			float x1; ///< кооордината x  верхнего левого угла .
			float y1; ///< координата  y  верхнего левого угла .

			float x2; ///< кооордината x  нижнего правого  угла .
			float y2; ///< координата  y  нижнего правого  угла .
			  ************************************/

			vec2 min;
			vec2 max;


			//! \brief The corners of the rectangle
			struct Corners
			{
				 vec2 points[4];
			};


			inline Rect() 
			{ 
				//x1 = y1 = x2 = y2 = 0.0f;  
				min = max = vec2( 0.0f , 0.0f );
			}

			inline Rect(const Rect& r)
			{
				//x1 = r.x1; 
				//y1 = r.y1;

				//x2 = r.x2; 
				//y2 = r.y2;
				// 

				min = r.min;
				max = r.max;
			}

			inline Rect(float _x1, float _y1, float _x2, float _y2) 
			{ 
				//x1=_x1; 
				//y1=_y1; 
				
				//x2=_x2; 
				//y2=_y2; 

				min = vec2( _x1 , _y1 );
				max = vec2( _x2 , _y2 );
			}

#if ( defined(_WINDOWS_)  )

			Rect(const POINT p1, const POINT p2)
			{
				//x1=(float)p1.x;
				//y1=(float)p1.y;
				//x2=(float)p2.x;
				//y2=(float)p2.y;

				min = vec2( (float)p1.x , (float)p1.y );
				max = vec2( (float)p2.x , (float)p2.y );
			}

			Rect(const RECT& rec) 
			{  
				*this = rec; 
			}

#endif


//#ifdef __GB__BASE__RECTANGLE_H__

			Rect(const Rectangle& rec)
			{
			   *this = rec;
			}
//#endif


			inline void set(float _x1, float _y1, float _x2, float _y2) 
			{ 
				//x1=_x1; 
				//y1=_y1; 
				
				//x2=_x2; 
				//y2=_y2;

				min = vec2( _x1 , _y1 );
				max = vec2( _x2 , _y2 );
			}




#if ( defined(_WINDOWS_) )

			inline void set(const POINT& np1, const POINT& np2) 
			{ 
				//x1=(float)np1.x; 
				//y1=(float)np1.y;

				//x2=(float)np2.x; 
				//y2=(float)np2.y; 

				min = vec2( (float)np1.x , (float)np1.y );
				max = vec2( (float)np2.x , (float)np2.y );
			}

			inline void operator = (const RECT& rec)
			{
				//x1 = (float)rec.left;
				//y1 = (float)rec.top;

				//x2 = (float)rec.right;
				//y2 = (float)rec.bottom;

				min = vec2( (float)rec.left ,  (float)rec.top );
				max = vec2( (float)rec.right , (float)rec.bottom );
			}


			inline operator RECT () const
			{
				RECT res;
				res.left   = (long)min.x;   //x1;
				res.top    = (long)min.y;   //y1;
				res.right  = (long)max.x;   //x2;
				res.bottom = (long)max.y;   //y2;
				return res;
			}

#endif



//#ifdef __GB__BASE__RECTANGLE_H__

			inline void operator = (const Rectangle& rec)
			{
				//x1 = (float)rec.left;
				//y1 = (float)rec.top;
				//x2 = x1 + (float)rec.width;
				//y2 = y1 + (float)rec.height;

				min = vec2( (float)rec.left , (float)rec.top );
				max = vec2(  (float)rec.width,  (float)rec.height );
			}

			inline operator Rectangle() const
			{
				return Rectangle( 
					//(int)x1, (int)y1, (int)(x2-x1), (int)(y2-y1)
					(int)min.x, (int)min.y, 
					(int)(max.x-min.x), (int)(max.y-min.y)
					);

			}

//#endif



			//! \brief set to zero all
			inline void setzero() 
			{ 
				//x1=y1=x2=y2=0.0; 
				min = max = vec2( 0.0f , 0.0f );
			}
			//! \brief  check of all components to zero
			inline bool is_zero() const // old:  empty 
			{ 
				//return  (x1==0.0f) && (y1==0.0f) && (x2==0.0f) && (y2==0.0f) ;
				//const vec2 _zero = vec2( 0.0f , 0.0f );
				//return min == max == _zero;
				return  min.x == 
					0.0f && min.y == 
					0.0f && max.x == 
					0.0f && max.y == 0.0f;
			}

			//! \brief The shift of origin. The motion of the rectangle
			inline void translate(float x, float y)	
			{ 
				//x1+=x; 
				//y1+=y;	
				//x2+=x;	
				//y2+=y; 

				min.x += x;
				max.x += x;
				min.y += y;
				max.y += y;
			}

			//! \brief  The shift of origin. The motion of the rectangle
			inline void translate(const  vec2& val) 
			{ 
				//x1+=val.x; y1+=val.y;	x2+=val.x; y2+=val.y; 
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

		/*	//! \brief Get / set the initial coordinate of the rectangle
			inline  vec2  minCoord() const 
			{  
				vec2 res(x1, y1); 
				//res.x = x1; 
				//res.y = y1; 
				return res; 
			}
			
			inline void   minCoord( vec2& coord)
			{
				x1=coord.x;
				y1=coord.y;
			}

			//! \brief Получить/установить Вторичную координату прямоугольника
			inline  vec2 maxCoord() const
			{
				vec2 res;
				res.x=x2;
				res.y=y2;
				return res;
			}

			inline void  maxCoord( vec2& coord)
			{
				x2=coord.x;
				y2=coord.y;
			}

			*/


			// TODO void move(const Normal2& normal, float distance) { }

			//! \brief  Extract all the four vertices of the rectangle.
			void extract_corners(Corners& _outCorners) const
			{
				//_outCorners.points[0] =  vec2(x1, y1);
				//_outCorners.points[2] =  vec2(x2, y1);
				//_outCorners.points[3] =  vec2(x2, y2);
				//_outCorners.points[4] =  vec2(x1, y2);

				_outCorners.points[0] =  vec2( min.x , min.y );
				_outCorners.points[2] =  vec2( max.x , min.y );
				_outCorners.points[3] =  vec2( max.x , max.y );
				_outCorners.points[4] =  vec2( min.x , max.y );
			}



			/** \brief Ставить новую позицию по верхнему левому краю прямоугольника.
			Размеры не изменяются. */
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

			/** \brief new position at the top left edge of the rectangle.
						The dimensions are not changed. */
			inline void set_position_topleft(const POINT& pnt)
			{
				set_position_topleft( (float)pnt.x , (float)pnt.y );
			}

			#endif


			/** \brief  Get the point coordinate of the upper-left
							corner of the rectangle.  */
			inline point get_position_topleft() const
			{
				point res;
				res.x = (long)min.x;
				res.y = (long)min.y;
				return res;
			}


	  /** \brief Установить новую ширину. 
	  Координата левого вернего угла не меняется. */
	  inline void set_width(float fWidth)   
	  { 
		  max.x = min.x + fWidth;  
	  }

	  /** \brief Установить новую высоту. 
	  Координата левого вернего угла не меняется. */
	  inline void set_height(float fHeight) 
	  { 
		  max.y = min.y + fHeight; 
	  }

	  /** \brief Установить новую ширину и высоту. 
	  Координата левого вернего угла не меняется. */
	  inline void set_width_height(float fWidth, float fHeight)
	  {
			max.x = min.x + fWidth;
			max.y = min.y + fHeight;
	  }


//#if defined(_WINDOWS_)

  //! \brief Получить  координату верхнего левого угла прямоугольника.
  inline point get_topleft() const
  {
	  point res = point( (long)min.x , (long)min.y );
	  //res.x=(long)x1;
	  //res.y=(long)y1;
	  return res;
  }

  //! \brief Получить  координату нижнег оправого угла прямоугольника.
  inline point get_bottomright() const
  {
	  point res = point(  (long)max.x , (long)max.y );
	  //res.x=(long)x2;
	  //res.y=(long)y2;
	  return res;
  }

//#endif


//  //! \brief Получить  координату верхнего левого угла прямоугольника.
//  inline  vec2 getTopLeft() const
//  {
//	  vec2 res;
//	  res.x=x1;
//	  res.y=y1;
//	  return res;
//  }


//  //! \brief Получить  координату нижнего правого угла прямоугольника.
//  inline  vec2 getBottomRight() const
//  {
//	  vec2 res;
//	  res.x=x2;
//	  res.y=y2;
//	  return res;
 // }



  /** \brief Получить центральную среднюю точку прямоугольника */
  inline  vec2 get_center() const  // old: getCenterPoint
  {
		vec2 res;
		point pTpLft = get_topleft();
		point pBtRt  = get_bottomright();
		res.x = ( (float)pTpLft.x + (float)pBtRt.x ) / 2.0f;
		res.y = ( (float)pTpLft.y + (float)pBtRt.y ) / 2.0f;
		return res;
  }

  /** \brief  Установить координаты прямоугольника по средней точке. Размеры не меняются.  */
  inline void  set_center(const  vec2& pnt)	// old: setCenterPoint
  {
	  float nw = get_width();
	  float nh = get_height();

	  //set_position_topleft( pnt.x - nw/2 , pnt.y - nh/2);
	  //float w=get_width();
	  //float h=get_height();

	  min.x = (float)pnt.x - nw / 2.0f;
	  min.y = (float)pnt.y - nh / 2.0f;

	  max.x = min.x + nw;
	  max.y = min.y + nh;
  };


//#if ( defined(_WINDOWS_)  )

  /** \brief Отсечение координат точки p в пределах прямоугольника */
  inline void clump_coord( point& pntTobeClump ) const
  {
	  if( (float)pntTobeClump.x < min.x ) { pntTobeClump.x = (long)min.x; };
	  if( (float)pntTobeClump.x > max.x ) { pntTobeClump.x = (long)max.x; };
	  if( (float)pntTobeClump.y < min.y ) { pntTobeClump.y = (long)min.y; };
	  if( (float)pntTobeClump.y > max.y ) { pntTobeClump.y = (long)max.y; };
  }

//#endif

  /** \brief Отсечение координат точки p в пределах прямоугольника */
  inline void clump_coord( vec2& pntTobeClump ) const
  {
	  if( pntTobeClump.x < min.x ) { pntTobeClump.x = min.x; };
	  if( pntTobeClump.x > max.x ) { pntTobeClump.x = max.x; };
	  if( pntTobeClump.y < min.y ) { pntTobeClump.y = min.y; };
	  if( pntTobeClump.y > max.y ) { pntTobeClump.y = max.y; };
  }



  //! \brief Проверка попадания точки в прямоугольник .
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

  //! \brief Проверка попадания точки в прямоугольник .
  inline bool check_contain_point(const POINT& pnt) const 
  { 
	  return check_contain_point(pnt.x, pnt.y); 
  }

#endif




  //!   \brief Вычислить площадь.
  inline float compute_square() 
  { 
	  return  get_width() * get_height();  
  }


/******
   // \brief  В виде в строку разделёную пробелами 
  void  toCstr(char* buf) const
  {
	  *buf = '\0';
	  sprintf(buf, "%i %i    %i  %i",  x1, y1, x2, y2  );
  };

  //   \brief Прочитать значения из строки разделёной пробелами 
  bool fromCstr(const char* s)
  {
	  const int n = sscanf(s, "%i %i %i %i",   x1, y1, x2, y2   );
	  if(n!=4) return false;
	  return true;
  };
*****/

	void operator = (const std::string& str)
	{
		std::istringstream ss(str);
		ss >> min;
		ss >> max;
		if( ss.fail() ) 
			throw std::invalid_argument("bad input string");
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


  /** \brief Получить  в виде  D3DRECT */
  inline operator D3DRECT() const 
  { 
	D3DRECT r; 
	r.x1 = (LONG)min.x;
	r.y1 = (LONG)min.y;
	r.x2 = (LONG)max.x;
	r.y2 = (LONG)max.y;
	return r; 
  }

  //  /** \brief Получить  в виде указателя  D3DRECT */
  //inline operator const D3DRECT* ()  const 
  //{  
//	return (D3DRECT*)&x1;  
 // }
  

  /** \brief  Установить из вьпорта d3d9 устройства */
  inline void operator =  ( const D3DVIEWPORT9& vp )
  {
	  min.x = (float)vp.X;
	  min.y = (float)vp.Y;
	  max.x = min.x + (float)vp.Width;
	  max.y = min.y + (float)vp.Height;
  }

  //*  \brief Присвоить вьюпорту vpInOut  размеры и позицию прямоугольника.
  void to_viewport(D3DVIEWPORT9& vpInOut) const
  {
	vpInOut.X = (DWORD)min.x;
	vpInOut.Y = (DWORD)min.y;
	vpInOut.Width = (DWORD)get_width();
	vpInOut.Height = (DWORD)get_height();
  }


#endif   // #ifdef _D3D9_H_



	  // todo
  // std::string tostr() const {......}
  // bool        fromstr(const std::string& str) {.....}

 
    // //! \brief печать на консоль
    //void print() const {   printf("%f  %f     %f  %f", x1, y1,   x2, y2);    };

	friend std::ostream &operator << (std::ostream &stream, const Rect& r)
	{
		stream << r.min << "    " << r.max;
		return stream;
	}
	
	
		};




}