#include "stdafx.h"
#include "ReplaceTextInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

ReplaceTextInputCommand::ReplaceTextInputCommand(command::Position position, const string & text)
	: InputCommand(InputCommandType::ReplaceText)
	, position(position)
	, text(text)
{
}

void ReplaceTextInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteCommand(*this);
}

}
