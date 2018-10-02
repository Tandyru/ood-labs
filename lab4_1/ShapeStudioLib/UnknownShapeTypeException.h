#pragma once
#include <exception>
#include <string>

class UnknownShapeTypeException : public std::exception
{
public:
	UnknownShapeTypeException(const std::string& type)
		: m_type(type)
	{
	}

	char const* what() const override
	{
		m_message = std::string("Unknown shape type: ") + m_type;
		return m_message.c_str();
	}
private:
	std::string m_type;
	mutable std::string m_message;
};
