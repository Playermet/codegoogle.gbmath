/** \file

  \brief Stack the matrices

  \author ksacvet777
*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif

#include <stack>


#pragma warning(push)
#pragma warning(disable : 4290)



 

namespace gbmath
{


	//! \brief The stack of matrices based on std::stack
	class MatrixStackStd 
	{
	public:

				  MatrixStackStd()  {}
		virtual  ~MatrixStackStd()
		{
			while( !m_stack.empty() )
			{
				   m_stack.pop();
			}
		}
 
		int empty() const
		{
			return m_stack.size()==0;
		}

		void push()
		{
			mat44 m (1.0f);
			if(!m_stack.empty() )
			{
			  m = m_stack.top();
			}
			m_stack.push(m);
			m_stack.top() = m;
		}

		void pop() throw(std::runtime_error&)
		{
			if (empty() )
			{
				throw std::runtime_error("stack empty");
			}

			m_stack.pop();

		}

		mat44& top()
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("Stack empty");
			}

			return m_stack.top();
		}

		const mat44& top()  const
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("Stack empty");
			}

			return m_stack.top();
		}

		void loadIdentity() throw(std::runtime_error&)
		{
				if(m_stack.empty())
				{
					throw std::runtime_error("stack empty");
				}

				m_stack.top().setIdentity();
		}

		//! \brief m_stack.top() = m;
		void load(const mat44& m)  throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			m_stack.top() = m;
		}

		//! \brief  m_stack.top() = m_stack.top() * m;
		void mul(const mat44& m)    throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			m_stack.top() = m_stack.top() * m;
		}

		//! \brief   m_stack.top() = m * m_stack.top();
		void mul_local(const mat44& m)      throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			m_stack.top() = m * m_stack.top();
		}

		//! \brief  m_stack.top() = m_stack.top() * mscaling;
		void scale(float x, float y, float z)      throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			mat44 mscaling;
			mscaling.setScaling(x,y,z);
			m_stack.top() = m_stack.top() * mscaling;
		}

		//! \brief m_stack.top() = m_stack.top() * mrotate;
		void rotate(const vec3& ax, float angle) throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			mat44 mrotate;
			mrotate.setRotationAxis(ax,angle);
		    m_stack.top() = m_stack.top() * mrotate;
		}

		//! \brief m_stack.top() = m_stack.top() * mrotate;
		void rotate(const Quaternion& q) throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}

			mat44 mrotate;
			mrotate.setRotationQuaternion(q);
			m_stack.top() = m_stack.top() * mrotate;
		}

		//! \brief m_stack.top() = m_stack.top() * mtranslate;
		inline void translate(float x, float y, float z) throw(std::runtime_error&)
		{
			if(m_stack.empty())
			{
				throw std::runtime_error("stack empty");
			}
			mat44 mtranslate;
			mtranslate.setTranslation(x,y,z);
			m_stack.top() = m_stack.top() * mtranslate;
		}

		//! \brief m_stack.top() = m_stack.top() * mtranslate;
		inline void translate(const vec3& v)
		{
			translate(v.x , v.y , v.y);
		}

		std::stack<mat44> m_stack;

	};

    
 
}


#pragma warning(pop)

 