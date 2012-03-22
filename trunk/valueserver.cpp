#pragma once

#include "_gbmath.h"


#pragma warning(push)
#pragma warning(disable : 4290)
#pragma warning(disable : 4996)

 
namespace gbmath
{

 namespace detail
 {

	 bool check_str_maybe_name(const char* str)
	 {
		 if(!str) return  false;
		 
		 const size_t LEN =  strlen(str);
		 for(size_t c=0; c<LEN; c++)
		 {
			 if( c == 0 )
			 {
				 // first iter
				if( (str[c] >= 'A') && (str[c] <= 'Z')  ) continue;
				if( (str[c] >= 'a') && (str[c] <= 'z')  ) continue;
			 
				continue;
			 }
			 else
			 {
				return false;
			 }


			 if( (str[c] >= 'A') && (str[c] <= 'Z')  )
				 continue;

			 if( (str[c] >= 'a') && (str[c] <= 'z')  )
				 continue;

			 if( (str[c] >= '0') && (str[c] <= '9')  )
				 continue;

			 if( (str[c]=='-') || (str[c]=='_')  )
				 continue;


			 return false;

		 }

		 return  true;
	 }



	//===================================================================
	 value_name::value_name(const char* name) throw (std::runtime_error)
	 {
		 m_name[0] = '\0';

		*this = name;

	 }

	 bool value_name::operator == (const char* a) const throw (std::runtime_error)
	 {
		 assert(false && "need debug step");

		 if (a==NULL)
		 {
			 throw std::runtime_error("NULL");
		 }

		 if(a[0] == '\0')
		 {
			 throw std::runtime_error("empty name");
		 }

		 if( !check_str_maybe_name(a))
		 {
			 throw std::runtime_error("bad argument string");
		 }

		 const size_t srclen = strlen(a);

		 int c=0;
		 while(true)
		 {

			 if( (m_name[c] == '\0') || (a[c] == '\0') )
			 {
				 return false;
			 }

			 if( tolower(m_name[c]) != tolower(a[c]) )
			 {
				 return false;
			 }


			 c++;
		 }

		 return true;
	 }

	 void value_name::operator = (const char* a) throw (std::runtime_error)
	 {
		 assert(false && "need debug step");

		 if (a==NULL)
		 {
			 throw std::runtime_error("name string is NULL");
		 }

		 if(a[0] == '\0')
		 {
			 throw std::runtime_error("empty name");
		 }

		 const size_t LEN = strlen(a);
		 if(LEN > 31)
		 {
			 throw std::runtime_error("big name");
		 }

		 if( !check_str_maybe_name(a) ) 
		 {
			 throw std::runtime_error("bad string name");
		 }


		 strncpy(m_name, a, 31);
	 }


 }




 //=============================================


	bool valueServer::isFloatValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_FloatValues.size(); c++)
		{
			if( m_FloatValues[c].name == val_name )   return true;
		}

		return false;
	}

	bool valueServer::isVector2ValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_Vector2Values.size(); c++)
		{
			if( m_Vector2Values[c].name == val_name )   return true;
		}

		return false;
	}

	bool valueServer::isVector3ValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_Vector3Values.size(); c++)
		{
			if( m_Vector3Values[c].name == val_name )   return true;
		}

		return false;
	}
 
	bool valueServer::isVector4ValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_Vector4Values.size(); c++)
		{
			if( m_Vector4Values[c].name == val_name )   return true;
		}

		return false;
	}

	bool valueServer::isMatrix33ValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_Matrix33Values.size(); c++)
		{
			if( m_Matrix33Values[c].name == val_name )   return true;
		}

		return false;
	}

	bool valueServer::isMatrix44ValueExists(const char* val_name) const
	{
		for(size_t c=0; c<m_Matrix44Values.size(); c++)
		{
			if( m_Matrix44Values[c].name == val_name )   return true;
		}

		return false;
	}


 int valueServer::registerFloatValue(const char* val_name, detail::FuncGetFloatValue _func, void* _user_ptr) throw(std::runtime_error)
 {
	  if( isFloatValueExists(val_name) )
	  {
		  std::string temp;
		  temp = "value ";
		  temp += val_name;
		  temp += " exists";
		  throw std::runtime_error(temp);
	  }

	  detail::itemFloatValue itm;

	  itm.name = val_name;
	  itm.func = _func;
	  itm.user_ptr = _user_ptr;
	  m_FloatValues.push_back(itm);


	  return (int)(m_FloatValues.size()-1);
 }

 int valueServer::registerVector2Value(const char* val_name, detail::FuncGetVector2Value _func, void* _user_ptr) throw(std::runtime_error)
 {
	 if( isVector2ValueExists(val_name) )
	 {
		 std::string temp;
		 temp = "value ";
		 temp += val_name;
		 temp += " exists";
		 throw std::runtime_error(temp);
	 }

	 detail::itemVector2Value itm;

	 itm.name = val_name;
	 itm.func = _func;
	 itm.user_ptr = _user_ptr;
	 m_Vector2Values.push_back(itm);


	 return (int)(m_Vector2Values.size()-1);
 }

 int valueServer::registerVector3Value(const char* val_name, detail::FuncGetVector3Value _func, void* _user_ptr) throw(std::runtime_error)
 {
	  
	 if( isVector3ValueExists(val_name) )
	 {
		 std::string temp;
		 temp = "value ";
		 temp += val_name;
		 temp += " exists";
		 throw std::runtime_error(temp);
	 }

	 detail::itemVector3Value itm;

	 itm.name = val_name;
	 itm.func = _func;
	 itm.user_ptr = _user_ptr;
	 m_Vector3Values.push_back(itm);


	 return (int)(m_Vector3Values.size()-1);
 }

 int valueServer::registerVector4Value(const char* val_name, detail::FuncGetVector4Value _func, void* _user_ptr)  throw(std::runtime_error)
 {
	  
	 if( isVector4ValueExists(val_name) )
	 {
		 std::string temp;
		 temp = "value ";
		 temp += val_name;
		 temp += " exists";
		 throw std::runtime_error(temp);
	 }

	 detail::itemVector4Value itm;

	 itm.name = val_name;
	 itm.func = _func;
	 itm.user_ptr = _user_ptr;
	 m_Vector4Values.push_back(itm);


	 return (int)(m_Vector4Values.size()-1);
 }

 int valueServer::registerMatrix33Value(const char* val_name, detail::FuncGetMatrix33Value _func, void* _user_ptr) throw(std::runtime_error)
 {
	  
	 if( isMatrix33ValueExists(val_name) )
	 {
		 std::string temp;
		 temp = "value ";
		 temp += val_name;
		 temp += " exists";
		 throw std::runtime_error(temp);
	 }

	 detail::itemMatrix33Value itm;

	 itm.name = val_name;
	 itm.func = _func;
	 itm.user_ptr = _user_ptr;
	 m_Matrix33Values.push_back(itm);


	 return (int)(m_Matrix33Values.size()-1);

 }

 int valueServer::registerMatrix44Value(const char* val_name, detail::FuncGetMatrix44Value _func, void* _user_ptr) throw(std::runtime_error)
 {
	  
	 if( isMatrix44ValueExists(val_name) )
	 {
		 std::string temp;
		 temp = "value ";
		 temp += val_name;
		 temp += " exists";
		 throw std::runtime_error(temp);
	 }

	 detail::itemMatrix44Value itm;

	 itm.name = val_name;
	 itm.func = _func;
	 itm.user_ptr = _user_ptr;
	 m_Matrix44Values.push_back(itm);


	 return (int)(m_Matrix44Values.size()-1);
 }

 //===========================================

 float valueServer::getFloatValue(const int index) const throw(int)
 {
	 if( index > (int)m_FloatValues.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemFloatValue& itm = m_FloatValues[index];
	 const float res = itm.func(itm.user_ptr);
	 return res;
 }

 const vec2* valueServer::getVector2Value(const int index) const throw(int)
 {
	 if( index > (int)m_Vector2Values.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemVector2Value& itm = m_Vector2Values[index];
	 const vec2* res = itm.func(itm.user_ptr);
	 return res;
 }

 const vec3* valueServer::getVector3Value(const int index) const throw(int)
 {
	 if( index > (int)m_Vector3Values.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemVector3Value& itm = m_Vector3Values[index];
	 const vec3* res = itm.func(itm.user_ptr);
	 return res;
 }

 const vec4* valueServer::getVector4Value(const int index) const throw(int)
 {
	 if( index > (int)m_Vector4Values.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemVector4Value& itm = m_Vector4Values[index];
	 const vec4* res = itm.func(itm.user_ptr);
	 return res;
 }

 const mat33* valueServer::getMatrix33Value(const int index) const throw(int)
 {
	 if( index > (int)m_Matrix33Values.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemMatrix33Value& itm = m_Matrix33Values[index];
	 const mat33* res = itm.func(itm.user_ptr);
	 return res;
 }

 const mat44* valueServer::getMatrix44Value(const int index) const throw(int)
 {
	 if( index > (int)m_Matrix44Values.size()-1 )
	 {
		 throw (index);
	 }

	 const detail::itemMatrix44Value& itm = m_Matrix44Values[index];
	 const mat44* res = itm.func(itm.user_ptr);
	 return res;
 }


}

#pragma warning(pop)
