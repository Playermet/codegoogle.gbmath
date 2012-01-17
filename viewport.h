/**  \file
 \brief Viewport. Output area in the coordinate and size.

  \todo  vieport_s  в нём типы заменить на стандартные.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{
	
		
 
	 //! \brief Viewport. Output area in the coordinate and size.
	 struct vieport_s  {

	   unsigned int  x; ///<   coordinate of the X (horizontal)
	   unsigned int  y; ///<   coordinate of the Y (vertical)

	   unsigned int  width;  ///< viewport width.
	   unsigned int  height; ///< viewport height.

#ifdef _D3D9_H_
	   inline void operator =  (const D3DVIEWPORT9& vp)
	   {
		   x = (unsigned int)vp.X;
		   y = (unsigned int)vp.Y;

		   width  = (unsigned int)vp.Width;
		   height = (unsigned int)vp.Height;

	   }



	   inline void fromdevice(IDirect3DDevice9* pdevice) 
								throw(std::runtime_error)
	   {
		   D3DVIEWPORT9 vp;
		   if FAILED( pdevice->GetViewport(&vp) ) 
			   throw std::runtime_error("operation failed");

		   *this = vp;
	   }
#endif

	 };



	  //! \brief  Expanded output region with the addition of min and max for the Z .
	 class ViewportZ : public vieport_s  {
	  public:

	      float minZ;
	      float maxZ;

#ifdef _D3D9_H_
	   inline ViewportZ (const D3DVIEWPORT9& vp) 
	   { 
		   *this = vp; 
	   }
#endif


	  #ifdef _D3D9_H_
	   inline void operator = (const D3DVIEWPORT9& vp)
	   {
			x = (unsigned int)vp.X;
			y = (unsigned int)vp.Y;

			width  = (unsigned int)vp.Width;
			height = (unsigned int)vp.Height;

			minZ = vp.MinZ;
			maxZ = vp.MaxZ;
	   }

	   inline operator const D3DVIEWPORT9& () const
	   {
			return (D3DVIEWPORT9&)*this;
	   }



	   //! \briefAssign the coordinates, width and height
	   inline void to_d3d9Viewport(D3DVIEWPORT9& vpInOut) const
	   {
			vpInOut.X = (DWORD)x;
			vpInOut.Y = (DWORD)y;

			vpInOut.Width  = (DWORD)width;
			vpInOut.Height = (DWORD)height;

			vpInOut.MinZ = minZ;
			vpInOut.MaxZ = maxZ;
		}
	  #endif  // #ifdef _D3D9_H_


	  };

}
