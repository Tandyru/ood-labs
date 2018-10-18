#include "stdafx.h"
#include "DeleteItemInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

DeleteItemInputCommand::DeleteItemInputCommand(command::Position position)
	: InputCommand(InputCommandType::DeleteItem)
	, position(position)
{
}

void DeleteItemInputCommand::Accept(IInputCommandVisitor & executor)
{
	executor.ExecuteCommand(*this);
}

}