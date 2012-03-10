/**  \file
 \brief  

*/

#pragma once

#ifndef __GBMATH_H__
    #error  DO NOT INCLUDE THIS FILE. USE:   #include <gbmath/_gbmath.h>
#endif


 
namespace gbmath
{



	namespace detail 
	{

		bool check_str_maybe_name(const char* str);

		class value_name {
		private:
			char m_name[32];

		public:

			value_name()
			{
				m_name[0] = '\0';
			}
		
			value_name(const char* name) throw (std::runtime_error) ;
			~value_name() {}


			bool empty() const
			{
				return m_name[0] == '\0';
			}

			inline bool operator == (const value_name& a) const 
			{
				return	*this == a.m_name;
			}
		

			bool operator == (const char* a) const throw (std::runtime_error);

			void operator = (const char* a) throw (std::runtime_error);


		};


		typedef    float (__cdecl *FuncGetFloatValue)(void* user_ptr);

		typedef    const vec2*  (__cdecl *FuncGetVector2Value)(void* user_ptr);	
		typedef    const vec3*  (__cdecl *FuncGetVector3Value)(void* user_ptr);	
		typedef    const vec4*  (__cdecl *FuncGetVector4Value)(void* user_ptr);	

		typedef    const mat33*  (__cdecl *FuncGetMatrix33Value)(void* user_ptr);	
		typedef    const mat44*  (__cdecl *FuncGetMatrix44Value)(void* user_ptr);



		struct itemFloatValue 
		{
			value_name name;
			 FuncGetFloatValue func;
			 void* user_ptr;


			// itemFloatValue(const char* _name, FuncGetFloatValue _func, void* _user_ptr) throw (std::runtime_error)
			//	 : name(_name), func(_func), user_ptr(_user_ptr)
			// {
			//	 if(!_func) 
			//		 throw std::runtime_error("function is null");
			 //
			 //
			 //}

			itemFloatValue()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};

 		struct itemVector2Value 
		{
			value_name name;
			FuncGetVector2Value func;
			void* user_ptr;


			itemVector2Value()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};


		struct itemVector3Value 
		{
			value_name name;
			FuncGetVector3Value func;
			void* user_ptr;


			itemVector3Value()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};

		struct itemVector4Value 
		{
			value_name name;
			FuncGetVector4Value func;
			void* user_ptr;

			itemVector4Value()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};

		struct itemMatrix33Value 
		{
			value_name name;
			FuncGetMatrix33Value func;
			void* user_ptr;

			itemMatrix33Value()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};


		struct itemMatrix44Value 
		{
			value_name name;
			FuncGetMatrix44Value func;
			void* user_ptr;

			itemMatrix44Value()
			{
				func = NULL;
				user_ptr = NULL;
			}

		};




	}


	class valueServer {
	private:
		std::vector<detail::itemFloatValue> m_FloatValues;

		std::vector<detail::itemVector2Value> m_Vector2Values;
		std::vector<detail::itemVector3Value> m_Vector3Values;
		std::vector<detail::itemVector4Value> m_Vector4Values;
	
		std::vector<detail::itemMatrix33Value> m_Matrix33Values;
		std::vector<detail::itemMatrix44Value> m_Matrix44Values;

	
	public:
 

		valueServer()
		{
		
		}
		
		virtual ~valueServer() {}
		
		

		//----------------------------------------------------------
		bool isFloatValueExists(const char* val_name) const;

		bool isVector2ValueExists(const char* val_name) const;
		bool isVector3ValueExists(const char* val_name) const;
		bool isVector4ValueExists(const char* val_name) const;

		bool isMatrix33ValueExists(const char* val_name) const;
		bool isMatrix44ValueExists(const char* val_name) const;

		//----------------------------
		
		int registerFloatValue(const char* val_name, detail::FuncGetFloatValue _func, void* _user_ptr) throw(std::runtime_error);	

		int registerVector2Value(const char* val_name, detail::FuncGetVector2Value _func, void* _user_ptr) throw(std::runtime_error);		
		int registerVector3Value(const char* val_name, detail::FuncGetVector3Value _func, void* _user_ptr) throw(std::runtime_error);
		int registerVector4Value(const char* val_name, detail::FuncGetVector4Value _func, void* _user_ptr) throw(std::runtime_error);	
		
		int registerMatrix33Value(const char* val_name, detail::FuncGetMatrix33Value _func, void* _user_ptr) throw(std::runtime_error);		
		int registerMatrix44Value(const char* val_name, detail::FuncGetMatrix44Value _func, void* _user_ptr) throw(std::runtime_error);
		
		
		
		//-----------------------------
		
		float getFloatValue(const int index) const throw(int);
		
		const vec2* getVector2Value(const int index) const throw(int);
		const vec3* getVector3Value(const int index) const throw(int);
		const vec4* getVector4Value(const int index) const throw(int);		
		
		const mat33* getMatrix33Value(const int index) const throw(int);		
		const mat44* getMatrix44Value(const int index) const throw(int);	


		
		//-------------------------
		


		
	
	};





}
