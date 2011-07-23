
#include "fmath.h"


namespace gb
{

namespace fmath
{


//=========================================================================
//  Frustum
//=========================================================================

//=========================================================================
void Frustum::make(const  mat44& mViewProj) 
{
 
	// left plane 
	planes[0].a = mViewProj._14 + mViewProj._13;
	planes[0].b = mViewProj._24 + mViewProj._23;
	planes[0].c = mViewProj._34 + mViewProj._33;
	planes[0].d = mViewProj._44 + mViewProj._43;
	//D3DXPlaneNormalize((D3DXPLANE*)&planes[0], (D3DXPLANE*)&planes[0]);
	planes[0].normalize();


	// right plane
	planes[1].a = mViewProj._14 - mViewProj._13;
	planes[1].b = mViewProj._24 - mViewProj._23;
	planes[1].c = mViewProj._34 - mViewProj._33;
	planes[1].d = mViewProj._44 - mViewProj._43;
	//D3DXPlaneNormalize((D3DXPLANE*)&planes[1], (D3DXPLANE*)&planes[1]);
	planes[1].normalize();


	// top plane
	planes[2].a = mViewProj._14 + mViewProj._11;
	planes[2].b = mViewProj._24 + mViewProj._21;
	planes[2].c = mViewProj._34 + mViewProj._31;
	planes[2].d = mViewProj._44 + mViewProj._41;
	//D3DXPlaneNormalize((D3DXPLANE*)&planes[2], (D3DXPLANE*)&planes[2]);
	planes[2].normalize();


	//Bottom  plane
	planes[3].a = mViewProj._14 - mViewProj._11;
	planes[3].b = mViewProj._24 - mViewProj._21;
	planes[3].c = mViewProj._34 - mViewProj._31;
	planes[3].d = mViewProj._44 - mViewProj._41;
	//D3DXPlaneNormalize((D3DXPLANE*)&planes[3], (D3DXPLANE*)&planes[3]);
    planes[3].normalize();


	// near  plane
	planes[4].a = mViewProj._14 - mViewProj._12;
	planes[4].b = mViewProj._24 - mViewProj._22;
	planes[4].c = mViewProj._34 - mViewProj._32;
	planes[4].d = mViewProj._44 - mViewProj._42;
//	D3DXPlaneNormalize((D3DXPLANE*)&planes[4], (D3DXPLANE*)&planes[4]);
    planes[4].normalize();


	// far  plane
	planes[5].a = mViewProj._14 + mViewProj._12;
	planes[5].b = mViewProj._24 + mViewProj._22;
	planes[5].c = mViewProj._34 + mViewProj._32;
	planes[5].d = mViewProj._44 + mViewProj._42;
	//D3DXPlaneNormalize((D3DXPLANE*)&planes[5], (D3DXPLANE*)&planes[5]);
	planes[5].normalize();

 
};


//=========================================================================
bool Frustum::checkPoint(const  vec3& point) const  
{
	for(int c=0; c<6; c++) 
	{
		if( planes[c].dotCoord(point) < 0.0f )
		//if(D3DXPlaneDotCoord( (D3DXPLANE*)&planes[c], &D3DXVECTOR3(pos->x, pos->y, pos->z)) < 0.0f)
		{
			return true;		
		}

	}
	return false;
};


//=========================================================================
bool Frustum::checkSphere(const Sphere& sphere)  const 
{
	for(int c=0; c<6; c++) 
	{  
		if( planes[c].dotCoord(sphere.center) < -sphere.radius  )
		//if(  D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(sphere->center.x, sphere->center.y, sphere->center.z))  <  -sphere->radius  )
		{
          return true;
		}
 
	}

	return false;
};

//=========================================================================
bool Frustum::checkAABB(const AABB& aabb) const  
{

	for(int c=0; c<6; c++) 
	{
	    if( planes[c].dotCoord(  vec3(aabb.min.x, aabb.min.y, aabb.min.z) ) >= 0.0f )
        //if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.min.x, aabb.min.y, aabb.min.z)) >= 0.0f)
			continue;
					
	      if( planes[c].dotCoord(  vec3(aabb.max.x, aabb.min.y, aabb.min.z) ) >= 0.0f ) 	
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.max.x, aabb.min.y, aabb.min.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.min.x, aabb.max.x, aabb.min.z) ) >= 0.0f ) 			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.min.x, aabb.max.x, aabb.min.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.max.x, aabb.max.x, aabb.min.z) ) >= 0.0f ) 			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.max.x, aabb.max.x, aabb.min.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.min.x, aabb.min.y, aabb.max.z) ) >= 0.0f )			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.min.x, aabb.min.y, aabb.max.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.max.x, aabb.min.y, aabb.max.z) ) >= 0.0f )			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.max.x, aabb.min.y, aabb.max.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.min.x, aabb.max.x, aabb.max.z) ) >= 0.0f )			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.min.x, aabb.max.x, aabb.max.z)) >= 0.0f)
			continue;
			
	      if( planes[c].dotCoord(  vec3(aabb.max.x, aabb.max.x, aabb.max.z) ) >= 0.0f )			
		//if(D3DXPlaneDotCoord((D3DXPLANE*)&planes[c], &D3DXVECTOR3(aabb.max.x, aabb.max.x, aabb.max.z)) >= 0.0f)
			continue;

			
		return true;
		
	} // for

	return false;
};



}
}

