#include "stdafx.h"
#include "InputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

InputCommand::InputCommand(InputCommandType type)
	: type(type)
{
}

void InputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteNonArgCommand(type);
}

}