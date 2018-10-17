#include "stdafx.h"
#include "InputCommandType.h"
#include "IsValueInArray.h"

namespace input_command
{

bool IsNonargCommand(InputCommandType type)
{
	static InputCommandType nonargCommands[] = {
		InputCommandType::List,
		InputCommandType::Help,
		InputCommandType::Undo,
		InputCommandType::Redo,
	};
	return IsValueInArray(type, nonargCommands);
}
}