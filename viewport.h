/**  \file
 \brief ??????

  \todo  vieport_s  в нём типы заменить на стандартные.


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{



	 //! \brief Вьюпорт  Область вывода  по координате и размерам.
	 struct vieport_s  {

	   unsigned int  x; ///< координата по X (по гризонтали)
	   unsigned int  y; ///< координата по Y (по вертикали)

	   unsigned int  width;  ///< ширина
	   unsigned int  height; ///< высота

#ifdef _D3D9_H_
	   inline void operator =  (const D3DVIEWPORT9& vp)
	   {
		   x = (unsigned int)vp.X;
		   y = (unsigned int)vp.Y;

		   width  = (unsigned int)vp.Width;
		   height = (unsigned int)vp.Height;

	   }

#pragma message("!!! warning 4297 !!"  __FILE__  )

	   inline void fromdevice(IDirect3DDevice9* pdevice) throw(std::runtime_error)
	   {
		   D3DVIEWPORT9 vp;
		   if FAILED( pdevice->GetViewport(&vp) ) throw std::runtime_error("operation failed");
		   *this = vp;
	   }
#endif

	 };


	  //! \brief  Расширеная область вывода с добавлением min и max для Z .
	 class ViewportZ : public vieport_s  {
	  public:

	      float minZ;
	      float maxZ;

#ifdef _D3D9_H_
	   inline ViewportZ (const D3DVIEWPORT9& vp) { *this = vp; }
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

	   //! \brief ПРисвоить координаты, ширину и высоту в  D3DVIEWPORT9    УБРАТЬ !!!!!
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