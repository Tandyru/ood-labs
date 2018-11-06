#pragma once
#include "Exception.h"

namespace document
{

class CInvalidPositionException
	: public Exception
{
public:
	inline CInvalidPositionException() 
		: Exception("Invalid position exception")
	{
	}
};

}