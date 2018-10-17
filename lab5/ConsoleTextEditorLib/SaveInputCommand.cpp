#include "stdafx.h"
#include "SaveInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

void SaveInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteSaveCommand(*this);
}

}
