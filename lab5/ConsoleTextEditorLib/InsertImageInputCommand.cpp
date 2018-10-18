#include "stdafx.h"
#include "InsertImageInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

InsertImageInputCommand::InsertImageInputCommand(command::Position position, unsigned int width, unsigned int height, string path)
	: InputCommand(InputCommandType::InsertImage)
	, position(position)
	, width(width)
	, height(height)
	, path(path)
{
}

void InsertImageInputCommand::Accept(IInputCommandVisitor & executor)
{
	executor.ExecuteCommand(*this);
}

}
