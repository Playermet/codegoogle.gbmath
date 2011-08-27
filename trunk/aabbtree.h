 
#if 0

#pragma once

#ifndef __GBMATH_H__
#error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif



 namespace gbmath
 {

   //template <typename TUserType>
   class AABBTree {
   public:

     template <typename TUserType>
     class Node {
	 public:

	    TUserType value;
		AABB aabb;

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


		void push_back(const Node<T>& n)
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

		Iterator& begin()
		{
		 Iterator res();
		}





	 private:
	   std::vector< Node<TUserType> > _child;

	 };




   };


 }


#endif

// end file