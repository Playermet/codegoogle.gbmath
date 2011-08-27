﻿/**  \file
 \brief  Axis Aligned Bounding Box


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


namespace gbmath
{


#pragma message("!!!! rename aabb  "   __FILE__ )


	// many rus info aabox  
	 // http://www.devmaster.net/forums/showthread.php?t=10324

	//! \brief Axis Aligned Bounding Box  by min and max points.
	class aabb {
	public:
	vec3   min; ///< min box point
	vec3   max; ///< max box pointбокса

		//! box corners
		struct corners 
		{
			vec3 points [8];

			inline  vec3& operator [] (unsigned int index)
			{
				assert(index<8 && "invalid index");
				return points[index];
			}

			inline  vec3 operator [] (unsigned int index)   const
			{
				assert(index<8 && "invalid index");
				return points[index];
			}

		};

	inline aabb() 
	{

	}

	inline aabb(const aabb& aabb) 
	{
		min = aabb.min; 
		max = aabb.max; 
	}

	inline aabb(const  vec3& _min, const  vec3& _max) 
	{ 
		min = _min; 
		max = _max; 
	}

	inline void setzero()
	{
		min.setzero();
		max.setzero();
	}

	inline bool operator == (const aabb& aabb) 
	{ 
		return (min == aabb.min) && (max == aabb.max); 
	}


	//! \brief Return combined with boxing
	inline aabb operator + (const aabb& _aabb) const
	{
	#pragma message("!!! NEED CHECK CODE AFTER REFRACT   "  __FILE__ )
		aabb res = *this;
		if (_aabb.min.x < res.min.x)   res.min.x = _aabb.min.x;
		if (_aabb.min.y < res.min.y)   res.min.y = _aabb.min.y;
		if (_aabb.min.z < res.min.z)   res.min.z = _aabb.min.z;

		if (_aabb.max.x > res.max.x)   res.max.x = _aabb.max.x;
		if (_aabb.max.y > res.max.y)   res.max.y = _aabb.max.y;
		if (_aabb.max.z > res.max.z)   res.max.z = _aabb.max.z;
		return res;
	}

	//! \brief Return combined with a point
	inline aabb operator + (const  vec3& pnt) const
	{
		aabb res = *this;
		if(pnt.x < res.min.x) res.min.x = pnt.x;
		if(pnt.y < res.min.y) res.min.y = pnt.y;
		if(pnt.z < res.min.z) res.min.z = pnt.z;

		if(pnt.x > res.max.x) res.max.x = pnt.x;
		if(pnt.y > res.max.y) res.max.y = pnt.y;
		if(pnt.z > res.max.z) res.max.z = pnt.z;
		return res;
	}

	//! \brief  Merge with another box
	inline aabb& operator += (const aabb& _aabb)
	{
		if (_aabb.min.x < min.x)  min.x=_aabb.min.x;
		if (_aabb.min.y < min.y)  min.y=_aabb.min.y;
		if (_aabb.min.z < min.z)  min.z=_aabb.min.z;

		if (_aabb.max.x > max.x)  max.x=_aabb.max.x;
		if (_aabb.max.y > max.y)  max.y=_aabb.max.y;
		if (_aabb.max.z > max.z)  max.z=_aabb.max.z;
		return *this;
	}

	//! \brief Merge point
	inline aabb& operator += (const  vec3& pnt)
	{
		includePoint(pnt);
		return *this;
	}

	//! \brief  Construct by point.  NEED_CHECK!!!
	inline void make(const  vec3& p1, const  vec3& p2)
	{
		min = p1.minimized(p2);
		max = p1.maximized(p2);
	}

	//! \brief  Construct by point.
	inline void make(float p1_x, float p1_y, float p1_z,
					 float p2_x, float p2_y, float p2_z)
	{
		make(  vec3(p1_x , p1_y , p1_z) ,  vec3(p2_x , p2_y , p2_z) );
	}


	//! \brief extract the coordinates of the corners of boxing 
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


	//! \brief get box center coord.
	vec3 center() const
	{
		vec3 res;
		res.x = (max.x + min.x)/2.0f;
		res.y = (max.y + min.y)/2.0f;
		res.z = (max.z + min.z)/2.0f;
		return res;
	}

	//! \brief  Including the coordinates of pnt in boxing
	aabb& includePoint(const  vec3& pnt)
	{
		if (pnt.x < min.x) min.x = pnt.x;
		if (pnt.y < min.y) min.y = pnt.y;
		if (pnt.z < min.z) min.z = pnt.z;

		if (pnt.x > max.x) max.x = pnt.x;
		if (pnt.y > max.y) max.y = pnt.y;
		if (pnt.z > max.z) max.z = pnt.z;
		return *this;
	}

	//! \brief cut coordinate coord within boxing and return the result
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

	//! \brief  get size  X
	inline float size_x() const 
	{ 
		return max.x - min.x; 
	}

	//! \brief  get size  Y
	inline float size_y() const 
	{ 
		return max.y - min.y; 
	}

	//! \brief get size Z
	inline float size_z() const 
	{ 
		return max.z - min.z; 
	}

	//! \brief Get 3d-box size
	inline size3d size() const
	{
		size3d res;
		res.x = size_x();
		res.y = size_y();
		res.z = size_z();
		return res;
	}

	//! \brief get volume
	inline float volume() const 
	{ 
		return size_x() * size_y() * size_z(); 
	}


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



	//! \brief  Transform the matrix m. Get aligned corners.
	aabb& transform(const  mat44& m)
	{
		corners cr;
		extractCorners(cr);

		min.setzero();
		max.setzero();

		for(int c=0; c<8; c++)
		{
			cr[c].transform_coord(m);
			*this += cr[c];
		}

		return *this;
	}



	//! \brief  move.
	inline void offset(const  vec3& v)
	{
		min += v;
		max += v;
	}

	//! \brief Combine with Box
	inline aabb& includeAabb( const aabb& aabb)
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
	sphere toSphere() const
	{
		sphere res;
		res.center =  min.middle(max);
		res.radius =  min.distance(max) * 0.5f;
		return res;
	}

	//! \brief Check points for being in a box.   OK!
	inline bool checkContainPoint(const  vec3& p )
	{
		return      (p.x <= this->max.x) && (p.x >= this->min.x)
		&& (p.y <= this->max.y) && (p.y >= this->min.y)
		&& (p.z <= this->max.z) && (p.z >= this->min.z);
	}

	//!  check Intersect Plane    NEED_CHECK!!!
	bool checkIntersectPlane(const plane_s& pl) const;

	//todo: bool checkIntersectRay(const Ray& ray) {....}
	//todo: bool checkIntersecеSphere(const sphere& sph) {....}
	//todo: bool checkIntersectAABB_ex(Plane& outContactPlane, const aabb& aabb) {....}


	//* TEMP. Check boxes to the touch..
	bool checkIntersectAABB(const aabb& b) const
	{
		if( (max.x < b.min.x) || (min.x > b.max.x) ) return false;
		if( (max.y < b.min.y) || (min.y > b.max.y) ) return false;
		if( (max.z < b.min.z) || (min.z > b.max.z) ) return false;
		return true;
	}


	// http://www.devmaster.net/forums/showthread.php?t=10324   #5

	//   Check boxes to the touch..
	bool checkIntersectAABB_2(aabb& aabb) const
	{
		return
		min.x > aabb.max.x || max.x < aabb.min.x ||
		min.y > aabb.max.y || max.y < aabb.min.y ||
		min.z > aabb.max.z || max.z < aabb.min.z;
	}


 
	//  Check boxes to the touch..  
	obj_contains_e checkContainsAabb( const aabb& box ) const
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
			}
		}
		//else
		return  SC_NOOVERLAP;
	};


	obj_contains_e checkContainsSphere( const sphere& s)  const
	{
		aabb b = s.toAabbOutside();
		return checkContainsAabb(b);
	}



	};
	// end class
 

}
