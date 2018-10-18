#include "stdafx.h"
#include "SaveInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

SaveInputCommand::SaveInputCommand(const string & path)
	: InputCommand(InputCommandType::Save)
	, path(path)
{
}

void SaveInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteCommand(*this);
}

}
