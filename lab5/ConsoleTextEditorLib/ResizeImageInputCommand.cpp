#include "stdafx.h"
#include "ResizeImageInputCommand.h"
#include "IInputCommandExecutor.h"

namespace input_command
{

ResizeImageInputCommand::ResizeImageInputCommand(command::Position position, unsigned int width, unsigned int height)
	: InputCommand(InputCommandType::ResizeImage)
	, position(position)
	, width(width)
	, height(height)
{
}

void ResizeImageInputCommand::Accept(IInputCommandVisitor & executor)
{
	executor.ExecuteCommand(*this);
}


}
