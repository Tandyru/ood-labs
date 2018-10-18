#include "stdafx.h"
#include "SetTitleInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

SetTitleInputCommand::SetTitleInputCommand(const string & title)
	: InputCommand(InputCommandType::SetTitle)
	, title(title)
{
}

void SetTitleInputCommand::Accept(IInputCommandVisitor & executor)
{
	executor.ExecuteCommand(*this);
}

}