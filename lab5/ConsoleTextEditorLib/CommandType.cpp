#include "stdafx.h"
#include "CommandType.h"

namespace command
{

template<typename T, unsigned int SZ>
bool IsValueInArray(T value, const T (&array)[SZ])
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

bool IsNonargCommand(CommandType type)
{
	static CommandType nonargCommands[] = {
		CommandType::List, 
		CommandType::Help,
		CommandType::Undo,
		CommandType::Redo,
	};
	return IsValueInArray(type, nonargCommands);
}
}