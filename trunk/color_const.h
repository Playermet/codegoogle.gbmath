/** \file
 \brief  Color constants.
 
 
*/

#pragma once

#ifndef __GBMATH_H__
	#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif
 
 
namespace gbmath
{


//! \brief  color constants
namespace color_const
{




//-------------------------------------------------------------------------
//                   COLOR CONST	 color4f
//-------------------------------------------------------------------------


static const color4f  COLOR4F_WHITE                 = color4f( 1.0f,       1.0f,       1.0f,       1.0f );
static const color4f  COLOR4F_BLACK                 = color4f( 0.0f,       0.0f,       0.0f,       1.0f );
static const color4f  COLOR4F_DIMGRAY               = color4f( 0.329412f,  0.329412f,  0.329412f,  1.0f );
static const color4f  COLOR4F_GRAY                  = color4f( 0.752941f,  0.752941f,  0.752941f,  1.0f );
static const color4f  COLOR4F_LIGHTGRAY             = color4f( 0.658824f,  0.658824f,  0.658824f,  1.0f );
static const color4f  COLOR4F_AQUAMARINE            = color4f( 0.439216f,  0.858824f,  0.576471f,  1.0f );
static const color4f  COLOR4F_BLUEVIOLET            = color4f( 0.62352f,   0.372549f,  0.623529f,  1.0f );
static const color4f  COLOR4F_BROWN                 = color4f( 0.647059f,  0.164706f,  0.164706f,  1.0f );
static const color4f  COLOR4F_CADETBLUE             = color4f( 0.372549f,  0.623529f,  0.623529f,  1.0f );
static const color4f  COLOR4F_CORAL                 = color4f( 1.0f,       0.498039f,  0.0f,       1.0f );
static const color4f  COLOR4F_CORNFLOWERBLUE        = color4f( 0.258824f,  0.258824f,  0.435294f,  1.0f );
static const color4f  COLOR4F_DARKGREEN             = color4f( 0.184314f,  0.309804f,  0.184314f,  1.0f );
static const color4f  COLOR4F_DARKOLIVEGREEN        = color4f( 0.309804f,  0.309804f,  0.184314f,  1.0f );
static const color4f  COLOR4F_DARKORCHID            = color4f( 0.6f,       0.196078f,  0.8f,       1.0f );
static const color4f  COLOR4F_DARKSLATEBLUE         = color4f( 0.419608f,  0.137255f,  0.556863f,  1.0f );
static const color4f  COLOR4F_DARKSLATEGRAY         = color4f( 0.184314f,  0.309804f,  0.309804f,  1.0f );
static const color4f  COLOR4F_DARKSLATEGREY         = color4f( 0.184314f,  0.309804f,  0.309804f,  1.0f );
static const color4f  COLOR4F_DARKTURQUOISE         = color4f( 0.439216f,  0.576471f,  0.858824f,  1.0f );
static const color4f  COLOR4F_FIREBRICK             = color4f( 0.556863f,  0.137255f,  0.137255f,  1.0f );
static const color4f  COLOR4F_FORESTGREEN           = color4f( 0.137255f,  0.556863f,  0.137255f,  1.0f );
static const color4f  COLOR4F_GOLD                  = color4f( 0.8f,       0.498039f,  0.196078f,  1.0f );
static const color4f  COLOR4F_GOLDENROD             = color4f( 0.858824f,  0.858824f,  0.439216f,  1.0f );
static const color4f  COLOR4F_GREENYELLOW           = color4f( 0.576471f,  0.858824f,  0.439216f,  1.0f );
static const color4f  COLOR4F_INDIAN                = color4f( 0.309804f,  0.184314f,  0.184314f,  1.0f );
static const color4f  COLOR4F_KHAKI                 = color4f( 0.623529f,  0.623529f,  0.372549f,  1.0f );
static const color4f  COLOR4F_LIGHTBLUE             = color4f( 0.74902f,   0.847059f,  0.847059f,  1.0f );
static const color4f  COLOR4F_LIGHTSTEELBLUE        = color4f( 0.560784f,  0.560784f,  0.737255f,  1.0f );
static const color4f  COLOR4F_LIMEGREEN             = color4f( 0.196078f,  0.8f,       0.196078f,  1.0f );
static const color4f  COLOR4F_MAROON                = color4f( 0.556863f,  0.137255f,  0.419608f,  1.0f );
static const color4f  COLOR4F_MEDIUMAQUAMARINE      = color4f( 0.196078f,  0.8f,       0.6f,       1.0f );
static const color4f  COLOR4F_MEDIUMBLUE            = color4f( 0.196078f,  0.196078f,  0.8f,       1.0f );
static const color4f  COLOR4F_MEDIUMFORESTGREEN     = color4f( 0.419608f,  0.556863f,  0.137255f,  1.0f );
static const color4f  COLOR4F_MEDIUMGOLDENROD       = color4f( 0.917647f,  0.917647f,  0.678431f,  1.0f );
static const color4f  COLOR4F_MEDIUMORCHID          = color4f( 0.576471f,  0.439216f,  0.858824f,  1.0f );
static const color4f  COLOR4F_MEDIUMSEAGREEN        = color4f( 0.258824f,  0.435294f,  0.258824f,  1.0f );
static const color4f  COLOR4F_MEDIUMSLATEBLUE       = color4f( 0.498039f,  0.0f,       1.0f,       1.0f );
static const color4f  COLOR4F_MEDIUMSPRINGGREEN     = color4f( 0.498039f,  1.0f,       0.0f,       1.0f );
static const color4f  COLOR4F_MEDIUMTURQUOISE       = color4f( 0.439216f,  0.858824f,  0.858824f,  1.0f );
static const color4f  COLOR4F_MEDIUMVIOLET          = color4f( 0.858824f,  0.439216f,  0.576471f,  1.0f );
static const color4f  COLOR4F_MIDNIGHTBLUE          = color4f( 0.184314f,  0.184314f,  0.309804f,  1.0f );
static const color4f  COLOR4F_NAVY                  = color4f( 0.137255f,  0.137255f,  0.556863f,  1.0f );
static const color4f  COLOR4F_NAVYBLUE              = color4f( 0.137255f,  0.137255f,  0.556863f,  1.0f );
static const color4f  COLOR4F_ORANGE                = color4f( 1.0f,       0.5f,       0.0f,       1.0f );
static const color4f  COLOR4F_ORANGERED             = color4f( 1.0f,       0.25f,      0.0f,       1.0f );
static const color4f  COLOR4F_ORCHID                = color4f( 0.858824f,  0.439216f,  0.858824f,  1.0f );
static const color4f  COLOR4F_PALEGREEN             = color4f( 0.560784f,  0.737255f,  0.560784f,  1.0f );
static const color4f  COLOR4F_PINK                  = color4f( 0.737255f,  0.560784f,  0.560784f,  1.0f );
static const color4f  COLOR4F_PLUM                  = color4f( 0.917647f,  0.678431f,  0.917647f,  1.0f );
static const color4f  COLOR4F_ALMON                 = color4f( 0.435294f,  0.258824f,  0.258824f,  1.0f );
static const color4f  COLOR4F_EAGREEN               = color4f( 0.137255f,  0.556863f,  0.419608f,  1.0f );
static const color4f  COLOR4F_IENNA                 = color4f( 0.556863f,  0.419608f,  0.137255f,  1.0f );
static const color4f  COLOR4F_KYBLUE                = color4f( 0.196078f,  0.6f,       0.8f,       1.0f );
static const color4f  COLOR4F_LATEBLUE              = color4f( 0.0f,       0.498039f,  1.0f,       1.0f );
static const color4f  COLOR4F_PRINGGREEN            = color4f( 0.0f,       1.0f,       0.498039f,  1.0f );
static const color4f  COLOR4F_TEELBLUE              = color4f( 0.137255f,  0.419608f,  0.556863f,  1.0f );
static const color4f  COLOR4F_TAN                   = color4f( 0.858824f,  0.576471f,  0.439216f,  1.0f );
static const color4f  COLOR4F_THISTLE               = color4f( 0.847059f,  0.74902f,   0.847059f,  1.0f );
static const color4f  COLOR4F_TURQUOISE             = color4f( 0.678431f,  0.917647f,  0.917647f,  1.0f );
static const color4f  COLOR4F_VIOLET                = color4f( 0.309804f,  0.184314f,  0.309804f,  1.0f );
static const color4f  COLOR4F_VIOLETRED             = color4f( 0.8f,       0.196078f,  0.6f,       1.0f );
static const color4f  COLOR4F_WHEAT                 = color4f( 0.847059f,  0.847059f,  0.74902f,   1.0f );
static const color4f  COLOR4F_YELLOWGREEN           = color4f( 0.6f,       0.8f,       0.196078f,  1.0f );
static const color4f  COLOR4F_UMMERSKY              = color4f( 0.22f,      0.69f,      0.87f,      1.0f );
static const color4f  COLOR4F_RICHBLUE              = color4f( 0.35f,      0.35f,      0.67f,      1.0f );
static const color4f  COLOR4F_BRASS                 = color4f( 0.71f,      0.65f,      0.26f,      1.0f );
static const color4f  COLOR4F_COPPER                = color4f( 0.72f,      0.45f,      0.20f,      1.0f );
static const color4f  COLOR4F_BRONZE                = color4f( 0.55f,      0.47f,      0.14f,      1.0f );
static const color4f  COLOR4F_BRONZE2               = color4f( 0.65f,      0.49f,      0.24f,      1.0f );
static const color4f  COLOR4F_ILVER                 = color4f( 0.90f,      0.91f,      0.98f,      1.0f );
static const color4f  COLOR4F_BRIGHTGOLD            = color4f( 0.85f,      0.85f,      0.10f,      1.0f );
static const color4f  COLOR4F_OLDGOLD               = color4f( 0.81f,      0.71f,      0.23f,      1.0f );
static const color4f  COLOR4F_FELDSPAR              = color4f( 0.82f,      0.57f,      0.46f,      1.0f );
static const color4f  COLOR4F_QUARTZ                = color4f( 0.85f,      0.85f,      0.95f,      1.0f );
static const color4f  COLOR4F_NEONPINK              = color4f( 1.00f,      0.43f,      0.78f,      1.0f );
static const color4f  COLOR4F_DARKPURPLE            = color4f( 0.53f,      0.12f,      0.47f,      1.0f );
static const color4f  COLOR4F_NEONBLUE              = color4f( 0.30f,      0.30f,      1.00f,      1.0f );
static const color4f  COLOR4F_COOLCOPPER            = color4f( 0.85f,      0.53f,      0.10f,      1.0f );
static const color4f  COLOR4F_MANDARINORANGE        = color4f( 0.89f,      0.47f,      0.20f,      1.0f );
static const color4f  COLOR4F_LIGHTWOOD             = color4f( 0.91f,      0.76f,      0.65f,      1.0f );
static const color4f  COLOR4F_MEDIUMWOOD            = color4f( 0.65f,      0.50f,      0.39f,      1.0f );
static const color4f  COLOR4F_DARKWOOD              = color4f( 0.52f,      0.37f,      0.26f,      1.0f );
static const color4f  COLOR4F_PICYPINK              = color4f( 1.00f,      0.11f,      0.68f,      1.0f );
static const color4f  COLOR4F_EMISWEETCHOC          = color4f( 0.42f,      0.26f,      0.15f,      1.0f );
static const color4f  COLOR4F_BAKERSCHOC            = color4f( 0.36f,      0.20f,      0.09f,      1.0f );
static const color4f  COLOR4F_FLESH                 = color4f( 0.96f,      0.80f,      0.69f,      1.0f );
static const color4f  COLOR4F_NEWTAN                = color4f( 0.92f,      0.78f,      0.62f,      1.0f );
static const color4f  COLOR4F_NEWMIDNIGHTBLUE       = color4f( 0.00f,      0.00f,      0.61f,      1.0f );
static const color4f  COLOR4F_VERYDARKBROWN         = color4f( 0.35f,      0.16f,      0.14f,      1.0f );
static const color4f  COLOR4F_DARKBROWN             = color4f( 0.36f,      0.25f,      0.20f,      1.0f );
static const color4f  COLOR4F_DARKTAN               = color4f( 0.59f,      0.41f,      0.31f,      1.0f );
static const color4f  COLOR4F_GREENCOPPER           = color4f( 0.32f,      0.49f,      0.46f,      1.0f );
static const color4f  COLOR4F_DKGREENCOPPER         = color4f( 0.29f,      0.46f,      0.43f,      1.0f );
static const color4f  COLOR4F_DUSTYROSE             = color4f( 0.52f,      0.39f,      0.39f,      1.0f );
static const color4f  COLOR4F_HUNTERSGREEN          = color4f( 0.13f,      0.37f,      0.31f,      1.0f );
static const color4f  COLOR4F_CARLET                = color4f( 0.55f,      0.09f,      0.09f,      1.0f );
static const color4f  COLOR4F_MEDIUMPURPLE          = color4f( 0.73f,      0.16f,      0.96f,      1.0f );
static const color4f  COLOR4F_LIGHTPURPLE           = color4f( 0.87f,      0.58f,      0.98f,      1.0f );
static const color4f  COLOR4F_VERYLIGHTPURPLE       = color4f( 0.94f,      0.81f,      0.99f,      1.0f );
static const color4f  COLOR4F_GREEN                 = color4f( 0.0f,       0.5f,       0.0f,       1.0f );
static const color4f  COLOR4F_OLIVE                 = color4f( 0.5f,       0.5f,       1.0f,       1.0f );
static const color4f  COLOR4F_PURPLE                = color4f( 1.0f,       0.0f,       1.0f,       1.0f );
static const color4f  COLOR4F_TEAL                  = color4f( 0.0f,       0.5f,       0.5f,       1.0f );
static const color4f  COLOR4F_RED                   = color4f( 1.0f,       0.0f,       0.0f,       1.0f );
static const color4f  COLOR4F_LIME                  = color4f( 0.0f,       1.0f,       0.0f,       1.0f );
static const color4f  COLOR4F_YELLOW                = color4f( 1.0f,       1.0f,       0.0f,       1.0f );
static const color4f  COLOR4F_BLUE                  = color4f( 0.0f,       0.0f,       1.0f,       1.0f );
static const color4f  COLOR4F_FUCHSIA               = color4f( 1.0f,       0.0f,       1.0f,       1.0f );
static const color4f  COLOR4F_AQUA                  = color4f( 0.0f,       1.0f,       1.0f,       1.0f );




//-------------------------------------------------------------------------
//                   COLOR CONST	 uicolor32_t
//-------------------------------------------------------------------------

static const     unsigned int      CUICOLOR_ALICEBLUE        = 0xFFF0F8FF;
static const     unsigned int      CUICOLOR_ANTIQUEWHITE     = 0xFFFAEBD7;
static const     unsigned int      CUICOLOR_AQUA             = 0xFF00FFFF;
static const     unsigned int      CUICOLOR_AQUAMARINE       = 0xFF7FFFD4;
static const     unsigned int      CUICOLOR_AZURE            = 0xFFF0FFFF;
static const     unsigned int      CUICOLOR_BEIGE            = 0xFFF5F5DC;
static const     unsigned int      CUICOLOR_BISQUE           = 0xFFFFE4C4;
static const     unsigned int      CUICOLOR_BLACK            = 0xFF000000;
static const     unsigned int      CUICOLOR_BLANCHEDALMOND   = 0xFFFFEBCD;
static const     unsigned int      CUICOLOR_BLUE             = 0xFF0000FF;
static const     unsigned int      CUICOLOR_BLUEVIOLET       = 0xFF8A2BE2;
static const     unsigned int      CUICOLOR_BROWN            = 0xFFA52A2A;
static const     unsigned int      CUICOLOR_BURLYWOOD        = 0xFFDEB887;
static const     unsigned int      CUICOLOR_CADETBLUE        = 0xFF5F9EA0;
static const     unsigned int      CUICOLOR_CHARTREUSE       = 0xFF7FFF00;
static const     unsigned int      CUICOLOR_CHOCOLATE        = 0xFFD2691E;
static const     unsigned int      CUICOLOR_CORAL            = 0xFFFF7F50;
static const     unsigned int      CUICOLOR_CORNFLOWERBLUE   = 0xFF6495ED;
static const     unsigned int      CUICOLOR_CORNSILK         = 0xFFFFF8DC;
static const     unsigned int      CUICOLOR_CRIMSON          = 0xFFDC143C;
static const     unsigned int      CUICOLOR_CYAN             = 0xFF00FFFF;
static const     unsigned int      CUICOLOR_DARKBLUE         = 0xFF00008B;
static const     unsigned int      CUICOLOR_DARKCYAN         = 0xFF008B8B;
static const     unsigned int      CUICOLOR_DARKGOLDENROD    = 0xFFB8860B;
static const     unsigned int      CUICOLOR_DARKGRAY         = 0xFFA9A9A9;
static const     unsigned int      CUICOLOR_DARKGREEN        = 0xFF006400;
static const     unsigned int      CUICOLOR_DARKKHAKI        = 0xFFBDB76B;
static const     unsigned int      CUICOLOR_DARKMAGENTA      = 0xFF8B008B;
static const     unsigned int      CUICOLOR_DARKOLIVEGREEN   = 0xFF556B2F;
static const     unsigned int      CUICOLOR_DARKORANGE       = 0xFFFF8C00;
static const     unsigned int      CUICOLOR_DARKORCHID       = 0xFF9932CC;
static const     unsigned int      CUICOLOR_DARKRED          = 0xFF8B0000;
static const     unsigned int      CUICOLOR_DARKSALMON       = 0xFFE9967A;
static const     unsigned int      CUICOLOR_DARKSEAGREEN     = 0xFF8FBC8B;
static const     unsigned int      CUICOLOR_DARKSLATEBLUE    = 0xFF483D8B;
static const     unsigned int      CUICOLOR_DARKSLATEGRAY    = 0xFF2F4F4F;
static const     unsigned int      CUICOLOR_DARKTURQUOISE    = 0xFF00CED1;
static const     unsigned int      CUICOLOR_DARKVIOLET       = 0xFF9400D3;
static const     unsigned int      CUICOLOR_DEEPPINK         = 0xFFFF1493;
static const     unsigned int      CUICOLOR_DEEPSKYBLUE      = 0xFF00BFFF;
static const     unsigned int      CUICOLOR_DIMGRAY          = 0xFF696969;
static const     unsigned int      CUICOLOR_DODGERBLUE       = 0xFF1E90FF;
static const     unsigned int      CUICOLOR_FIREBRICK        = 0xFFB22222;
static const     unsigned int      CUICOLOR_FLORALWHITE      = 0xFFFFFAF0;
static const     unsigned int      CUICOLOR_FORESTGREEN      = 0xFF228B22;
static const     unsigned int      CUICOLOR_FUCHSIA          = 0xFFFF00FF;
static const     unsigned int      CUICOLOR_GAINSBORO        = 0xFFDCDCDC;
static const     unsigned int      CUICOLOR_GHOSTWHITE       = 0xFFF8F8FF;
static const     unsigned int      CUICOLOR_GOLD             = 0xFFFFD700;
static const     unsigned int      CUICOLOR_GOLDENROD        = 0xFFDAA520;
static const     unsigned int      CUICOLOR_GRAY             = 0xFF808080;
static const     unsigned int      CUICOLOR_GREEN            = 0xFF008000;
static const     unsigned int      CUICOLOR_GREENYELLOW      = 0xFFADFF2F;
static const     unsigned int      CUICOLOR_GROW             = 0xFF808080;
static const     unsigned int      CUICOLOR_HONEYDEW         = 0xFFF0FFF0;
static const     unsigned int      CUICOLOR_HOTPINK          = 0xFFFF69B4;
static const     unsigned int      CUICOLOR_INDIANRED        = 0xFFCD5C5C;
static const     unsigned int      CUICOLOR_INDIGO           = 0xFF4B0082;
static const     unsigned int      CUICOLOR_IVORY            = 0xFFFFFFF0;
static const     unsigned int      CUICOLOR_KHAKI            = 0xFFF0E68C;
static const     unsigned int      CUICOLOR_LAVENDER         = 0xFFE6E6FA;
static const     unsigned int      CUICOLOR_LAVENDERBLUSH    = 0xFFFFF0F5;
static const     unsigned int      CUICOLOR_LAWNGREEN        = 0xFF7CFC00;
static const     unsigned int      CUICOLOR_LEMONCHIFFON     = 0xFFFFFACD;
static const     unsigned int      CUICOLOR_LIGHTBLUE        = 0xFFADD8E6;
static const     unsigned int      CUICOLOR_LIGHTCORAL       = 0xFFF08080;
static const     unsigned int      CUICOLOR_LIGHTCYAN        = 0xFFE0FFFF;
static const     unsigned int      CUICOLOR_LIGHTGOLDENRODYELLOW = 0xFFFAFAD2;
static const     unsigned int      CUICOLOR_LIGHTGRAY        = 0xFFD3D3D3;
static const     unsigned int      CUICOLOR_LIGHTGREEN       = 0xFF90EE90;
static const     unsigned int      CUICOLOR_LIGHTPINK        = 0xFFFFB6C1;
static const     unsigned int      CUICOLOR_LIGHTSALMON      = 0xFFFFA07A;
static const     unsigned int      CUICOLOR_LIGHTSEAGREEN    = 0xFF20B2AA;
static const     unsigned int      CUICOLOR_LIGHTSKYBLUE     = 0xFF87CEFA;
static const     unsigned int      CUICOLOR_LIGHTSLATEGRAY   = 0xFF778899;
static const     unsigned int      CUICOLOR_LIGHTSTEELBLUE   = 0xFFB0C4DE;
static const     unsigned int      CUICOLOR_LIGHTYELLOW      = 0xFFFFFFE0;
static const     unsigned int      CUICOLOR_LIME             = 0xFF00FF00;
static const     unsigned int      CUICOLOR_LIMEGREEN        = 0xFF32CD32;
static const     unsigned int      CUICOLOR_LINEN            = 0xFFFAF0E6;
static const     unsigned int      CUICOLOR_MAGENTA          = 0xFFFF00FF;
static const     unsigned int      CUICOLOR_MAROON           = 0xFF800000;
static const     unsigned int      CUICOLOR_MEDIUMAQUAMARINE     = 0xFF66CDAA;
static const     unsigned int      CUICOLOR_MEDIUMBLUE           = 0xFF0000CD;
static const     unsigned int      CUICOLOR_MEDIUMORCHID         = 0xFFBA55D3;
static const     unsigned int      CUICOLOR_MEDIUMPURPLE         = 0xFF9370DB;
static const     unsigned int      CUICOLOR_MEDIUMSEAGREEN       = 0xFF3CB371;
static const     unsigned int      CUICOLOR_MEDIUMSLATEBLUE      = 0xFF7B68EE;
static const     unsigned int      CUICOLOR_MEDIUMSPRINGGREEN    = 0xFF00FA9A;
static const     unsigned int      CUICOLOR_MEDIUMTURQUOISE      = 0xFF48D1CC;
static const     unsigned int      CUICOLOR_MEDIUMVIOLETRED      = 0xFFC71585;
static const     unsigned int      CUICOLOR_MIDNIGHTBLUE         = 0xFF191970;
static const     unsigned int      CUICOLOR_MINTCREAM        = 0xFFF5FFFA;
static const     unsigned int      CUICOLOR_MISTYROSE        = 0xFFFFE4E1;
static const     unsigned int      CUICOLOR_MOCCASIN         = 0xFFFFE4B5;
static const     unsigned int      CUICOLOR_NAVAJOWHITE      = 0xFFFFDEAD;
static const     unsigned int      CUICOLOR_NAVY             = 0xFF000080;
static const     unsigned int      CUICOLOR_OLDLACE          = 0xFFFDF5E6;
static const     unsigned int      CUICOLOR_OLIVE            = 0xFF808000;
static const     unsigned int      CUICOLOR_OLIVEDRAB        = 0xFF6B8E23;
static const     unsigned int      CUICOLOR_ORANGE           = 0xFFFFA500;
static const     unsigned int      CUICOLOR_ORANGERED        = 0xFFFF4500;
static const     unsigned int      CUICOLOR_ORCHID           = 0xFFDA70D6;
static const     unsigned int      CUICOLOR_PALEGOLDENR      = 0xFFEEE8AA;
static const     unsigned int      CUICOLOR_PALEGREEN        = 0xFF98FB98;
static const     unsigned int      CUICOLOR_PALETURQUOI      = 0xFFAFEEEE;
static const     unsigned int      CUICOLOR_PALEVIOLETR      = 0xFFDB7093;
static const     unsigned int      CUICOLOR_PAPAYAWHIP       = 0xFFFFEFD5;
static const     unsigned int      CUICOLOR_PEACHPUFF        = 0xFFFFDAB9;
static const     unsigned int      CUICOLOR_PERU             = 0xFFCD853F;
static const     unsigned int      CUICOLOR_PINK             = 0xFFFFC0CB;
static const     unsigned int      CUICOLOR_PLUM             = 0xFFDDA0DD;
static const     unsigned int      CUICOLOR_POWDERBLUE       = 0xFFB0E0E6;
static const     unsigned int      CUICOLOR_PURPLE           = 0xFF800080;
static const     unsigned int      CUICOLOR_RED              = 0xFFFF0000;
static const     unsigned int      CUICOLOR_ROSYBROWN        = 0xFFBC8F8F;
static const     unsigned int      CUICOLOR_ROYALBLUE        = 0xFF4169E1;
static const     unsigned int      CUICOLOR_SADDLEBROWN      = 0xFF8B4513;
static const     unsigned int      CUICOLOR_SALMON           = 0xFFFA8072;
static const     unsigned int      CUICOLOR_SANDYBROWN       = 0xFFF4A460;
static const     unsigned int      CUICOLOR_SEAGREEN         = 0xFF2E8B57;
static const     unsigned int      CUICOLOR_SEASHELL         = 0xFFFFF5EE;
static const     unsigned int      CUICOLOR_SIENNA           = 0xFFA0522D;
static const     unsigned int      CUICOLOR_SILVER           = 0xFFC0C0C0;
static const     unsigned int      CUICOLOR_SKYBLUE          = 0xFF87CEEB;
static const     unsigned int      CUICOLOR_SLATEBLUE        = 0xFF6A5ACD;
static const     unsigned int      CUICOLOR_SLATEGRAY        = 0xFF708090;
static const     unsigned int      CUICOLOR_SNOW             = 0xFFFFFAFA;
static const     unsigned int      CUICOLOR_SPRINGGREEN      = 0xFF00FF7F;
static const     unsigned int      CUICOLOR_STEELBLUE        = 0xFF4682B4;
static const     unsigned int      CUICOLOR_TAN              = 0xFFD2B48C;
static const     unsigned int      CUICOLOR_TEAL             = 0xFF008080;
static const     unsigned int      CUICOLOR_THISTLE          = 0xFFD8BFD8;
static const     unsigned int      CUICOLOR_TOMATO           = 0xFFFF6347;
static const     unsigned int      CUICOLOR_TRANSPARENT      = 0x00FFFFFF;
static const     unsigned int      CUICOLOR_TURQUOISE        = 0xFF40E0D0;
static const     unsigned int      CUICOLOR_VIOLET           = 0xFFEE82EE;
static const     unsigned int      CUICOLOR_WHEAT            = 0xFFF5DEB3;
static const     unsigned int      CUICOLOR_WHITE            = 0xFFFFFFFF;
static const     unsigned int      CUICOLOR_WHITESMOKE       = 0xFFF5F5F5;
static const     unsigned int      CUICOLOR_YELLOW           = 0xFFFFFF00;
static const     unsigned int      CUICOLOR_YELLOWGREEN      = 0xFF9ACD32;



}
   
}
