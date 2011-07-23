/**  \file
 \brief яяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif




namespace gb 
{

	namespace fmath
	{
	
	
#pragma message("#error  need rename class  (aabr or rect)"  __FILE__ )

		//! Прямоугольник по мин. и макс координате
		class Rect {
		public:
			float x1; ///< кооордината x  верхнего левого угла . 
			float y1; ///< координата  y  верхнего левого угла .

			float x2; ///< кооордината x  нижнего правого  угла . 
			float y2; ///< координата  y  нижнего правого  угла .


			//! \brief Углы прямоугольника
			struct Corners 
			{
				 vec2 points[4];
			};
 

			inline Rect() { x1 = y1 = x2 = y2 = 0.0f;  }
			inline Rect(const Rect& r) 
			{
				x1=r.x1; y1=r.y1;  x2=r.x2; y2=r.y2; 
			}
			
			inline Rect(float _x1, float _y1, float _x2, float _y2) { x1=_x1; y1=_y1; x2=_x2; y2=_y2; }

#if ( defined(_WINDOWS_)  )	
			Rect(const POINT p1, const POINT p2)  
			{ 
				x1=(float)p1.x;  
				y1=(float)p1.y;  
				x2=(float)p2.x;  
				y2=(float)p2.y;  
			}
			Rect(const RECT& rec) {  *this = rec; }
#endif 

#ifdef __GB__BASE__RECTANGLE_H__
			Rect(const gb::base::Rectangle& rec)
			{
			   *this = rec;
			}
#endif

			inline void set(int nx1, int ny1, int nx2, int ny2)         { x1=(float)nx1;   y1=(float)ny1;   x2=(float)nx2;   y2=(float)ny2; }
			inline void set(float _x1, float _y1, float _x2, float _y2) { x1=_x1; y1=_y1; x2=_x2; y2=_y2; }




#if ( defined(_WINDOWS_) )	

			inline void set(const POINT& np1, const POINT& np2) { x1=(float)np1.x; y1=(float)np1.y; x2=(float)np2.x; y2=(float)np2.y; };
			inline void operator = (const RECT& rec) 
			{
				x1 = (float)rec.left;
				y1 = (float)rec.top;
				x2 = (float)rec.right;
				y2 = (float)rec.bottom;    
			}


			inline operator RECT () const 
			{
				RECT res;
				res.left   = (long)x1;
				res.top    = (long)y1;
				res.right  = (long)x2;
				res.bottom = (long)y2;
				return res; 
			}  

#endif  


#ifdef __GB__BASE__RECTANGLE_H__
			inline void operator = (const gb::base::Rectangle& rec)
			{
				x1 = (float)rec.left;
				y1 = (float)rec.top;
				x2 = x1 + (float)rec.width;
				y2 = y1 + (float)rec.height;
			}

			inline operator gb::base::Rectangle() const 
			{
				return gb::base::Rectangle( (int)x1, (int)y1, (int)(x2-x1), (int)(y2-y1) );
			}
#endif


			//! \brief Занулить 
			inline void setzero() { x1=y1=x2=y2=0.0; }
			//! \brief  проверка всех компонентов на ноль
			inline bool empty() const { return ( (x1==0.0f) && (y1==0.0f) && (x2==0.0f) && (y2==0.0f) ); }

			//! \brief Сдвиг координат. Движение прямоугольника
			inline void translate(float x, float y)	{ x1+=x; y1+=y;	x2+=x;	y2+=y; }

			//! \brief Сдвиг координат. Движение прямоугольника на значение val
			inline void translate(const  vec2& val) { x1+=val.x; y1+=val.y;	x2+=val.x; y2+=val.y; }

#if ( defined(_WINDOWS_) )

			/** \brief Движение координат на указаное значение */
			inline void translate(const POINT& p) 
			{  
				translate( (float)p.x, (float)p.y );   
			}

#endif  


			//! \brief Получение ширины прямоугольника  
			inline float getWidth()  const { return (x2-x1); };

			//! \brief Получение высоты прямоуголника   
			inline float getHeight() const { return (y2-y1); }; 

			//! \brief Получить/установить первичную координату прямоугольника
			inline  vec2  minCoord() const {  vec2 res; res.x=x1; res.y=y1; return res; }
			inline void          minCoord( vec2& coord)       
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

			inline void         maxCoord( vec2& coord)       
			{ 
				x2=coord.x;
				y2=coord.y;
			}

			// TODO void move(const Normal2& normal, float distance) { }

			//! \brief  Извлечь все 4 вершины прямоугольника.
			void extractCorners(Corners& _outCorners) 
			{	  
				_outCorners.points[0] =  vec2(x1, y1);
				_outCorners.points[2] =  vec2(x2, y1);
				_outCorners.points[3] =  vec2(x2, y2);
				_outCorners.points[4] =  vec2(x1, y2);
			}


		
			/** \brief Установить новую позицию по верхнему левому краю прямоугольника. 
			      Размеры сохраняются. */
			inline void setPositionTopLeft(float x, float y) 
			{   
				float w=getWidth();  
				float h=getHeight();  
				x1=x; y1=y; 
				x2=x1+w; y2=y+h;  
			}

			inline void setPositionTopLeft(const  vec2& v) { setPositionTopLeft(v.x,v.y); }  

#if ( defined(_WINDOWS_) )

			/** \brief Установить новую позицию по верхнему левому краю прямоугольника. 
			        Размеры сохраняются. */
			inline void setPositionTopLeft(const POINT& pnt) 
			{  
				setPositionTopLeft((float)pnt.x, (float)pnt.y);   
			}

			/** \brief Получить точку координату верхнего левого угла прямоугольника. */
			inline POINT getPositionTopLeft() const 
			{ 
				POINT res; 
				res.x=(long)x1; 
				res.y=(long)y1; 
				return res; 
			}

#endif 


  
  /** \brief Установить новую ширину. Координата левого вернего угла не меняется. */
  inline void setWidth(float fWidth)   { x2 = x1 + fWidth;  }
  /** \brief Установить новую высоту. Координата левого вернего угла не меняется. */
  inline void setHeight(float fHeight) { y2 = y1 + fHeight; }
  /** \brief Установить новую ширину и высоту. Координата левого вернего угла не меняется. */
  inline void setWidthHeight(float fWidth, float fHeight) 
  {
   x2 = x1 + fWidth;
   y2 = y1 + fHeight;
  }


#if defined(_WINDOWS_)

  //! \brief Получить  координату верхнего левого угла прямоугольника. 
  inline POINT getTopLeft_p() const 
  {  
	  POINT res; 
	  res.x=(long)x1; 
	  res.y=(long)y1; 
	  return res; 
  }

  //! \brief Получить  координату нижнег оправого угла прямоугольника.
  inline POINT getBottomRight_p() const 
  {  
	  POINT res; 
	  res.x=(long)x2; 
	  res.y=(long)y2; 
	  return res; 
  }

#endif


  //! \brief Получить  координату верхнего левого угла прямоугольника.
  inline  vec2 getTopLeft() const 
  {   
	  vec2 res; 
	  res.x=x1; 
	  res.y=y1; 
	  return res; 
  }

  //! \brief Получить  координату нижнего правого угла прямоугольника. 
  inline  vec2 getBottomRight() const 
  {   
	  vec2 res; 
	  res.x=x2; 
	  res.y=y2; 
	  return res; 
  }



  /** \brief Получить центральную среднюю точку прямоугольника */
  inline  vec2 getCenterPoint() const 
  {
	   vec2 res;
	   vec2 pTpLft = getTopLeft();
	   vec2 pBtRt  = getBottomRight();

	  res.x = (pTpLft.x + pBtRt.x) / 2.0f;
	  res.y = (pTpLft.y + pBtRt.y) / 2.0f;

	  return res; 
  }

  /** \brief  Установить координаты прямоугольника по средней точке. Размеры не меняются.  */
  inline void  setCenterPoint(const  vec2& pnt) 
  {
	  float nw = getWidth();
	  float nh = getHeight();

	  //setPositionTopLeft( pnt.x - nw/2 , pnt.y - nh/2); 
	  //float w=getWidth();  
	  //float h=getHeight();

	  x1=(float)pnt.x - nw/2.0f; 
	  y1=(float)pnt.y - nh/2.0f; 

	  x2=x1 + nw; 
	  y2=y1 + nh; 
  };

#if ( defined(_WINDOWS_)  )

  /** \brief Отсечение координат точки p в пределах прямоугольника */
  inline void clumpCoord(   POINT& pntTobeClump ) const 
  {
	  if( (float)pntTobeClump.x < x1 ) { pntTobeClump.x = (long)x1; };
	  if( (float)pntTobeClump.x > x2 ) { pntTobeClump.x = (long)x2; };
	  if( (float)pntTobeClump.y < y1 ) { pntTobeClump.y = (long)y1; };
	  if( (float)pntTobeClump.y > y2 ) { pntTobeClump.y = (long)y2; };
  }

#endif

  /** \brief Отсечение координат точки p в пределах прямоугольника */
  inline void clumpCoord( vec2& pntTobeClump ) const 
  {
	  if( pntTobeClump.x < x1 ) { pntTobeClump.x = x1; };
	  if( pntTobeClump.x > x2 ) { pntTobeClump.x = x2; };
	  if( pntTobeClump.y < y1 ) { pntTobeClump.y = y1; };
	  if( pntTobeClump.y > y2 ) { pntTobeClump.y = y2; };
  }



  //! \brief Проверка попадания точки в прямоугольник . 
  inline bool checkContainPoint(int x, int y) const 
  {
	  if( (x>x1) && (y>y1) && (x<x2) && (y<y2)  ) return true;
	  return false;
  }

#if ( defined(_WINDOWS_) )
  //! \brief Проверка попадания точки в прямоугольник .
  inline bool checkContainPoint(const POINT& pnt) const { return checkContainPoint(pnt.x, pnt.y); }
#endif

  //!   \brief Вычислить площадь.
  inline float computeSquare() { return ( getWidth() * getHeight()  );  };

 

  /** \brief  В виде в строку разделёную пробелами  */
  void  toCstr(char* buf) const 
  {
	  *buf = '\0';
	  sprintf(buf, "%i %i    %i  %i",  x1, y1, x2, y2  );   
  };

  /** \brief Прочитать значения из строки разделёной пробелами */
  bool fromCstr(const char* s) 
  {
	  const int n = sscanf(s, "%i %i %i %i",   x1, y1, x2, y2   ); 
	  if(n!=4) return false;
	  return true;
  };

 


#ifdef _D3D9_H_

  void operator = (const D3DRECT&  rc) { x1=(float)rc.x1; y1=(float)rc.y1; x2=(float)rc.x2; y2=(float)rc.y2; }

  /** \brief Получить  в виде  D3DRECT */
  inline operator D3DRECT() const { D3DRECT r; r.x1=(LONG)x1; r.y1=(LONG)y1; r.x2=(LONG)x2; r.y2=(LONG)y2;  return r; }

  /** \brief Получить  в виде указателя  D3DRECT */
  inline operator const D3DRECT* ()  const {  return (D3DRECT*)&x1;  }

  /** \brief  Установить из вьпорта d3d9 устройства */
  inline void operator =  ( const D3DVIEWPORT9& vp ) 
  {
	  x1 = (float)vp.X;
	  y1 = (float)vp.Y;
	  x2 = x1 + (float)vp.Width;
	  y2 = y1 + (float)vp.Height;
  }

  //*  \brief Присвоить вьюпорту vpInOut  размеры и позицию прямоугольника.
  void to_viewport(D3DVIEWPORT9& vpInOut) const
  {
    vpInOut.X = (DWORD)x1;
	vpInOut.Y = (DWORD)y1;
	vpInOut.Width = (DWORD)getWidth();
	vpInOut.Height = (DWORD)getHeight();
  }


#endif   // #ifdef _D3D9_H_



	  // todo 
  // std::string tostr() const {......}
  // bool        fromstr(const std::string& str) {.....}



     //! \brief печать на консоль 
    void print() const {   printf("%f  %f     %f  %f", x1, y1,   x2, y2);    };

		};

	
	
	
	
	
	
	
	
	
	}
}
