/** \file
 \brief color functions.
*/

#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 

//#include "color.h"
//#include "color_integer.h"
//#include "color_def.h"


//#include <float.h>
//#include <math.h>
//#include <string>

//#include <assert.h>

//#include "color.h"
//#include "color3.h"
//#include "color4.h"
//#include "color_def.h"

 
namespace gbmath
{


//
//  color macros
//


//!  \brief   Построение цвета по байтам. Альфа первая.  
inline unsigned int make_color_argb( byte_t a, byte_t r, byte_t g, byte_t b )
{
	//#define MAKECOLOR_ARGB(a,r,g,b)
	//(( uicolor32_t)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
	assert( sizeof(int) == 4 && "check platform" );
	int res =  ( (a&0xff)<<24 ) | ( (r&0xff)<<16 ) | ( (g&0xff)<<8 ) |  (b&0xff);
	return res;
}


//!   \brief  Построение цвета по байтам. Альфа последняя  
inline unsigned int make_color_rgba( byte_t r , byte_t g , byte_t b , byte_t a )
{
	//#define MAKECOLOR_RGBA(r,g,b,a)
	// MAKECOLOR_ARGB(a,r,g,b)
	return make_color_argb(a,r,g,b);
}


/*****************************
/ **  \brief   Построение цвета color_rgb24_s  по трём элементам  //  * /
inline color_rgb24_s  make_rgb(byte_t r, byte_t g, byte_t b)
{
//#define MAKECOLOR_RGB(r,g,b)
// (( color_rgb24_s)( (((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)) )
   color_rgb24_s res = ( (r&0xff)<<16 ) | ( (g&0xff)<<8 ) | ( b&0xff ) ;
   return res;
}
 *****************************/


//!  \brief   Построение целочисленого цвета по компонентам float (0.0f ... 1.0f) 
inline unsigned int make_rgba(float r, float g, float b, float a)
{
	assert(sizeof(unsigned int) == 4);
	//#define MAKECOLOR_FLOAT_RGBA(r,g,b,a) \
	// MAKECOLOR_RGBA((uint32_t)((r)*255.f),(uint32_t)((g)*255.f),(uint32_t)((b)*255.f),(uint32_t)((a)*255.f))
	return make_color_rgba(
		(byte_t)(r*255.f),(byte_t) (g*255.f),	(byte_t)(b*255.f),	(byte_t)(a*255.f)
	);
}




#ifdef _D3D9_H_

//----------------------------------------------
//	 D3DCOLOR   the order of bytes:  a r g b
//----------------------------------------------


//! \brief  Convert standard integral color D3DCOLOR .
inline D3DCOLORVALUE make_d3dcolorvalue( D3DCOLOR col )
{
	D3DCOLORVALUE res;

	const float k = 1.0f / 255.0f;

	res.r = k * (float)((col << 8 ) >> 24);
	res.g = k * (float)((col << 16) >> 24);
	res.b = k * (float)((col << 24) >> 24);
	res.a = k * (float)( col >> 24);

	return res;
}

#endif    // _D3D9_H_



//! \brief  exchange of components R и G . 
inline void colorSwapRG(unsigned int& color)
{
	register byte_t n_g = (byte_t)(color >> 16);
	register byte_t n_r = (byte_t)(color >> 8);

	color = (color | 0x00FFFF00) ^ 0x00FFFF00 ;
	color |= ((unsigned int)n_g << 8);
	color |= ((unsigned int)n_r << 16);
}



//! \brief  exchange of components R и B . 
inline void   colorSwapRB(unsigned int& color)
{
	register byte_t n_B = (byte_t)(color >> 16);
	register byte_t n_R = (byte_t)(color );

	color  =  (color | 0x00FF00FF) ^ 0x00FF00FF ;
	color |= (unsigned  int)n_B;
	color |= ((unsigned int)n_R << 16);
}



//! \brief exchange of componentsG и B .  
inline void colorSwapGB(unsigned int&  color)
{
	register byte_t _g  = (byte_t) ( color >> 8 );
	register byte_t _b  = (byte_t) ( color  );

	color = (color | 0x0000FFFF) ^ 0x0000FFFF ;
	color |= ( (unsigned int)_g << 0);
	color |= ( (unsigned int)_b << 8);
}



//! \brief  Converting 4-byte RGBA color order in the order ARGB.
inline  unsigned int   rgba_to_argb(unsigned  int val )
{
	assert( sizeof(unsigned int) == 4 );
	return ( (val>>8) | (val<<24)  );
}



//! \brief	 Converting 4-byte order ARGB color in order RGBA.
inline unsigned int   argb_to_rgba(unsigned  int val )
{
	assert( sizeof(unsigned int) == 4 );
	return ( (val<<8) | (val>>24) );
}




//------------------------------------------------
// Isolation of the color components
//------------------------------------------------


inline byte_t   colorExtractA( unsigned int color )
{
	return (byte_t)(color >> 24);
}

inline byte_t   colorExtractR( unsigned int color )
{
	return (byte_t)(color >> 16);
}

inline byte_t   colorExtractG( unsigned int color )
{
	return (byte_t)(color >> 8);
}

inline byte_t   colorExtractB( unsigned int color )
{
	return (byte_t)color;
}


//-------------------------------------------------
//  Isolation of the color component  as float.
//-------------------------------------------------



inline float   colorExtractAf( unsigned int color )
{
	return ( ( (float)colorExtractA(color) ) / 255.0f );
}


inline float   colorExtractRf( unsigned int color )
{
	return ( ( (float)colorExtractR(color) ) / 255.0f );
}


inline float   colorExtractGf( unsigned int color )
{
	return ( ( (float)colorExtractG(color) ) / 255.0f );
}


inline float   colorExtractBf( unsigned int color )
{
	return ( ( (float)colorExtractB(color) ) / 255.0f );
}


//-------------------------------------------------
// Set the color components
//-------------------------------------------------



inline void   colorSetA( unsigned int & col, byte_t a ) 
{ 
	col |= 0xFF000000; col ^= 0xFF000000; col |=(unsigned int)(a << 24); 
}


inline void   colorSetR( unsigned int & col, byte_t r ) 
{ 
	col |= 0x00FF0000; col ^= 0x00FF0000; col |=(unsigned int)(r << 16); 
}


inline void   colorSetG( unsigned int & col, byte_t g ) 
{ 
	col |= 0x0000FF00; col ^= 0x0000FF00; col |=(unsigned int)(g <<  8); 
}


inline void   colorSetB( unsigned int & col, byte_t b ) 
{ 
	col |= 0x000000FF; col ^= 0x000000FF; col |=(unsigned int)(b);       
}




//-------------------------------------------------
// set the color components    float
//-------------------------------------------------


inline void   colorSetAf( unsigned int& color, float a ) 
{ 
	colorSetA( color, (byte_t)( a * 255.0f ) );  
}

inline void   colorSetRf( unsigned int& color, float r ) 
{ 
	colorSetR( color, (byte_t)( r * 255.0f ) );  
}

inline void   colorSetGf( unsigned int& color, float g ) 
{ 
	colorSetG( color, (byte_t)( g * 255.0f ) );  
}


inline void   colorSetBf( unsigned int& color, float b ) 
{ 
	colorSetB( color, (byte_t)( b * 255.0f ) );  
}





//-------------------------------------------------
//  Exchange of color components.
//-------------------------------------------------

inline void  colorRgb24_SwapRG( color3_24& color )
{
	register byte_t temp;
	temp = color.r;
	color.r=color.g;
	color.g=temp;
}

inline void  colorRgb24_SwapRB( color3_24& color )
{
	register byte_t temp;
	temp = color.r;
	color.r=color.b;
	color.b=temp;
}

inline void  colorRgb24_SwapGB( color3_24& color )
{
	register byte_t temp;
	temp = color.g;
	color.g=color.b;
	color.b=temp;
}


//! \brief Конвертация uicolor32_t в color_rgb24_s.  
inline color3_24   color_rgb_fFrom_uicolor (unsigned int    color)
{
	color3_24 res;
	res.r=(color >> 16);
	res.g=(color>>8);
	res.b=(color);
	return res;
}




}
