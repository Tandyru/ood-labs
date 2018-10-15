#pragma once

template<typename T, unsigned int SZ>
bool IsValueInArray(T value, const T(&array)[SZ])
{
	for (auto val : array)
	{
		if (value == val)
		{
			return true;
		}
	}
	return false;
}
