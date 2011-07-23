// matrix_quad.hpp


#ifndef __MATRIX_QUAD_HPP__
#define __MATRIX_QUAD_HPP__


#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif

//#include "matrix.hpp"

namespace gb
{

	namespace fmath
	{
	
 
	template <typename T, size_t N>
	struct matrix_quad : public  matrix<T, N, N> {
	  

		inline matrix_quad() {}

		inline matrix_quad(const matrix_quad<T,N>& m)
		{
			*this = m;
		}


		inline void set_identity()
		{
			const T _ZERO = (T)0;
			const T _ONE = (T)1;
			for(size_t c=0; c<N; c++)
			{
				for(size_t j=0; j<N; j++)
				{
					if( j == c )
					{
						elems[  c * N + j  ] = _ONE;
					}
					else
					{
						elems[  c * N + j  ] = _ZERO;
					}
				}
			}
		}

		matrix_quad<T,N> operator * (const matrix_quad<T,N>& a)
		{
			assert(false); // ??????? xxxxxx need check !
			matrix_quad<T,N> res;
			for(size_t i=0; i<N; i++)
			{
				for(size_t j=0; j<N; j++)
				{
					res.at(i,j) = T();
					for (size_t k=0; k<N; k++) 
					{
						res.at(i,j) += a.at(i,k) * b.at(k,j);
					}
				}
			}
			return res;
		}










	}; 


	//------------------------------------------------------------------------------------------------
	
	namespace __test
	{
	
	inline void __test_matrix_quad()
	{
		matrix_quad<float,4> mat;

		using namespace std;
		cout << mat << std::endl;
	

	   system("pause");

	   cout << "set identity" << endl;
		mat.set_identity();
	   cout << mat <<endl;
	
	




		 system("pause");
	    int _end =0;
	}
	
	
	}





	
	
	}
}

#endif // __MATRIX_QUAD_HPP__