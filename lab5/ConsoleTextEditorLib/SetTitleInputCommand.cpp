#include "stdafx.h"
#include "SetTitleInputCommand.h"
#include "IInputCommandExecutor.h"

using namespace std;

namespace input_command
{

SetTitleInputCommand::SetTitleInputCommand(const string & title)
	: InputCommand(InputCommandType::SetTitle)
	, title(title)
{
}

void SetTitleInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteCommand(*this);
}

}