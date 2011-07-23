/**  \file
 \brief  яяяяяяяяяяяяя


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	

	
	
	// много инфы по боксу   http://www.devmaster.net/forums/showthread.php?t=10324
		
	//! \brief Бокс по мин. и макс. координатам. Axis Aligned Bounding Box.
	class AABB {
	public:
	   vec3   min; ///< минимальная точка бокса
	   vec3   max; ///< максимальная точка бокса

	  //! углы бокса
	  struct corners {
		   vec3 points [8];

		  inline  vec3& operator [] (unsigned int index)
		  {
		    assert(index<8 && "invelid index");
			return points[index];
		  }

 		  inline  vec3 operator [] (unsigned int index)   const
		  {
		    assert(index<8 && "invelid index");
			return points[index];
		  }


	  };
	  
	  inline AABB() {}
	  inline AABB(const AABB& aabb) {min=aabb.min; max=aabb.max;}	  
	  inline AABB(const  vec3& _min, const  vec3& _max) { min=_min; max=_max;  }
	
	  inline void setzero()
	  {
		  min.setzero();
		  max.setzero();
	  }

	  inline bool operator == (const AABB& aabb) { return (min == aabb.min) && (max == aabb.max); }
	  
	
 	  //! \brief Вернуть объединённый с боксом	
	  inline AABB operator + (const AABB& aabb) const
	  {
	    AABB res = *this;
	    if (aabb.min.x < res.min.x)   res.min.x = aabb.min.x;
	    if (aabb.min.y < res.min.y)   res.min.y = aabb.min.y;
	    if (aabb.min.z < res.min.z)   res.min.z = aabb.min.z;
	   
	    if (aabb.max.x > res.max.x)   res.max.x = aabb.max.x;
	    if (aabb.max.y > res.max.y)   res.max.y = aabb.max.y;
	    if (aabb.max.z > res.max.z)   res.max.z = aabb.max.z;  
		 return res; 
	  }
	  
	  //! \brief Вернуть объединённый с точкой	 
	  inline AABB operator + (const  vec3& pnt) const	  
	  {
	     AABB res = *this;
	  	if(pnt.x < res.min.x) res.min.x = pnt.x;
		if(pnt.y < res.min.y) res.min.y = pnt.y;
		if(pnt.z < res.min.z) res.min.z = pnt.z;

		if(pnt.x > res.max.x) res.max.x = pnt.x;
		if(pnt.y > res.max.y) res.max.y = pnt.y;
		if(pnt.z > res.max.z) res.max.z = pnt.z;
		  return res;	  
	  }
	  
	  //! \brief Объединить с боксом  
	  inline AABB& operator += (const AABB& aabb)
	  {
	    if (aabb.min.x < min.x)  min.x=aabb.min.x;
	    if (aabb.min.y < min.y)  min.y=aabb.min.y;
	    if (aabb.min.z < min.z)  min.z=aabb.min.z;
	   
	    if (aabb.max.x > max.x)  max.x=aabb.max.x;
	    if (aabb.max.y > max.y)  max.y=aabb.max.y;
	    if (aabb.max.z > max.z)  max.z=aabb.max.z; 
		 return *this;	  
	  }
	  
	  //! \brief Объединить с точкой pnt	 
	  inline AABB& operator += (const  vec3& pnt)
	  {
		 includePoint(pnt);
		 return *this;	  
	  }
 
	  //! \brief  Построить по точкам  ПРОВЕРИТЬ
	  inline void make(const  vec3& p1, const  vec3& p2)
	  {
	     min = p1.minimized(p2);
	     max = p1.maximized(p2);
	  }
	  
	  //! \brief  Построить по точкам 
	  inline void make(float p1_x, float p1_y, float p1_z,
					   float p2_x, float p2_y, float p2_z)
	  {
		  make(  vec3(p1_x , p1_y , p1_z) ,  vec3(p2_x , p2_y , p2_z) );
	  }
 

	  //! \brief Извлечь углы бокса в cOut
	  inline void extractCorners(corners& cOut) const
	  {
		  cOut[0] =  vec3(  min.x,  min.y,  min.z );
		  cOut[1] =  vec3(  min.x,  min.y,  max.z );
		  cOut[2] =  vec3(  min.x,  max.y,  min.z );
		  cOut[3] =  vec3(  min.x,  max.y,  max.z );
		  cOut[4] =  vec3(  max.x,  min.y,  min.z );
		  cOut[5] =  vec3(  max.x,  min.y,  max.z );
		  cOut[6] =  vec3(  max.x,  max.y,  min.z );
		  cOut[7] =  vec3(  max.x,  max.y,  max.z );   
	  }
	  

	  //! \brief Получить центр бокса
	   vec3 center() const 
	  { 
	     vec3 res;
		  res.x = (max.x + min.x)/2.0f;
		  res.y = (max.y + min.y)/2.0f;		
		  res.z = (max.z + min.z)/2.0f;		
	    return res; 
	  }
	  
	  //! \brief  Включить координату pnt в бокс
	  AABB& includePoint(const  vec3& pnt) 
	  {
	    if (pnt.x < min.x) min.x = pnt.x;
		if (pnt.y < min.y) min.y = pnt.y;
		if (pnt.z < min.z) min.z = pnt.z;

		if (pnt.x > max.x) max.x = pnt.x;
		if (pnt.y > max.y) max.y = pnt.y;
		if (pnt.z > max.z) max.z = pnt.z;
	       return *this;
	  }
	  
	  //! \brief Привести координаты coord в пределах бокса и вернуть результат 
	   vec3 clumpCoord(const  vec3& coord) const
	  {
	      vec3 r = coord;
		 
		   if(coord.x > max.x) r.x = max.x;
		   if(coord.x < min.x) r.x = min.x;		   
		 
		   if(coord.y > max.y) r.y = max.y;
		   if(coord.y < min.y) r.y = min.y;		 
		 
		   if(coord.z > max.z) r.z = max.z;
		   if(coord.z < min.z) r.z = min.z;		 
	   
	          return r;
	  }
	  
	  //! \brief  Размер по X
	  inline float size_x() const { return max.x - min.x; }
	  //! \brief  Размер по Y	  
	  inline float size_y() const { return max.y - min.y; }	
	  //! \brief  Размер по Z	  
	  inline float size_z() const { return max.z - min.z; }	

	  //! \brief Получить 3d-размер бокса
	  inline Size3d size3d() const 
	  {
	   Size3d res;
	   res.x = size_x();
	   res.y = size_y();	   
	   res.z = size_z();	   
	   return res;
	  }
	  
	  //! \brief Получить объём 
	  inline float volume() const { return size_x() * size_y() * size_z(); }
	  


	  inline plane_s  plane_positive_x() const 
	  {
		  plane_s res = { 1.0f , 0.0f , 0.0f , max.x };
		  return res;
	  }


	  inline plane_s  plane_negative_x() const 
	  {
  		  plane_s res = { -1.0f , 0.0f , 0.0f ,  min.x };
		  return res;
	  } 


	  inline plane_s  plane_positive_y() const 
	  {
		  plane_s res = { 0.0f , 1.0f , 0.0f ,  max.y};
		  return res;
	  }


	  inline plane_s  plane_negative_y() const 
	  {
 		  plane_s res = { 0.0f , -1.0f , 0.0f ,  min.y};
		  return res;
	  } 


	  inline plane_s  plane_positive_z() const 
	  {
		  plane_s res = { 0.0f , 0.0f , 1.0f , max.z };
		  return res;
	  }


	  inline plane_s  plane_negative_z() const 
	  {
		  plane_s res = { 0.0f , 0.0f , -1.0f , min.z };
		  return res;
	  } 

 

//! \brief  Трансформировать по матрице m . Получить выровненые вершины.
AABB& transform(const  mat44& m)
{
   corners cr;
   extractCorners(cr);

   min.setzero();
   max.setzero();

   for(int c=0; c<8; c++)
   {
     cr[c].transformCoord(m);
	 *this += cr[c];
   }
 
  return *this;
}

 

	  //! \brief  Сдвинуть.
	  inline void offset(const  vec3& v)
	  {
		  min += v;
		  max += v;
	  }

	  //! \brief Объединить с боксом	  
	  inline AABB& includeAabb( const AABB& aabb)
	  {
		  if (aabb.min.x <   min.x)     min.x=aabb.min.x;
		  if (aabb.min.y <   min.y)     min.y=aabb.min.y;
		  if (aabb.min.z <   min.z)     min.z=aabb.min.z;

		  if (aabb.max.x >   max.x)     max.x=aabb.max.x;
		  if (aabb.max.y >   max.y)     max.y=aabb.max.y;
		  if (aabb.max.z >   max.z)     max.z=aabb.max.z; 

		  return *this;   
	  }

	  //! \brief  Преобразование в сферу. Край сферы по углам бокса.
	  Sphere toSphere() const
	  {
		  Sphere res;
		  res.center =  min.middle(max); 
		  res.radius =  min.distance(max) * 0.5f; 
		  return res;
	  }

	  //! \brief Проверка точки на нахождение в боксе.   ПРОВЕРЕНО!
	  inline bool checkContainPoint(const  vec3& p )
	  {
		  return      (p.x <= this->max.x) && (p.x >= this->min.x)
			  && (p.y <= this->max.y) && (p.y >= this->min.y)
			  && (p.z <= this->max.z) && (p.z >= this->min.z);
	  }	  


	  bool checkIntersectPlane(const plane_s& pl) const;

//bool checkIntersectRay(const Ray& ray) {....}
//bool checkIntersecеSphere(const Sphere& sph) {....}
//bool checkIntersectAABB_ex(Plane& outContactPlane, const AABB& aabb) {....}
	
	
//* времянка. Проверка пересечения боксов.
bool checkIntersectAABB(const AABB& b) const
{
    if( (max.x < b.min.x) || (min.x > b.max.x) ) return false;
    if( (max.y < b.min.y) || (min.y > b.max.y) ) return false;
    if( (max.z < b.min.z) || (min.z > b.max.z) ) return false;
    return true;
}	
	
	
// http://www.devmaster.net/forums/showthread.php?t=10324   #5	
bool checkIntersectAABB_2(AABB& aabb) const
{
    return
        min.x > aabb.max.x || max.x < aabb.min.x ||
        min.y > aabb.max.y || max.y < aabb.min.y ||
        min.z > aabb.max.z || max.z < aabb.min.z;
}


 
 
//function AABBContainsAABB(const mainAABB, testAABB : TAABB) : TSpaceContains;

ObjContainsE checkContainsAabb( const AABB& box ) const
{
  if
   (( min.x<box.max.x) &&
    ( min.y<box.max.y) &&
    ( min.z<box.max.z) &&

    (box.min.x< max.x) &&
    (box.min.y< max.y) &&
    (box.min.z< max.z))  
  {
    if((box.min.x>= min.x) &&
      (box.min.y>= min.y) &&
      (box.min.z>= min.z) &&

      (box.max.x<= max.x) &&
      (box.max.y<= max.y) &&
      (box.max.z<= max.z) ) 
       return SC_CONTAINSFULLY;
    else
	{
      return SC_CONTAINSPARTIALLY;
	}; 
  }
  else
     return  SC_NOOVERLAP;


   return SC_NOOVERLAP;
};

 
ObjContainsE checkContainsSphere( const Sphere& s)  const 
{
    AABB b = s.toAabbOutside();
     return checkContainsAabb(b);
};
	 
	






	};
	// end class
		
	
	
	
	
	
	
	
	
	
	}
}
