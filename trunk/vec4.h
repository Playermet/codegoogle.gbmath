/**  \file
 \brief ??????


*/

#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb 
{

	namespace fmath
	{
	
	
	


		/** \brief Базовый 4d-вектор. Поправить операторы по эпислону   */		
		struct vec4  {

		    union 
			{
			
				struct 
				{
				   float x, y, z, w;
				};

				float floats [4];
			};

			inline vec4() { x=y=z=w=0.0f; };

			inline vec4(const vec4& v)      { x=v.x;  y=v.y; z=v.z; w=v.w;  };
//			inline vec4(const vec4* v)      { x=v->x;  y=v->y; z=v->z; w=v->w;  };

			inline vec4(const vec3& v, float _w)  { x=v.x;  y=v.y; z=v.z; w=_w;  };

			inline vec4(const vec2& v, float _z, float _w) {x=v.x; y=v.y; z=_z; w=_w; }

			inline vec4(float _x, float _y, float _z, float _w)   { x=_x;   y=_y; z=_z; w=_w;  }
			inline vec4(int   _x, int   _y, int   _z, int   _w)   { x=(float)_x;   y=(float)_y;  z=(float)_z; w=(float)_w;}

			//! \brief Присваивание из float-массива 
			inline void operator = (const float* pf) {x=pf[0]; y=pf[1]; z=pf[2]; w=pf[3]; }
 
					 
			inline bool  operator == (const vec4 &v) const {	return (x == v.x && y == v.y && z == v.z && w == v.w); }
			inline bool  operator != (const vec4 &v) const {	return (x != v.x || y != v.y || z != v.z || w != v.w); }
 
			inline vec4  operator + () const   { 	return *this; }
			inline vec4  operator - () const { vec4 res;	res.x = -x;	res.y = -y;	res.z = -z;	res.w = -w;	return res; }

			inline vec4  operator + (const vec4 &v) const {	vec4 res;	res = *this;	res += v;	return res; }
			inline vec4  operator - (const vec4 &v) const {	vec4 res;	res = *this;	res -= v;	return res; }
			inline vec4  operator * (float f) const         {	vec4 res;	res = *this;	res.x *= f;	res.y *= f;	res.z *= f;	res.w *= f;	return res; }
			inline vec4  operator / (float f) const         {	vec4 res;	res = *this;	res.x /= f;	res.y /= f;	res.z /= f;	res.w /= f;	return res; }

			inline vec4 &  operator += (const vec4 &v) {	x += v.x;	y += v.y;	z += v.z;	w += v.w;	return *this; }
			inline vec4 &  operator -= (const vec4 &v) {	x -= v.x;	y -= v.y;	z -= v.z;	w -= v.w;	return *this; }
			inline vec4 &  operator *= (float f)         {	x *= f;	y *= f;	z *= f;	w *= f;	return *this; }

			inline vec4 &  operator /= (float f)         {	x /= f;	y /= f;	z /= f;	w /= f;	return *this; }

			inline operator  const float*() const  { return &x; }
			inline operator        float*()        { return &x; }
 


			inline float operator [] (unsigned int index) const
			{
				assert(index<4 && "invalid index");
				const float* pf = &x;
				return pf[index];
			}

			inline  float& operator [] (unsigned int index) 
			{
				assert(index<4 && "invalid index");
				float* pf = &x;
				return *(pf + index);
			}




#ifdef __D3DX9MATH_H__
			inline operator D3DXVECTOR4*() { return (D3DXVECTOR4*)&x; }
			inline operator const D3DXVECTOR4*() const { return (D3DXVECTOR4*)&x; }
			inline operator D3DXVECTOR4() const  {  return D3DXVECTOR4(x,y,z,w); }
		   	inline void operator = (const D3DXVECTOR4& v) {	x=v.x; y=v.y; z=v.z; w=v.w; }	
#endif					
			
			//! \brief Обнулить все компоненты
		    inline void setzero() {x=y=z=w=0.0f; }
			//! проверить равны ли все компоненты нулю
			inline bool empty() const { return ( (x==0.0f) && (y==0.0f) && (z==0.0f) && (w==0.0f) ); }

			inline vec4& set    (float _x, float _y, float _z, float _w) { x=_x; y=_y; z=_z; w=_w; return *this; }
 
			//! \brief  Все ли компоненты нулевые по эпсилону.
			inline bool isZero(float epsilon) const
			{
				return( abs( x ) <= epsilon ) && ( abs( y ) <= epsilon ) && ( abs( z ) <= epsilon ) && ( abs( y ) <= epsilon );
			}

			//! \brief  получить длинну
			inline float length () const {	return (float)sqrt( x*x + y*y + z*z + w*w );	}
			//! \brief  получить квадрат длинны
			inline float lengthSq() const {	 return (x*x + y*y + z*z + w*w);  }

			//! \brief   Вернуть скалярное произведение с вектором v
			inline float   dot (const vec4& v) const { return x*v.x + y*v.y + z*v.z + w*v.w; }

			
#pragma message ("KS777: MATH::VEC4 >> NEED CHECK CROSS METHOD !!!"  __FILE__)
			//! \brief Получить векторное (перекрестное)  произведение с вектором v.
			inline vec4  cross ( const vec4 & v) const
			{
				  vec4 r;
				r.x = ( z * v.w - w * v.z) * y + ( w * v.y - y * v.w) * z + ( y * v.z - z * v.y) * w;
				r.y = ( w * v.z - z * v.w) * x + ( x * v.w - w * v.x) * z + ( z * v.x - x * v.z) * w;
				r.z = ( y * v.w - w * v.y) * x + ( w * v.x - x * v.w) * y + ( x * v.y - y * v.x) * w;
				r.w = ( z * v.y - y * v.z) * x + ( x * v.z - z * v.x) * y + ( y * v.x - x * v.y) * z;
				  return r;
			}


			// НЕПРАВИЛЬНО !!!!
			void cross( const vec4& U, const vec4& V, const vec4& W )   
			{
				assert(false && "bad code !");

				float a = V.x*W.y - V.y*W.x;
				float b = V.x*W.z - V.z*W.x;
				float c = V.x*W.w - V.w*W.x;
				float d = V.y*W.z - V.z*W.y;
				float e = V.y*W.w - V.w*W.y;
				float f = V.z*W.w - V.w*W.z;

				vec4 Out;
				Out.x = f*U.y - e*U.z + d*U.w ;
				Out.y = f*U.x + c*U.z - b*U.w ; // no valid
				Out.z = e*U.x - c*U.y + a*U.w ;
				Out.w = d*U.x + b*U.y - a*U.z ; // no valid

				*this = Out;
			}

			//! \brief  Инвертировать.
			inline vec4&   invert() {  x=-x; y=-y; z=-z; w=-w; return *this; };
			//! \brief  Вернуть инвертированый.
			inline vec4    inverted() const 
			{
				vec4 res = *this;
				res.invert();
				return res;
			}

			//! \brief  Вернуть вектор по линейной интерполяции между this и v  по коэффициенту k
			inline vec4    lerp(const vec4& v, const float k) 
			{
				vec4 r;
				r.x = x + (v.x - x) * k;
				r.y = y + (v.y - y) * k;
				r.z = z + (v.z - z) * k;
				r.w = w + (v.w - w) * k;
				return r;			
			}



			//! \brief  Получить минимальную компоненту.
			inline float minval() const 
			{ 	  
				float res = x;
				if(y<res) res=y;
				if(z<res) res=z;
				if(w<res) res=w;
				return res;
			}

			//! \brief Получить максимальную компоненту.
			inline float maxval() const
			{   
				float res = x;
				if(res<y) res=y;
				if(res<z) res=z;
				if(res<w) res=w;
				return res;
			}	
 
		/** \brief  вычисл. минимальной абсолютной компоненты.  */
		inline float minAbsVal() const 
		{ 
			float ax=abs(x); 
			float ay=abs(y); 
			float az=abs(z); 
			float aw=abs(w);
				  float res=ax;    
				  if(ay<res) res=ay; 
				  if(az<res) res=az; 
				  if(aw<res) res=aw; 
				  return res; 
		}

		/** \brief  вычисл. максимальной абсолютной компоненты.  */
		inline float maxAbsVal() const 
		{ 
			float ax=abs(x); 
			float ay=abs(y); 
			float az=abs(z); 
			float aw=abs(w);
				  float res=ax;
				  if(ay>res) res=ay; 
				  if(az>res) res=az;	 
				  if(aw>res) res=aw;	
				  return res;	
		}


		//! \brief Выполнить отсечение значений в диапазоне между vmin и vmax
		inline void clump(const vec4& vmin, const vec4& vmax) 
		{
			if( x < vmin.x) x=vmin.x;  if(x > vmax.x) x=vmax.x;
			if( y < vmin.y) y=vmin.y;  if(y > vmax.y) y=vmax.y;
			if( z < vmin.z) z=vmin.z;  if(z > vmax.z) z=vmax.z;
			if( w < vmin.w) w=vmin.w;  if(w > vmax.w) w=vmax.w;
		}



	//void toCstr(char* buf) const 
	//{
	//	*buf = '\0';
	//    sprintf(buf, "%f %f %f %f", x, y, z, w );
	//}

	//bool fromCstr(const char* s) 
	//{
	//	const int NS = sscanf(s, "%f%f%f%f", &x, &y, &z, &w);
	//	if(4!=NS)  return false;
	//	return true;
	//}
 

			friend std::ostream &operator << (std::ostream &stream, const vec4& v)
			{
				stream << v.x << " " << v.y << " " << v.z << " " << v.w;
				return stream;
			}


 			operator std::string() const 
			{
				std::ostringstream ss;
				ss << x << " " << y << " " << z << " " << w;
				return ss.str();
			}

			void operator = (const std::string& str) throw (std::invalid_argument)
			{
				std::istringstream ss(str);
				ss >> x;
				ss >> y;
				ss >> z;
				ss >> w;
				if( ss.fail() ) throw std::invalid_argument("bad input string");
			}

			friend std::istringstream &operator >> (std::istringstream &ss, vec4& v)
			{
				ss >> v.x;
				ss >> v.y;
				ss >> v.z;
				ss >> v.w;
				return ss;
			}
 
			friend std::istream &operator >> (std::istream &stream, vec4& v)
			{
				stream >> v.x;
				stream >> v.y;
				stream >> v.z;
				stream >> v.w;
				return stream;
			}
			


		}; 
		// end vec4
 
	
	}
}
