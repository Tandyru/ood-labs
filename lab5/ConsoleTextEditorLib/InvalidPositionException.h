#pragma once
#include <exception>

namespace document
{

class CInvalidPositionException
	: public std::exception
{
public:
	inline CInvalidPositionException() 
		: std::exception("Invalid position exception")
	{
	}
};

}