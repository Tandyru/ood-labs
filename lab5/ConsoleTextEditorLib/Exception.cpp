#include "stdafx.h"
#include "Exception.h"

Exception::Exception(const char* message)
	: m_message(message)
{
}

char const * Exception::what() const
{
	return m_message.c_str();
}

