#pragma once
#include "InputCommandType.h"

namespace input_command
{

class IInputCommandExecutor;

struct InputCommand
{
	InputCommandType type;

	InputCommand(InputCommandType type);

	virtual void Execute(IInputCommandExecutor& executor);
	virtual ~InputCommand() = default;
};

}