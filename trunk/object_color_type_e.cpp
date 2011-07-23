/** \file
  \brief enum color on object
*/

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

			  return false;
			}


 
}
