
#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__


#pragma once

#ifndef __GB_FMATH_H__
    #error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif

#include <boost/array.hpp>
#include <iostream>
#include <string>

namespace gb
{

	namespace fmath
	{

	template <typename T, size_t NumColumns, size_t NumRows>
	struct matrix : public boost::array< T , NumColumns * NumRows > {


		inline matrix<T,NumColumns,NumRows> () {}

		inline matrix<T,NumColumns,NumRows> ( const matrix<T,NumColumns,NumRows>& a )
		{
			*this = a;
		}


		inline matrix<T,NumColumns,NumRows>(const T* _array)
		{ 
			*this = _array; 
		}


		inline operator  const T*() const  { return elems; }
		inline operator        T*()        { return elems; }


		inline matrix<T,NumColumns,NumRows> operator - () const 
		{
			matrix<T,NumColumns,NumRows> res;
			for(size_t c=0; c<size(); c++)
			{
				res.elems[c] = -elems[c];
			}
			return res;
		}

		inline matrix<T,NumColumns,NumRows> operator + (const T& value) const
		{
			matrix<T,NumColumns,NumRows> res;
			for(size_t c=0; c<size(); c++)
			{
				res.elems[c] = elems[c] + value;
			}
			return res;
		}

		inline matrix<T,NumColumns,NumRows> operator - (const T& value) const
		{
			matrix<T,NumColumns,NumRows> res;
			for(size_t c=0; c<size(); c++)
			{
				res.elems[c] = elems[c] - value;
			}
			return res;
		}


		inline matrix<T,NumColumns,NumRows> operator * (const T& value) const
		{
			matrix<T,NumColumns,NumRows> res;
			for(size_t c=0; c<size(); c++)
			{
				res.elems[c] = elems[c] * value;
			}
			return res;
		}

		inline matrix<T,NumColumns,NumRows> operator / (const T& value) const
		{
			matrix<T,NumColumns,NumRows> res;
			for(size_t c=0; c<size(); c++)
			{
				res.elems[c] = elems[c] / value;
			}
			return res;
		}


		inline matrix<T,NumColumns,NumRows>& operator += (const T& value)
		{
			for(size_t c=0; c<size(); c++)
			{
				elems[c] += value;
			}
			return *this;
		}

		inline matrix<T,NumColumns,NumRows>& operator -= (const T& value)
		{
			for(size_t c=0; c<size(); c++)
			{
				elems[c] -= value;
			}
			return *this;
		}


		inline matrix<T,NumColumns,NumRows>& operator *= (const T& value)
		{
			for(size_t c=0; c<size(); c++)
			{
				elems[c] *= value;
			}
			return *this;
		}


		inline matrix<T,NumColumns,NumRows>& operator /= (const T& value)
		{
			for(size_t c=0; c<size(); c++)
			{
				elems[c] /= value;
			}
			return *this;
		}




		inline void operator = (const T* _array)
		{
			for(size_t c=0; c<size(); c++)
			{
			   elems[c] = _array[c];
			}
		}


		inline void set_zero()
		{
			const T _ZERO = T();
			T* _ptr = begin();
			for(size_t c=0; c<NumColumns*NumRows; c++)
			{
			   _ptr[c] = _ZERO;
			}
		}

		inline bool is_zero() const
		{
			const T _ZERO = T();
			const T* _ptr = begin();
			for(size_t c=0; c<NumColumns*NumRows; c++)
			{
				if( _ptr[c] != _ZERO ) return false;
			}
			return true;
		}


		boost::array<T,NumRows> get_column() const 
		{
			boost::array<T,NumRows> res;
			for(size_t c=0; c<NumRows; c++)
			{
			  assert(false);  // ????????? xxxxxxx
			}
			return res;
		}

		boost::array<T,NumColumns> get_row() const 
		{
			boost::array<T,NumColumns> res;
			for(size_t c=0; c<NumColumns; c++)
			{
				assert(false);  // ????????? xxxxxxx
			}
			return res;
		}

		inline T& at(size_t column, size_t row)
		{
			if( column>=NumColumns || row>=NumRows )
			{
				throw std::range_error("bad index");
			}
			return elems[ row * NumColumns + column ];	// [ c * NumColumns + j ];
		}
	
	
		#pragma message("NEED ADD to/from string operators  "   __FILE__ )
	
		/*
		template <>
		matrix<T,NumColumns,NumRows> operator * (const matrix<T,NumColumns,NumRows>& a) const
		{
			BOOST_STATIC_ASSERT(   )
		
			matrix<T,NumColumns,NumRows> r;
			
			
		
		
			return r;
		}
	 */
 
		friend std::ostream &operator << (std::ostream &stream, const matrix<T,NumColumns,NumRows>& m)
		{
				for(size_t c=0; c<NumRows; c++)
				{
					for(size_t j=0; j<NumColumns; j++)
					{
						const T temp =  m[ c * NumColumns + j ];   //< temp
						stream << temp;
						
						if(j != NumColumns-1)
						{
							stream << " ";
						}
						
					}
					
					stream << "\n";
				}

				stream << "\n";

			return stream;
		}
		 

	protected:
		inline T& __at(size_t column, size_t row)
		{
			return elems[ row * NumColumns + column ];
		}
	 

	};



	namespace __test 
	{
		inline void __test_matrix()
		{
			using namespace std;
			matrix<float,3,4> mat;
			cout << mat << endl;

		cout << "sizeof (48):  " << sizeof(mat) << endl;


		cout << "fill values" << endl;
		for(size_t c=0; c<(3*4); c++)
		{
			mat[c] = (float)c;
		}
		cout << mat << endl;

		system("pause");


		 cout << "set_zero()"  << endl;
		 mat.set_zero();
		 cout << mat << endl;



			int _end =0;
		}








	}




	}

}

#endif // __MATRIX_HPP__