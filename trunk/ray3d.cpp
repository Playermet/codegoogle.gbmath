
#include "_gbmath.h"


namespace gbmath
{




bool  ray3d::checkIntersectSphere(const sphere& sphere) const
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



bool ray3d::checkIntersectSphere_2 (const sphere& sphere, float* result)
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


  const  float b = vect.dot(dir);


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



bool ray3d::checkIntersectSphere_3( const sphere& sph )
{
	const float __infin__  = _INFCODE;
	float res = 0.0f;

	// // в 10й студии нет xmath.h  Временное определение.
	// static const float INF = 1.0f/0.0f;

	// квадрат радиуса
	const float r =  (sph.radius * sph.radius);

	// квадрат расстояния от точки до центра сферы
	float d = 0.0f;
	
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

	if(h > r) // луч не пересекает сферу
	{
		res = __infin__;
		return false;
	}

    res = s+sqrt(r-h)*gbmath::scalar::sign(r-d); // расстояние до пересечения
 
    return  true;
}


bool ray3d::checkIntersectAABB(const aabb& aabb,  float* result)
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


bool ray3d::checkIntersectPlane( const plane_s& plane , float* pfOutResult) const
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

 
float ray3d::distanceToPlane( plane_s& plane )   const
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




}
