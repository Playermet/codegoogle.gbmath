/**  \file
 \brief яяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

 
namespace gbmath
{




		/** \brief Сущность описывает направление/нормаль в 3х-мерном пространстве.
		   Уровень выше, чем вектор.  Всегда нормализован.  */
		class Normal3 {
		private:
			float _x;
			float _y;
			float _z;

			inline void __normalize()
			{
#pragma message("ks777: need insert code check zero " __FILE__)
				register float len = sqrt ( _x*_x + _y*_y + _z*_z );
				_x/=len;
				_y/=len;
				_z/=len;
			}

		public:


			//! \brief  По дефолту нормаль смотрит в Z .
			inline Normal3() { _x=0.0f; _y=0.0f; _z=1.0f;  }
			inline Normal3(const Normal3& n) { _x=n._x; _y=n._y; _z=n._z; }
			inline Normal3(float x, float y, float z) { _x=x; _y=y; _z=z; __normalize(); }
			inline Normal3(const  vec3& v) { *this = v;  }


			inline operator  const float*() const  { return &_x; };
			//inline operator        float*()        { return &_x; };

			inline float x() const { return _x; }
			inline float y() const { return _y; }
			inline float z() const { return _z; }

			inline void operator = (const  vec3& vn)	{ _x = vn.x; _y = vn.y; _z = vn.z; __normalize(); }
			inline operator  vec3() const { return  vec3 (_x,_y,_z);  }
			inline operator  const vec3*() const { return (vec3*)&_x; }

			//! \brief  Вычислить угол между нормалями
			inline float angle (const Normal3& n)
			{
				const float fdot = _x*n._x + _y*n._y + _z*n._z;
                return acos(  fdot );
			}

			 //! \brief Установить как направление между точками pntDest и pntSrc .
			Normal3& setDirectionBetweenPoints(const Point3& pntSrc, const Point3& pntDest);

			//! \brief Изменить направление на противоположное
			inline void negate() {_x=-_x; _y=-_y; _z=-_z; }

			//! \brief  Трансформировать нормаль по матрице m
			Normal3& transform(const  mat44& m)
			{
			    vec3 v = *this;
			   v.transformNormal(m);
			   _x = v.x;
			   _y = v.y;
			   _z = v.z;
				return *this;
			}


#ifdef _D3D9_H_
			inline operator D3DVECTOR*() { return (D3DVECTOR*)&_x; }
			inline operator const D3DVECTOR*() const { return (D3DVECTOR*)&_x; }
			inline operator D3DVECTOR() const  { D3DVECTOR r; r.x=_x; r.y=_y; r.z=_z; return r;  }
			inline void operator = (const D3DVECTOR& v) {	_x=v.x; _y=v.y; _z=v.z; __normalize(); }
#endif


#ifdef __D3DX9MATH_H__
			inline operator const D3DXVECTOR3*() const { return (D3DXVECTOR3*)&_x; }

#endif


		};
		// end class




 
}