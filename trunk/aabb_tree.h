/**  \file
 \brief  box tree class.  In development


*/

#if 1

#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



 namespace gbmath
 {

   //template <typename TUserType>

 //! \brief  box tree
   class aabb_tree {
   public:

     template <typename TUserType>
     class Node {
	 public:

	    TUserType value;
		aabb aabb;

		/*
		class Iterator {
		public:
			Iterator(const Node<TUserType>& node) : __node(node)
			{

			}

			operator == ()
			{
			xxxxxxxxx
			}

			Node<TUserType> operator *()
			{
			xxxxxxxxxx
			}

		private:
		  Node<TUserType>& __node;

		};
		 */

		const std::vector<TUserType>& get_ghild() const 
		{
			return _child;
		}

		void push_back(const Node<TUserType>& n)
		{
		  _child.push_back(n);
		}

		Node<TUserType> operator [] (size_t index) throw()
		{
			if(index >_child.size()-1)
			{
			  throw std::runtime_error("bad index");
			}

		 return _child(index);
		}

		//

		//Iterator& begin()
		//{
		// Iterator res();
		//}





	 private:
	   std::vector< Node<TUserType> > _child;

	 };




   };


 }


#endif

// end file