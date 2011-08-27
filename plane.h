/**  \file
 \brief plane in 3d


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


#pragma message("!! need rename plane_s  "  __FILE__ )
 
namespace gbmath
{


		//! \brief   plane in 3d
		struct plane_s {

			  union
			  {

				   struct { float x , y , z , w ;   };
				   struct { float a , b , c , d ;   };

				   float floats [4];

			  };



			  //---------------------------------------------------------------------
			  //                        ОПЕРАТОРЫ
			  //---------------------------------------------------------------------




			  inline bool operator == ( const plane_s& p ) const
			  {
				  return a == p.a && b == p.b && c == p.c && d == p.d;
			  }

			  inline bool operator != ( const plane_s& p ) const
			  {
				  return a != p.a || b != p.b || c != p.c || d != p.d;
			  }

			  inline plane_s& operator *= ( const float f )
			  {
				  a *= f;  b *= f;  c *= f;  d *= f;   return *this;
			  }

			  inline plane_s& operator /= ( const float f )
			  {
				  const float fi = 1.0f/f;    a*=fi;  b*=fi;  c*=fi;  d*=fi;   return *this;
			  }



			  inline plane_s operator + () const
			  {
				  return *this;
			  }

			  inline plane_s operator - () const
			  {
				  plane_s res;
				  res.a = -a;
				  res.b = -b;
				  res.c = -c;
				  res.d = -d;
				  return res;
			  }

			  inline plane_s operator * ( const float f ) const
			  {
				  plane_s res;
				  res.a = a * f;
				  res.b = b * f;
				  res.c = c * f;
				  res.d = d * f;
				  return  res;
			  }

			  inline plane_s operator / ( const float f ) const
			  {
				  plane_s res;
				  const float fi = 1.0f / f;
				  res.a = a * fi;
				  res.b = b * fi;
				  res.c = c * fi;
				  res.d = d * fi;
				  return  res;
			  }

			  inline friend plane_s operator * (float f, const plane_s& p )
			  {
				  plane_s res;
				  res.a = f * p.a;
				  res.b = f * p.b;
				  res.c = f * p.c;
				  res.d = f * p.d;
				  return res;  // plane_s(f*p.a, f*p.b, f*p.c, f*p.d);
			  }

		   //! \brief  Присваивание из float-массива
		   inline void operator = (const float* pfArray)
		   {
			   a = pfArray[0];
			   b = pfArray[1];
			   c = pfArray[2];
			   d = pfArray[3];
		   }

		   inline operator        float*()       { return &a; };
		   inline operator const  float*() const { return &a; };

	#ifdef __D3DX9MATH_H__
		inline operator       D3DXPLANE*()       { return (D3DXPLANE*)&a; }
		inline operator const D3DXPLANE*() const { return (D3DXPLANE*)&a; }
		inline operator D3DXPLANE () { return D3DXPLANE(a,b,c,d); }
		inline 	void operator = (const D3DXPLANE& p) {a=p.a; b=p.b; c=p.c; d=p.d; }

	#endif

		   inline void make(float _a, float _b, float _c, float _d)
		   {
			   a = _a;
			   b = _b;
			   c = _c;
			   d = _d;
			   normalize();
		   }


			//! \brief Построение плоскости по координате point и нормали normal.
			inline plane_s& make_from_point_normal(const  vec3& point, const  vec3& normal)
			{
				 vec3 nn(normal);  //< возможно принудительную нормализацию надо убрать .
				nn.normalize();
				a=nn.x;
				b=nn.y;
				c=nn.z;
				d= -( nn.dot(point) );    // -( normal.dot(point) );
				return *this;
			};

			//! \brief Построение плоскости по точкам.
			inline plane_s& make_from_points(const  vec3& p1, const  vec3& p2, const  vec3& p3 )
			{
				 vec3 vsub1 = p1 - p2;
				vsub1.normalize();

				 vec3 vsub2 = p1 - p3;
				vsub2.normalize();

				 vec3 nrml = vsub1.cross(vsub2);
				nrml.normalize();

				make_from_point_normal(p1, &nrml);
				return *this;
			}

			//! \brief   Нормализовать плоскость.  ПРОВЕРЕНО!
			inline void normalize()
			{
				register const float fm = sqrt( a*a + b*b + c*c );
				a /= fm;
				b /= fm;
				c /= fm;
				d /= fm;
			}

			// ПРОВЕРЕНО!
			inline float dot(const  vec4& v) const
			{
				return a*v.x + b*v.y + c*v.z + d*v.w ;
			}

			inline float dotCoord  (const  vec3& vCoord) const
			{
				return a*vCoord.x + b*vCoord.y + c*vCoord.z + d*1.0f;
			}

			inline float dotNormal (const  vec3& vNormal) const
			{
				return a*vNormal.x + b*vNormal.y + c*vNormal.z + d*0.0f;
			}

			//! \brief   Масштабировать плоскость. ПРОВЕРЕНО!
			inline void scale(const float s)
			{
				a *= s;
				b *= s;
				c *= s;
				d *= s;
			}


			//! \brief  Вернуть нормаль плоскости.
			inline  vec3  normal() const
			{
				vec3 res;
				res.x = a;
				res.y = b;
				res.z = c;
				return res;
			}

			//! \brief  Инвертировать плоскость
			inline void inverse()
			{
				a *= -a;
				b *= -b;
				c *= -c;
			}

			//! \brief  Получить инвертированую плоскость
			inline plane_s inverted() const
			{
				plane_s res = *this;
				res.inverse();
				return res;
			}

			//! \brief Проверка точки содержится ли она внутри плоскости.
			inline bool checkPointInside(const  vec3& point)
			{
			  if( dotCoord(point) < 0.0f ) return true;
			  return false;
			}

			//! \brief Получить минимальное расстояние от точки pnt до плоскости .
			inline float distance(const  vec3& point)
			{
			   return abs( dotCoord(point) );
			}

			friend std::ostream& operator << (std::ostream& os, const plane_s& p)
			{
				os << p.a << " " << p.b << " " << p.c << " " << p.d ;
				return os;
			}

			operator std::string() const
			{
				std::ostringstream ss;
				ss << a << " " << b << " " << c << " " << d ;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				std::istringstream ss(str);
				ss >> a;
				ss >> b;
				ss >> c;
				ss >> d;
				if( ss.fail() ) throw std::invalid_argument("bad input string");
			}



		};
		
 
}