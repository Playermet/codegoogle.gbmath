﻿/**  \file
 \brief яяяяяяяяяяяя


*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



namespace gbmath
{





		//! \brief Матрица 4x4.
		struct mat44
		{
			union
			{
				struct
				{

				   float _11,  _12,  _13,  _14,
				         _21,  _22,  _23,  _24,
				         _31,  _32,  _33,  _34,
						 _41,  _42,  _43,  _44;
				};

				   float floats [4][4];

				   float array[16];
			};


			inline mat44() {}

			//! \brief Сбросить в идентичную и заполнить главную диагональ значением a (обычно 1.0f)
			inline mat44(float a)
			{
			   setIdentity();
			   _11=a;
			   _22=a;
			   _33=a;
			   _44=a;
			}

			inline mat44(const mat44& m) { *this = m; }

			inline mat44( float _11_, float _12_, float _13_, float _14_,
	                      float _21_, float _22_, float _23_, float _24_,
	                      float _31_, float _32_, float _33_, float _34_,
	                      float _41_, float _42_, float _43_, float _44_ ) :
				_11( _11_ ), _12( _12_ ), _13( _13_ ), _14( _14_ ),
				_21( _21_ ), _22( _22_ ), _23( _23_ ), _24( _24_ ),
				_31( _31_ ), _32( _32_ ), _33( _33_ ), _34( _34_ ),
				_41( _41_ ), _42( _42_ ), _43( _43_ ), _44( _44_ )  {}

			inline mat44(const float* pfArray)
			{
				*this = pfArray;
			}


			inline operator  const float*() const  { return &_11; }
			inline operator        float*()        { return &_11; }

#ifdef _D3D9_H_

			inline operator D3DMATRIX*()   { return (D3DMATRIX*)&_11; }
			inline operator const D3DMATRIX*() const  { return (D3DMATRIX*)&_11; }
			inline operator const D3DMATRIX() const
			{
			   D3DMATRIX res;
			   for(int c=0;c<4; c++)
			   {
			     for(int j=0; j<4; j++)
				 {
				  res.m[c][j] = floats[c][j];
				 }
			   }
			   return res;
			}


			inline void operator = (const D3DMATRIX& m)
			{
				_11 = m._11;
				_12 = m._12;
				_13 = m._13;
				_14 = m._14;

				_21 = m._21;
				_22 = m._22;
				_23 = m._23;
				_24 = m._24;

				_31 = m._31;
				_32 = m._32;
				_33 = m._33;
				_34 = m._34;

				_41 = m._41;
				_42 = m._42;
				_43 = m._43;
				_44 = m._44;
			}

#endif //  #ifdef _D3D9_H_



#ifdef __D3DX9MATH_H__
			inline operator D3DXMATRIX*()   { return (D3DXMATRIX*)&_11; }
			inline operator const D3DXMATRIX*() const  { return (D3DXMATRIX*)&_11; }
			inline operator const D3DXMATRIX() const
			{
			   D3DXMATRIX res;
			   for(int c=0;c<4; c++)
			   {
			     for(int j=0; j<4; j++)
				 {
				  res.m[c][j] = floats[c][j];
				 }
			   }
			   return res;
			}

			inline void operator = (const D3DXMATRIX& m)
			{
			   for(int c=0;c<4; c++)
			   {
			     for(int j=0; j<4; j++)
				 {
				  floats[c][j] = m.m [c][j];
				 }
			   }

			}


#endif // __D3DX9MATH_H__


			inline void operator  = (const float* pfArray)
			{
				_11 = pfArray[ 0];
				_12 = pfArray[ 1];
				_13 = pfArray[ 2];
				_14 = pfArray[ 3];

				_21 = pfArray[ 4];
				_22 = pfArray[ 5];
				_23 = pfArray[ 6];
				_24 = pfArray[ 7];

				_31 = pfArray[ 8];
				_32 = pfArray[ 9];
				_33 = pfArray[10];
				_34 = pfArray[11];

				_41 = pfArray[12];
				_42 = pfArray[13];
				_43 = pfArray[14];
				_44 = pfArray[15];

			}



			/**    \brief Строгое сравнение    */
			inline bool operator == ( const mat44& m ) const
			{
			 return ( ( _11 == m._11) &&
					  ( _12 == m._12) &&
					  ( _13 == m._13) &&
					  ( _14 == m._14) &&

					  ( _21 == m._21) &&
					  ( _22 == m._22) &&
					  ( _23 == m._23) &&
					  ( _24 == m._24) &&

					  ( _31 == m._31) &&
					  ( _32 == m._32) &&
					  ( _33 == m._33) &&
					  ( _34 == m._34) &&

					  ( _41 == m._41) &&
					  ( _42 == m._42) &&
					  ( _43 == m._43) &&
					  ( _44 == m._44) );
			}





			/**     \brief Строгое сравнение с отрицанием     */
			inline bool operator != ( const mat44& m ) const
			{
		      return ( ( _11 != m._11) ||
				       ( _12 != m._12) ||
					   ( _13 != m._13) ||
					   ( _14 != m._14) ||

					   ( _21 != m._21) ||
					   ( _22 != m._22) ||
					   ( _23 != m._23) ||
					   ( _24 != m._24) ||

					   ( _31 != m._31) ||
					   ( _32 != m._32) ||
					   ( _33 != m._33) ||
					   ( _34 != m._34) ||

					   ( _41 != m._41) ||
					   ( _42 != m._42) ||
					   ( _43 != m._43) ||
					   ( _44 != m._44) );
			};




			/**   \brief Инверсия знака компонентов  */
			inline mat44 operator - () const
			{
				mat44 r;

				r._11 = -_11 ;
				r._12 = -_12 ;
				r._13 = -_13 ;
				r._14 = -_14 ;

				r._21 = -_21 ;
				r._22 = -_22 ;
				r._23 = -_23 ;
				r._24 = -_24 ;

				r._31 = -_31 ;
				r._32 = -_32 ;
				r._33 = -_33 ;
				r._34 = -_34 ;

				r._41 = -_41 ;
				r._42 = -_42 ;
				r._43 = -_43 ;
				r._44 = -_44 ;

				return r;
			}



			/**   \brief Поэлементное сложение матриц  */
			inline mat44 operator + ( const mat44& m ) const
			{
				mat44 r;

				r._11 = _11 + m._11;
				r._12 = _12 + m._12;
				r._13 = _13 + m._13;
				r._14 = _14 + m._14;

				r._21 = _21 + m._21;
				r._22 = _22 + m._22;
				r._23 = _23 + m._23;
				r._24 = _24 + m._24;

				r._31 = _31 + m._31;
				r._32 = _32 + m._32;
				r._33 = _33 + m._33;
				r._34 = _34 + m._34;

				r._41 = _41 + m._41;
				r._42 = _42 + m._42;
				r._43 = _43 + m._43;
				r._44 = _44 + m._44;

				return r;
			}

			/**   \brief Поэлементное вычитание матриц  */
			inline mat44 operator - ( const mat44& m ) const
			{
				mat44 r;

				r._11 = _11 -  m._11;
				r._12 = _12 -  m._12;
				r._13 = _13 -  m._13;
				r._14 = _14 -  m._14;

				r._21 = _21 -  m._21;
				r._22 = _22 -  m._22;
				r._23 = _23 -  m._23;
				r._24 = _24 -  m._24;

				r._31 = _31 -  m._31;
				r._32 = _32 -  m._32;
				r._33 = _33 -  m._33;
				r._34 = _34 -  m._34;

				r._41 = _41 -  m._41;
				r._42 = _42 -  m._42;
				r._43 = _43 -  m._43;
				r._44 = _44 -  m._44;

				return r;
			}


			/**   \brief Умножение всех элементов матрицы на скаляр   */
			inline mat44 operator * (  float f ) const
			{
				mat44 r;

				r._11 = _11 * f;
				r._12 = _12 * f;
				r._13 = _13 * f;
				r._14 = _14 * f;

				r._21 = _21 * f;
				r._22 = _22 * f;
				r._23 = _23 * f;
				r._24 = _24 * f;

				r._31 = _31 * f;
				r._32 = _32 * f;
				r._33 = _33 * f;
				r._34 = _34 * f;

				r._41 = _41 * f;
				r._42 = _42 * f;
				r._43 = _43 * f;
				r._44 = _44 * f;

				return r;
			}



			/**  \brief Деление всех элементов матрицы на скаляр  */
			inline mat44 operator / ( float f ) const
			{
				mat44 r;

				r._11 = _11 / f;
				r._12 = _12 / f;
				r._13 = _13 / f;
				r._14 = _14 / f;

				r._21 = _21 / f;
				r._22 = _22 / f;
				r._23 = _23 / f;
				r._24 = _24 / f;

				r._31 = _31 / f;
				r._32 = _32 / f;
				r._33 = _33 / f;
				r._34 = _34 / f;

				r._41 = _41 / f;
				r._42 = _42 / f;
				r._43 = _43 / f;
				r._44 = _44 / f;

				return r;
			}


			inline mat44&     operator += (const mat44& m) { mat44 t=*this + m; *this=t; return *this;  }
			inline mat44&     operator -= (const mat44& m) { mat44 t=*this - m; *this=t; return *this;  }
			inline mat44&     operator *= (float f)          { mat44 t=*this * f; *this=t; return *this;  }
			inline mat44&     operator /= (float f)          { mat44 t=*this / f; *this=t; return *this;  }



			inline mat44&  operator *= ( const mat44& m )
			{
				mat44 t;
				t = *this * m;
				*this = t;
				return *this;
			}


			// ПРОВЕРЕНО !
			inline mat44 operator * ( const mat44& m ) const
			{
				mat44 r;

			 r._11 = floats[0][0] * m.floats[0][0] + floats[0][1] * m.floats[1][0] + floats[0][2] * m.floats[2][0] + floats[0][3] * m.floats[3][0];
			 r._12 = floats[0][0] * m.floats[0][1] + floats[0][1] * m.floats[1][1] + floats[0][2] * m.floats[2][1] + floats[0][3] * m.floats[3][1];
			 r._13 = floats[0][0] * m.floats[0][2] + floats[0][1] * m.floats[1][2] + floats[0][2] * m.floats[2][2] + floats[0][3] * m.floats[3][2];
			 r._14 = floats[0][0] * m.floats[0][3] + floats[0][1] * m.floats[1][3] + floats[0][2] * m.floats[2][3] + floats[0][3] * m.floats[3][3];

			 r._21 = floats[1][0] * m.floats[0][0] + floats[1][1] * m.floats[1][0] + floats[1][2] * m.floats[2][0] + floats[1][3] * m.floats[3][0];
			 r._22 = floats[1][0] * m.floats[0][1] + floats[1][1] * m.floats[1][1] + floats[1][2] * m.floats[2][1] + floats[1][3] * m.floats[3][1];
			 r._23 = floats[1][0] * m.floats[0][2] + floats[1][1] * m.floats[1][2] + floats[1][2] * m.floats[2][2] + floats[1][3] * m.floats[3][2];
			 r._24 = floats[1][0] * m.floats[0][3] + floats[1][1] * m.floats[1][3] + floats[1][2] * m.floats[2][3] + floats[1][3] * m.floats[3][3];

			 r._31 = floats[2][0] * m.floats[0][0] + floats[2][1] * m.floats[1][0] + floats[2][2] * m.floats[2][0] + floats[2][3] * m.floats[3][0];
			 r._32 = floats[2][0] * m.floats[0][1] + floats[2][1] * m.floats[1][1] + floats[2][2] * m.floats[2][1] + floats[2][3] * m.floats[3][1];
			 r._33 = floats[2][0] * m.floats[0][2] + floats[2][1] * m.floats[1][2] + floats[2][2] * m.floats[2][2] + floats[2][3] * m.floats[3][2];
			 r._34 = floats[2][0] * m.floats[0][3] + floats[2][1] * m.floats[1][3] + floats[2][2] * m.floats[2][3] + floats[2][3] * m.floats[3][3];

			 r._41 = floats[3][0] * m.floats[0][0] + floats[3][1] * m.floats[1][0] + floats[3][2] * m.floats[2][0] + floats[3][3] * m.floats[3][0];
			 r._42 = floats[3][0] * m.floats[0][1] + floats[3][1] * m.floats[1][1] + floats[3][2] * m.floats[2][1] + floats[3][3] * m.floats[3][1];
			 r._43 = floats[3][0] * m.floats[0][2] + floats[3][1] * m.floats[1][2] + floats[3][2] * m.floats[2][2] + floats[3][3] * m.floats[3][2];
			 r._44 = floats[3][0] * m.floats[0][3] + floats[3][1] * m.floats[1][3] + floats[3][2] * m.floats[2][3] + floats[3][3] * m.floats[3][3];

				return  r;
			}


			/**    \brief Умножение вектора на матрицу .  ПРОВЕРЕНО!  */
			inline vec4 operator * ( const vec4& v ) const
			{
				vec4 r;
				r.x =  _11 * v.x +  _21 * v.y +  _31 * v.z +  _41 * v.w;
				r.y =  _12 * v.x +  _22 * v.y +  _32 * v.z +  _42 * v.w;
				r.z =  _13 * v.x +  _23 * v.y +  _33 * v.z +  _43 * v.w;
				r.w =  _14 * v.x +  _24 * v.y +  _34 * v.z +  _44 * v.w;
				  return r;
			}

			bool empty() const
			{
		      static const mat44 _ZERO(0.0f);
			  if( memcmp( &_ZERO._11 , &_11 , sizeof(mat44) ) == 0 )
				      return true;
			  return false;
			}

			//! \brief Зануление всех элементов.
			inline void       setzero() { memset(&_11, 0, sizeof(mat44)  ); }

			//! \brief Установить в идентичную
			inline mat44&   setIdentity()
			{
				_11=1.0f; _12=0.0f; _13=0.0f; _14=0.0f;
				_21=0.0f; _22=1.0f; _23=0.0f; _24=0.0f;
				_31=0.0f; _32=0.0f; _33=1.0f; _34=0.0f;
				_41=0.0f; _42=0.0f; _43=0.0f; _44=1.0f;
				 return *this;
	        }

			inline bool isIdentity() const
			{
			 return floats[0][0] == 1.0f && floats[0][1] == 0.0f && floats[0][2] == 0.0f && floats[0][3] == 0.0f &&
					floats[1][0] == 0.0f && floats[1][1] == 1.0f && floats[1][2] == 0.0f && floats[1][3] == 0.0f &&
					floats[2][0] == 0.0f && floats[2][1] == 0.0f && floats[2][2] == 1.0f && floats[2][3] == 0.0f &&
					floats[3][0] == 0.0f && floats[3][1] == 0.0f && floats[3][2] == 0.0f && floats[3][3] == 1.0f;
			}

			//! \brief Установить в идентичную
			inline mat44& reset() { setIdentity(); return *this; }

			//! \brief Транспонирование. (Отражение элементов по главной диагонали)  ПРОВЕРЕНА!
			inline mat44& transpone()
			{
				   register float f;
				f = _12;  _12 = _21;  _21 = f;
				f = _13;  _13 = _31;  _31 = f;
				f = _14;  _14 = _41;  _41 = f;
				f = _23;  _23 = _32;  _32 = f;
				f = _24;  _24 = _42;  _42 = f;
				f = _34;  _34 = _43;  _43 = f;
				  return *this;
			}

			//!  религиозно-синтаксическое   Вычислить и вернуть транспонированое значение .
			mat44 transponed() const
			{
				mat44 res = *this;
				res.transpone();
				return res;
			}

			/** \brief Вычислить и вернуть транспонированое значение .  */
			inline mat44 getTransponed() const { mat44 r=*this; r.transpone(); return r; };

			/** \brief Вычислить и вернуть определитель.  */
			inline float determinant()  const
			{
				 return
					( _11 *  _22 -  _12 *  _21) * ( _33 *  _44 -  _34 *  _43) -
					( _11 *  _23 -  _13 *  _21) * ( _32 *  _44 -  _34 *  _42) +
					( _11 *  _24 -  _14 *  _21) * ( _32 *  _43 -  _33 *  _42) +
					( _12 *  _23 -  _13 *  _22) * ( _31 *  _44 -  _34 *  _41) -
					( _12 *  _24 -  _14 *  _22) * ( _31 *  _43 -  _33 *  _41) +
					( _13 *  _24 -  _14 *  _23) * ( _31 *  _42 -  _32 *  _41);
			};

			/** \brief Инверсия. Бросает исключение если инверсия невозможна. ПРОВЕРЕНА. */
			mat44&  invert () throw();

			//! \brief Вернуть инвертированую
			mat44 inverted() const throw()
			{
			  mat44 res = *this;
			  res.invert();
			  return res;
			}


			vec4 getRow(unsigned int index) const
			{
				assert(index<4  && "invalid index" );
				return vec4( floats[index][0], floats[index][1], floats[index][2], floats[index][3] );
			}

			vec4 setRow(unsigned int index, const vec4& row)
			{
				assert(index<4  && "invalid index" );
				floats[index][0]=row.x; floats[index][1]=row.y; floats[index][2]=row.z; floats[index][3]=row.w;
			}

			vec4 getColumn(unsigned int index) const
			{
				assert( index<4 && "invalid index" );
				return vec4( floats[0][index], floats[1][index], floats[2][index], floats[3][index] );
			}

			void setColumn(unsigned int index, const vec4& col)
			{
				assert( index<4 && "invalid index" );
			    floats[0][index]=col.x; floats[1][index]=col.y; floats[2][index]=col.z; floats[3][index]=col.w;
			}

			//! \brief   Изволечь данные трансляции.
			inline vec3 getTranslation() const
			{
				return vec3(floats[3][0], floats[3][1], floats[3][2]);
			}

			//-------------------------------------------------------------

			//! \brief  Раскидать матрицу на данные трансформации. ПРОВЕРЕНО!
			void decompose( vec3& scale,  Quaternion& rot, vec3& pos ) const;

			//-------------------------------------------------------------

			//! \brief Построение матрицы отражения по оси X
			inline mat44& setMirrorX ()
			{
				setIdentity();
				floats  [0][0] = -1.0f;
				return *this;
			}

			//! \brief Построение матрицы отражения по оси Y
			inline mat44& setMirrorY ()
			{
				setIdentity();
				floats  [1][1] = -1.0f;
				return *this;
			}

			//! \brief Построение матрицы отражения по оси Z
			inline mat44& setMirrorZ ()
			{
				setIdentity();
				floats [2][2] = -1.0f;
				return *this;
			}

		    //! \brief Построение матрицы отражения по плоскости plane.   ПРОВЕРЕНА!
			mat44& setReflection(const plane_s& plane );


			//! \brief  Построение теневой матрицы.  Рендеринг теней.   ПРОВЕРЕНА!
			mat44&  setShadow(const vec4& Light, const plane_s&Plane );

			//! \brief Построение матрицы поворота по оси X на угол angle . ПРОВЕРЕНА!
			inline mat44&  setRotationX( const float angle )
			{
				setIdentity();
				float sina, cosa;
				scalar::sincos(angle, sina, cosa);
				_22 =  cosa;
				_23 =  sina;
				_32 = -sina;
				_33 =  cosa;
                  return *this;
			}

			//! \brief Построение матрицы поворота по оси Y на угол angle . ПРОВЕРЕНО!
			inline mat44&  setRotationY( const float angle )
			{
				setIdentity();
				float sina, cosa;
				scalar::sincos(angle, sina, cosa);
				_11 =  cosa;
				_13 = -sina;
				_31 =  sina;
				_33 =  cosa;
				return *this;
			};

			//! \brief Построение матрицы поворота по оси Z на угол angle . ПРОВЕРЕНО!
			inline mat44&  setRotationZ( const float angle )
			{
				setIdentity();
				float sina, cosa;
				scalar::sincos(angle, sina, cosa);
				_11 =  cosa;
				_12 =  sina;
				_21 = -sina;
				_22 =  cosa;
				return *this;
			};


			//! \brief Построение матрицы поворота по оси vAx на угол angle . ПРОВЕРЕНО!
			inline mat44&  setRotationAxis( const vec3& vAx,  const float angle )
			{
				float sina, cosa, mcosa;
				scalar::sincos( angle , sina, cosa );
				mcosa = 1.0f - cosa;

				vec3 ax = vAx;
				ax.normalize();

				_11 =(mcosa * ax.x * ax.x) + cosa;
				_12 =(mcosa * ax.x * ax.y) - (ax.z * sina);
				_13 =(mcosa * ax.z * ax.x) + (ax.y * sina);
				_14 = 0.0f;

				_21 =(mcosa * ax.x * ax.y) + (ax.z * sina);
				_22 =(mcosa * ax.y * ax.y) + cosa;
				_23 =(mcosa * ax.y * ax.z) - (ax.x * sina);
				_24 = 0.0f;

				_31 =(mcosa * ax.z * ax.x) - (ax.y * sina);
				_32 =(mcosa * ax.y * ax.z) + (ax.x * sina);
				_33 =(mcosa * ax.z * ax.z) + cosa;
				_34 = 0.0f;

				_41 = 0.0f;
				_42 = 0.0f;
				_43 = 0.0f;
				_44 = 1.0f;

				transpone(); // need

				return *this;
			};


			//! \brief Построение матрицы поворота по оси по компонентам(axX,axY,axZ) на угол angle  . ПРОВЕРЕНО!
			inline mat44&  setRotationAxis( float axX, float axY, float axZ, float angle )
			{
				vec3 vax;
				vax.x = axX; vax.y = axY; vax.z = axZ;
				vax.normalize();
				return setRotationAxis(  vax, angle);
			};

			//! \brief  Построение матрицы поворота по углам Элера (Yaw-Y, Pitch-X, Roll-Z). ПРОВЕРЕНО!
			mat44& setRotationYawPitchRoll(float Yaw, float Pitch, float Roll)
			{
				mat44 mrYaw, mrPitch, mrRoll;

				mrYaw.setRotationY(  Yaw );
				mrPitch.setRotationX(  Pitch );
				mrRoll.setRotationZ( Roll );

				*this =  mrRoll * mrPitch * mrYaw;
				return *this;
			};

			//! \brief Построить матрицу поворота по кватерниону.  ПРОВЕРЕНО!
			mat44& setRotationQuaternion(const  Quaternion& q) ;



			//! \brief Построение матрицы сдвига (позиции)  . ПРОВЕРЕНО!
			inline mat44&  setTranslation( float x, float y, float z )
			{
				setIdentity();
				_41 = x;   _42 = y;  _43 = z;
				return *this;
			};

			//! \brief Построение матрицы сдвига (позиции)  ПРОВЕРЕНО!
			inline mat44&  setTranslation( const vec3& vTransl)
			{
				return  setTranslation(  vTransl.x, vTransl.y, vTransl.z);
			}

			//! \brief Построение матрицы масштабирования ПРОВЕРЕНО!
			inline mat44&  setScaling( float x, float y, float z)
			{
				_11 = x;   _12=0.0f;   _13=0.0f;   _14=0.0f;
				_21=0.0f;  _22 = y;    _23=0.0f;   _24=0.0f;
				_31=0.0f;  _32=0.0f;   _33 = z;    _34=0.0f;
				_41=0.0f;  _42=0.0f;   _43=0.0f;   _44 = 1.0f;
				return *this;
			}

			//! \brief Построение матрицы масштабирования	 ПРОВЕРЕНО!
			inline mat44&  setScaling( const vec3& vScaling)
			{
			  return setScaling( vScaling.x, vScaling.y, vScaling.z );
			}


			//! \brief Построить как матрицу трансформации
			mat44& setTransformation(const vec3& vScale,
								            const  Quaternion& qRotation,
								            const vec3& vTranslation);

			//! \brief Построить как матрицу трансформации
			mat44& setWorldTransform(const TransformData& t);


			//! \brief Построение ортографической левосторонней проекционной матрицы. ПРОВЕРЕНА.
			inline void setOrthoLH(float w, float h, float zn, float zf)
			{
				_11=2.0f/w;    _12=0.0f;       _13=0.0f;           _14=0.0f;
				_21=0.0f;      _22=2.0f/h;     _23=0.0f;           _24=0.0f;
				_31=0.0f;      _32=0.0f;       _33=1.0f/(zf-zn);   _34=0.0f;
				_41=0.0f;      _42=0.0f;       _43= -zn/(zf-zn);   _44=1.0f;

				// 2/w  0    0           0
				// 0    2/h  0           0
				// 0    0    1/(zf-zn)   0
				// 0    0   -zn/(zf-zn)  1
			}

			//! \brief Построение ортографической правосторонней проекционной матрицы. ПРОВЕРЕНА.
			inline void setOrthoRH(float w, float h, float zn, float zf)
			{
				_11=2.0f/w;     _12=0.0f;    _13=0.0f;          _14=0.0f;
				_21=0.0f;       _22=2.0f/h;  _23=0.0f;          _24=0.0f;
				_31=0.0f;       _32=0.0f;    _33=1.0f/(zn-zf);  _34=0.0f;
				_41=0.0f;       _42=0.0f;    _43=zn/(zn-zf);    _44=1.0f;

				// 2/w  0    0           0
				// 0    2/h  0           0
				// 0    0    1/(zn-zf)   0
				// 0    0    zn/(zn-zf)  l
			}


			//! \brief Построение ортографической матрицы   ПРОВЕРЕНА
			inline void setOrthoOffCenterLH(float minX, float maxX, float minY, float maxY, float zn, float zf)
			{
				_11 = 2.0f/(maxX-minX);         _12 = 0.0f,                     _13 = 0.0f,            _14 = 0.0f;
				_21 = 0.0f,                     _22 = 2.0f/(maxY-minY);         _23 = 0.0f,            _24 = 0.0f;
				_31 = 0.0f,                     _32 = 0.0f,                     _33 = 1.0f/(zf-zn);    _34 = 0.0f;
				_41 = (minX+maxX)/(minX-maxX);  _42 = (maxY+minY)/(minY-maxY);  _43 = zn/(zn-zf);      _44 = 1.0f;
			}


			//! \brief Построение ортографической матрицы  ПРОВЕРЕНА
			inline void setOrthoOffCenterRH(float minX, float maxX, float minY, float maxY, float zn, float zf)
			{
				_11=2.0f/(maxX-minX);        _12=0.0f;                     _13=0.0f;            _14=0.0f;
				_21=0.0f;                    _22=2.0f/(maxY-minY);         _23=0.0f;            _24=0.0f;
				_31=0.0f;                    _32=0.0f;                     _33=1.0f/(zn-zf);    _34=0.0f;
				_41=(minX+maxX)/(minX-maxX); _42=(maxY+minY)/(minY-maxY);  _43=zn/(zn-zf);      _44=1.0f;

				// 2/(r-l)      0            0           0
				// 0            2/(t-b)      0           0
				// 0            0            1/(zn-zf)   0
				// (l+r)/(l-r)  (t+b)/(b-t)  zn/(zn-zf)  l
			}


			//-------------------------------------------------------------

			//! \brief построение перспективной левосторонней матрицы. ПРОВЕРЕНА.
			void setPerspectiveFovLH(float fov, float asp, float zn, float zf)
			{
				const float yScale =   gbmath::scalar::cotan(fov/2.0f); //yScale = cot(fovY/2)
				const float xScale = yScale / asp;     //xScale = yScale / aspect ratio

				//xScale     0          0               0
				//0        yScale       0               0
				//0          0       zf/(zf-zn)         1
				//0          0       -zn*zf/(zf-zn)     0
				_11 = xScale;   _12 = 0.0f;    _13 = 0.0f;             _14 = 0.0f;
				_21 = 0.0f;     _22 = yScale;  _23 = 0.0f;             _24 = 0.0f;
				_31 = 0.0f;     _32 = 0.0f;    _33 =  zf/(zf-zn);      _34 = 1.0f;
				_41 = 0.0f;     _42 = 0.0f;    _43 = -zn*zf/(zf-zn);   _44 = 0.0f;
			}

			//! \brief построение перспективной правосторонней матрицы. ПРОВЕРЕНА.
			void setPerspectiveFovRH(float fov, float asp, float zn, float zf)
			{
			 const float yScale =   gbmath::scalar::cotan(fov/2.0f);
			 const float xScale = yScale / asp;

			    _11 = xScale;   _12 = 0.0f;    _13 = 0.0f;           _14 = 0.0f;
				_21 = 0.0f;     _22 = yScale;  _23 = 0.0f;           _24 = 0.0f;
				_31 = 0.0f;     _32 = 0.0f;    _33 = zf/(zn-zf);     _34 = -1.0f;
				_41 = 0.0f;     _42 = 0.0f;    _43 = zn*zf/(zn-zf);  _44 = 0.0f;
				// xScale     0          0              0
				// 0        yScale       0              0
				// 0        0        zf/(zn-zf)        -1
				// 0        0        zn*zf/(zn-zf)      0
				// where:
				// yScale = cot(fovY/2)
				// xScale = yScale / aspect ratio
			}


			//! \brief Построение перспективной левосторонней матрицы по высоте и ширине .ПРОВЕРЕНА.
			void setPerspectiveLH(float w, float h, float zn, float zf)
			{
				// 2*zn/w  0       0              0
				// 0       2*zn/h  0              0
				// 0       0       zf/(zf-zn)     1
				// 0       0       zn*zf/(zn-zf)  0

				_11 = 2.0f*zn/w;  _12 = 0.0f,        _13 = 0.0f,           _14 = 0.0f;
				_21 = 0.0f,       _22 = 2.0f*zn/h;   _23 = 0.0f,           _24 = 0.0f;
				_31 = 0.0f,       _32 = 0.0f,        _33 = zf/(zf-zn);     _34 = 1.0f;
				_41 = 0.0f,       _42 = 0.0f,        _43 = zn*zf/(zn-zf);  _44 = 0.0f;
			}

			//! \brief Построение перспективной правосторонней матрицы по высоте и ширине. ПРОВЕРЕНА.
			void setPerspectiveRH(float w, float h, float zn, float zf)
			{
				// 2*zn/w  0       0              0
				// 0       2*zn/h  0              0
				// 0       0       zf/(zn-zf)    -1
				// 0       0       zn*zf/(zn-zf)  0

				_11 = 2.0f*zn/w;  _12 = 0.0f,       _13 = 0.0f,           _14 = 0.0f;
				_21 = 0.0f,       _22 = 2.0f*zn/h;  _23 = 0.0f,           _24 = 0.0f;
				_31 = 0.0f,       _32 = 0.0f,       _33 = zf/(zn-zf);     _34 = -1.0f;
				_41 = 0.0f,       _42 = 0.0f,       _43 = zn*zf/(zn-zf);  _44 = 0.0f;
			}


			//-------------------------------------------------------------

			/** \brief Построение левосторонней матрицы вида. ПРОВЕРЕНА.  */
			void setViewLookAtLH(const vec3& eye, const vec3& at, const vec3& up)
			{
            vec3  zaxis = (at - eye);  zaxis.normalize();
		    vec3  xaxis = up.cross(zaxis); xaxis.normalize();
		    vec3  yaxis =  zaxis.cross(xaxis);

		   _11=xaxis.x;           _12=yaxis.x;            _13=zaxis.x;            _14=0.0f;
		   _21=xaxis.y;           _22=yaxis.y;            _23=zaxis.y;            _24=0.0f;
		   _31=xaxis.z;           _32=yaxis.z;            _33=zaxis.z;            _34=0.0f;
		   _41= -xaxis.dot(eye);  _42= -yaxis.dot(eye);   _43= -zaxis.dot(eye);   _44=1.0f;

			// zaxis = normal(At - Eye)
			// xaxis = normal(cross(Up, zaxis))
			// yaxis = cross(zaxis, xaxis)
			// xaxis.x           yaxis.x           zaxis.x          0
			// xaxis.y           yaxis.y           zaxis.y          0
			// xaxis.z           yaxis.z           zaxis.z          0
			// -dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  l
			}


			/** \brief Построение правосторонней матрицы вида. ПРОВЕРЕНА.  */
			void setViewLookAtRH(const vec3& eye, const vec3& at, const vec3& up)
			{
            vec3  zaxis = (eye - at);  zaxis.normalize();
		    vec3  xaxis = up.cross(zaxis); xaxis.normalize();
		    vec3  yaxis =  zaxis.cross(xaxis);

		   _11=xaxis.x;           _12=yaxis.x;            _13=zaxis.x;            _14=0.0f;
		   _21=xaxis.y;           _22=yaxis.y;            _23=zaxis.y;            _24=0.0f;
		   _31=xaxis.z;           _32=yaxis.z;            _33=zaxis.z;            _34=0.0f;
		   _41= -xaxis.dot(eye);  _42= -yaxis.dot(eye);   _43= -zaxis.dot(eye);   _44=1.0f;

	    	// zaxis = normal(Eye - At)
	    	// xaxis = normal(cross(Up, zaxis))
	    	// yaxis = cross(zaxis, xaxis)
	    	//  xaxis.x           yaxis.x           zaxis.x          0
	    	//  xaxis.y           yaxis.y           zaxis.y          0
	    	//  xaxis.z           yaxis.z           zaxis.z          0
	     	// -dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)
			}


			/** \brief Построение левосторонней матрицы вида  по направлению взгляда */
			inline  void setViewDirLH(const vec3& eye, const vec3& dir, const vec3& up)
			{
                #pragma message ("KS777 MATH::MAT44  need check setViewDirLH" __FILE__ )

				vec3 dirn = dir.normalized();
				const float flen = eye.length();
				dirn.x += flen;
				dirn.y += flen;
				dirn.z += flen;
				vec3 at = eye + dirn;
				setViewLookAtLH( eye, at, up);
			}

			/** \brief Построение правосторонней матрицы вида  по направлению взгляда */
			inline  void setViewDirRH(const vec3& eye, const vec3& dir, const vec3& up)
			{
				#pragma message ("KS777 MATH::MAT44 warn  need check setViewDirRH" __FILE__ )

				vec3 to = dir.normalized();
				const float flen = eye.length();
				to.x += flen;
				to.y += flen;
				to.z += flen;

				vec3 at = eye + to;
				setViewLookAtRH( eye, at, up);
			}



#if ( defined GB_OPENGL  && defined __GL_H__ )

			//! \brief  Старый способ  перемножения матрицы с текущей в OpenGL
			inline void glMul()  { glMultMatrixf( (GLfloat*)&_11  ); }

			//! \brief   Старый способ загрузки матрицы  в OpenGL
			inline void glLoad() { glLoadMatrixf( (GLfloat*)&_11  ); }

			//! \brief Загрузить из контекста OpenGL проекционную матрицу.
			inline void glGetProjection()
			{
				glGetFloatv(GL_PROJECTION_MATRIX, &_11);
			}

			//! \brief Загрузить из контекста OpenGL модель-видовую (WORLD X VIEW) матрицу.
			inline void glGetModelView()
			{
				glGetFloatv(GL_MODELVIEW_MATRIX, &_11);
			}

#endif // gb  OpenGL


#ifdef _D3D9_H_  // d3d9 device methods

			   //! \brief Установить матрицу в устройство d3d9 как матрицу ВИДА
			   inline HRESULT makeDevice9TransfView(IDirect3DDevice9* pdevice) const
			   {
				   return pdevice->SetTransform(D3DTS_VIEW, (D3DMATRIX*)&_11 );
			   }

			   //! \brief Установить матрицу в устройство d3d9 как матрицу ПРОЕКЦИИ
			   inline HRESULT makeDevice9TransfProj(IDirect3DDevice9* pdevice) const
			   {
				   return pdevice->SetTransform(D3DTS_PROJECTION, (D3DMATRIX*)&_11 );
			   }

			   //! \brief Установить матрицу в устройство d3d9 как матрицу ТРАНСФОРМАЦИИ
			   inline HRESULT makeDevice9TransfWorld(IDirect3DDevice9* pdevice)
			   {
				   return pdevice->SetTransform(D3DTS_WORLD, (D3DMATRIX*)&_11 );
			   }

			   //! \brief Установить матрицу в девайс как матрицу трансформации по данному типу trType
			   inline HRESULT makeDevice9Transf(IDirect3DDevice9* pdevice, D3DTRANSFORMSTATETYPE trType ) const
			   {
				   return pdevice->SetTransform( trType, (D3DMATRIX*)&_11 );
			   }




			   //! \brief Получить из устройства d3d9   матрицу ВИДА
			   inline HRESULT readDevice9TransfView(IDirect3DDevice9* pdevice)
			   {
				   return pdevice->GetTransform(D3DTS_VIEW, (D3DMATRIX*)&_11 );
			   }

			   //! \brief Получить из устройства устройства d3d9   матрицу ПРОЕКЦИИ
			   inline HRESULT readDevice9TransfProj(IDirect3DDevice9* pdevice)
			   {
				   return pdevice->GetTransform(D3DTS_PROJECTION, (D3DMATRIX*)&_11 );
			   }

			   //! \brief Получить из устройства устройства d3d9   матрицу ТРАНСФОРМАЦИИ
			   inline HRESULT readDevice9TransfWorld(IDirect3DDevice9* pdevice)
			   {
				   return pdevice->GetTransform(D3DTS_WORLD, (D3DMATRIX*)&_11 );
			   }



#endif // _D3D9_H_



				//! \brief Вывод значений на консоль
			   inline void print() const
			   {
				   printf("\n%f   %f   %f   %f  \n%f   %f   %f   %f  \n%f   %f   %f   %f  \n%f   %f   %f   %f  \n  ",
					   _11, _12, _13, _14,
					   _21, _22, _23, _24,
					   _31, _32, _33, _34,
					   _41, _42, _43, _44
					   );
			   }


		};






			static const mat44     MATRIX44_IDENTITY =  mat44
			(
			  1.0f,  0.0f,  0.0f,  0.0f,
			  0.0f,  1.0f,  0.0f,  0.0f,
			  0.0f,  0.0f,  1.0f,  0.0f,
			  0.0f,  0.0f,  0.0f,  1.0f
			);






}