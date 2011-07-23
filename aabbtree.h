/**  \file
 \brief  яяяяяяяяяяяяя


*/

#if 0

#pragma once

#ifndef __GB_FMATH_H__
#error НЕ ВКЛЮЧАЙТЕ ЭТОТ ФАЙЛ. ВКЛЮЧАЙТЕ:   #include <gb/fmath/math.h>  
#endif


namespace gb
{

 namespace fmath
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

}

#endif

// end file