﻿/**  \file
 \brief  ray in 3d space


  \todo Сделать перечечения: луч, сфера, бокс, плоскость,
  \todo   bool checkIntersectRay(const ray3d& ray) {....}
  \todo   bool checkIntersecеSphere(const Sphere& sph) {....}
  \todo  bool checkIntersectAABB(const aabb& aabb) {....}
  \todo  bool checkIntersectPlane(const Plane& aabb) {....}

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{


	//! \brief  ray in 3d space
	class ray3d {
	public:
	    vec3   orig; 
	    vec3   dir; 

	   inline ray3d() {}
	   inline ray3d(const ray3d& r) {orig=r.orig; dir=r.dir; }

		// may need to remove the option bNeedNormalizeDir
		inline ray3d(const  vec3& _orig, const  vec3& _dir, bool bNeedNormalizeDir=true)
		{
		  orig=_orig;
		  dir=_dir;
		  if(bNeedNormalizeDir)
			  dir.normalize();
		}

		//! \brief  Трансформировать луч по матрице m
		inline void transform(const  mat44& m)
		{
		     orig.transform_coord(m);
		     dir.transform_normal(m);
		}



		//>>>>>>>>>>>>>>>       checkIntersectSphere  >>>>>>>>>>>>>>>>>>>>>>>>>>>

		//  http://netlib.narod.ru/library/book0032/ch15_04.htm
		bool  checkIntersectSphere(const sphere& sphere) const
		{
			 vec3 v =  this->orig - sphere.center;

		     float b = 2.0f * this->dir.dot(v);
		     float c =    v.dot(v) - (sphere.radius * sphere.radius);

		     float discriminant = (b * b) - (4.0f * c);

		     if(discriminant < 0.0f)
			 {
		          return false;
			 }

		     discriminant = sqrtf(discriminant);

		     float s0 = (-b + discriminant) / 2.0f;
		     float s1 = (-b - discriminant) / 2.0f;

		     if(s0 >= 0.0f || s1 >= 0.0f)
			 {
		          return true;
			 }

		     return false;
		}


		 /**   \brief
		 http://www.gamecoder.ru/2011/04/3d-3d.html    */
		bool checkIntersectSphere_2 (const sphere& sphere, float* result)
		{
			 vec3 vect = orig - sphere.center ;

		   const float c = vect.length_sq() -  sphere.radius * sphere.radius;
		   float res = 0.0f;

		   if(c < 0.0f)
		   {
			   res = 0.0f;
		     if(result) *result = 0.0f;
		      return true;
		   }


		  const  float b = vect.dot(dir);//    dotProduct(vect, ray.direction);


		   const float d = b*b - c;


		   if (d < 0.0f)
		   {
		      return (false);
		   }


		   float root1 = -b - sqrt(c);
		   float root2 = -b + sqrt(c);


		   if(root1 >= root2)
			   res = root1;
		      if(result) *result = root1;
		   else
			   res =  root2;
		      if(result) *result = root2;

		   return ( res >= 0.0f );
		}


		//! \brief  Aslan.    CHECKED!
		bool checkIntersectSphere_3( const sphere& sph )
		{
			const float __infin__  = _INFCODE;
		  float res = 0.0f;

		 // // в 10й студии нет xmath.h  Временное определение.
		 // static const float INF = 1.0f/0.0f;

		 // квадрат радиуса
		  const float r =  (sph.radius * sph.radius);

		  // квадрат расстояния от точки до центра сферы
		   float d;
		  {
			 //  assert(false);
			  // inline float distance_sq(const vec3& point) const { return vec3(*this-point).lenghtSq ;  }
			//  vec3 vs = sph.center-orig;
		    // d =  vs.length_sq(); //  sph.center.length_sq();//  lenghtSq(p); // norm2(c-p);
			   d = sph.center.distance_sq(orig);
		  }

		  // проекция центра сферы на луч
		  float s =   (sph.center-orig).dot(dir) / dir.length(); //         sprod(c-p,l)/norm(l);

		  if( (d>r) && (s<0) ) // точка снаружи сферы и луч направлен от сферы
		  {

		    res = __infin__; // return INF; // нет пересечения
			 return false;
		  }

		  // квадрат расстояния от прямой до центра сферы по теореме Пифагора
		  float h = d - s*s;

		  if(h>r) // луч не пересекает сферу
		  {
		      res = __infin__;
			return false;
		  }

		  res = s+sqrt(r-h)*gbmath::scalar::sign(r-d); // расстояние до пересечения

		  // inline int Sign(float x) {  return (x>0)-(x<0);  }

		  return  true;
		}



		//
		//>>>>>>>>>>>>>>      checkIntersectAABB        >>>>>>>>>>>>>>>>>>>>>>>>>>>
		//

		//bool checkIntersectAABB( const aabb& aabb) {....}


		// http://www.gamecoder.ru/2011/04/3d-3d.html
		bool checkIntersectAABB(const aabb& aabb,  float* result)
		{
		   // We check if the ray is inside the box.
		   if (   orig.x >= aabb.min.x
		       && orig.x <= aabb.max.x
		       && orig.y >= aabb.min.y
		       && orig.y <= aabb.max.y
		       && orig.z >= aabb.min.z
		       && orig.z <= aabb.max.z)
		   {
		      *result = 0.0f;
		      return true;
		   }


		   float t_near = FLT_MIN;
		   float t_far = FLT_MAX;
		   float t1;
		   float t2;
		   float tmp;



		   if(dir.x != 0.0f)
		   {
		      t1 = (aabb.min.x - orig.x) / dir.x;
		      t2 = (aabb.max.x - orig.x) / dir.x;

		      if(t1 > t2)
		      {
		         tmp = t1;
		         t2 = t1;
		         t2 = tmp;
		      }

		      if(t1 > t_near)
		      {
		         t_near = t1;
		      }

		      if(t2 < t_far)
		      {
		         t_far = t2;
		      }

		      if(t_near > t_far) return false;
		      if(t_far < 0) return false;

		   }




		   if(dir.y != 0.0f)
		   {
		      t1 = (aabb.min.y - orig.y) / dir.y;
		      t2 = (aabb.max.y - orig.y) / dir.y;

		      if(t1 > t2)
		      {
		         tmp = t1;
		         t2 = t1;
		         t2 = tmp;
		      }

		      if(t1 > t_near)
		      {
		         t_near = t1;
		      }

		      if(t2 < t_far)
		      {
		         t_far = t2;
		      }

		      if(t_near > t_far) return false;
		      if(t_far < 0) return false;

		   }

		   if(dir.z != 0.0f)
		   {
		      t1 = (aabb.min.y - orig.y) / dir.y;
		      t2 = (aabb.max.y - orig.y) / dir.y;

		      if(t1 > t2)
		      {
		         tmp = t1;
		         t2 = t1;
		         t2 = tmp;
		      }

		      if(t1 > t_near)
		      {
		         t_near = t1;
		      }

		      if(t2 < t_far)
		      {
		         t_far = t2;
		      }

		      if(t_near >= t_far) return false;
		      if(t_far < 0) return false;
		   }

		   *result = t_near;

		   return (*result < t_far && *result >= 0);
		}



		//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


		//
		//>>>>>>>>>>>>>>>>>  checkIntersectPlane  >>>>>>>>>>>>>>>>>>>>>>>>>
		//

		//bool checkIntersectPlane(vec3& outContactCoord, const Plane& aabb) {....}

		// http://www.gamecoder.ru/2011/04/3d-3d.html

		bool checkIntersectPlane( const plane_s& plane , float* pfOutResult=NULL) const
		{
			const  vec3 plNrml = plane.normal();
		   const float alpha = plNrml.dot(dir); //    dotProduct(plane.normal, dir);

		   float fres = 0.0f;

		   if(alpha != 0.0f)
		   {
			    fres  = //   ( - dotProduct(plane.normal(), orig ) + plane.d )/alpha;
				 ( -  plNrml.dot(orig)  + plane.d ) / alpha;

			   if(pfOutResult)
			   {
		         *pfOutResult = fres ;
			   }

		      return ( fres >= 0.0f );
		   }


		   return false;
		}

		 //--------------------------------------------------------

		// http://www.gamespp.com/algorithms/collisionDetectionTutorial02.html
		// find the distance between a ray and a plane.
		inline float distanceToPlane( plane_s& plane )   const
		{

			const  vec3 vRayOrigin = orig;
			const  vec3 vnRayVector = dir;

			const   vec3& vnPlaneNormal = plane.normal();
			const float planeD = plane.d;



			float cosAlpha = vnRayVector.dot(vnPlaneNormal);

			// parallel to the plane (alpha=90)
			if (cosAlpha==0)
			{
				return -1.0f;
			}


			float  deltaD = planeD -  vRayOrigin.dot(vnPlaneNormal); //  DotProduct(vRayOrigin,vnPlaneNormal);

			return (deltaD/cosAlpha);
}




	};
	// end class



 
}