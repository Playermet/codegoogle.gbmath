#pragma once

#include "_gbmath.h"
//#include "ObjectColotType_e.h"



 
namespace gbmath
{


			std::string object_color_type_e::tostr(e _enum)
			{
				std::string res;
				switch(_enum)
				{
				case AMBIENT:
					{
					res = "AMBIENT";
					}
					break;

				case DIFFUSE:
					{
					res = "DIFFUSE";
					}
					break;

				case SPECULAR:
					{
					 res = "SPECULAR";
					}
					break;

				case EMISSIVE:
					{
					 res = "EMISSIVE";
					}
					break;


				case LIGHTSOURCECOLOR:
					{
						res = "LIGHTSOURCECOLOR";
					}
					break;


				case LIGHTMAPCOLOR:
					{
						res = "LIGHTMAPCOLOR";
					}
					break;

				default:
					{
					}
				}

				return res;
			}



			bool object_color_type_e::fromstr(e& outval, const std::string& str_arg)
			{
				outval = UNDEFINED;
				std::string s = str_arg;
				for(size_t c=0; c<s.length(); c++)
				{
					s[c] = toupper( s[c] );
				}

				if("AMBIENT" == s)
				{
					outval =  AMBIENT;
					return true;
				}

				if("DIFFUSE" == s)
				{
					outval =  DIFFUSE;
					return true;
				}

				if("SPECULAR" == s)
				{
					outval =  SPECULAR;
					return true;
				}

				if("EMISSIVE" == s)
				{
					outval =  EMISSIVE;
					return true;
				}

				if("LIGHTSOURCECOLOR" == s)
				{
					outval =  LIGHTSOURCECOLOR;
					return true;
				}


				if("LIGHTMAPCOLOR" == s)
				{
					outval =  LIGHTMAPCOLOR;
					return true;
				}
 

			  return false;
			}


	//==============================================


	const color4f*  object_color::getByType(
				const object_color_type_e::e value) const 
	{

		switch(value)
		{
		case   object_color_type_e::AMBIENT: { return &Ambien; } break;
		case   object_color_type_e::DIFFUSE: { return &Diffuse; } break;
		case   object_color_type_e::SPECULAR: { return &Specular; } break;
		case   object_color_type_e::EMISSIVE: { return &Emissive; } break;
		case   object_color_type_e::LIGHTSOURCECOLOR: { return &LightSourceSolor; } break;
		case   object_color_type_e::LIGHTMAPCOLOR:    { return &LightmapColor; } break;
 
 

			default:
				{
					printf("Value: %u\n" , (unsigned int)value );
					printf("not found \n");
				}
		}
 

		assert( false && " bad input value " );
	   return NULL;
	}
 
 
}
