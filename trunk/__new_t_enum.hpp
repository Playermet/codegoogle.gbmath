
#pragma once
 
#include <boost/any.hpp>
#include <boost/static_assert.hpp>


template <typename ENUM, typename int MAX_UNUSED>
class Enumerator {
public:

	BOOST_STATIC_ASSERT(sizeof(ENUM)==4 );

	Enumerator<ENUM,MAX_UNUSED> () 
	{
		_value = (ENUM)0;
	}


	Enumerator<ENUM,MAX_UNUSED> (const Enumerator<ENUM,MAX_UNUSED>& e)
	{
		_value = e.value;
	}

	void operator = (const ENUM e)
	{
		_value = e;
	}

	operator ENUM() const 
	{
		return _value;
	}

	bool is_first() const 
	{
		return (int)(_value) - 1 == 0;
	}

	bool is_last() const 
	{
		return (_value-MAX_UNUSED-1)  == 0;
	}



private:
	ENUM  _value;
};
