#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(const char* message);

	char const* what() const override;

private:
	std::string m_message;
};