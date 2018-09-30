#pragma once
#include <utility>

template<typename T1, typename T2, unsigned int SZ>
T2 MapEnum(const std::pair<T1, T2> (&map)[SZ], T1 value)
{
	for (auto& item : map)
	{
		if (item.first == value)
		{
			return item.second;
		}
	}
	throw std::exception("Invalid enum value");
}

template<typename T1, typename T2, unsigned int SZ>
T2 StringMapEnum(const std::pair<T1, T2> (&map)[SZ], const std::string& value)
{
	for (auto& item : map)
	{
		if (std::string(item.first) == value)
		{
			return item.second;
		}
	}
	throw std::exception("Invalid enum value");
}

template<typename T1, typename T2, unsigned int SZ>
T1 ReverseMapEnum(const std::pair<T1, T2> (&map)[SZ], T2 value)
{
	for (auto& item : map)
	{
		if (item.second == value)
		{
			return item.first;
		}
	}
	throw std::exception("Invalid enum value");
}

template<typename T1, typename T2, unsigned int SZ>
T1 ReverseStringMapEnum(const std::pair<T1, T2> (&map)[SZ], const std::string& value)
{
	for (auto& item : map)
	{
		if (std::string(item.second) == value)
		{
			return item.first;
		}
	}
	throw std::exception("Invalid enum value");
}
