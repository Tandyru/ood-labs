#include "stdafx.h"
#include "InsertImageInputCommand.h"
#include "IInputCommandExecutor.h"

using namespace std;

namespace input_command
{

InsertImageInputCommand::InsertImageInputCommand(Position position, unsigned int width, unsigned int height, string path)
	: InputCommand(InputCommandType::InsertImage)
	, position(position)
	, width(width)
	, height(height)
	, path(path)
{
}

void InsertImageInputCommand::Execute(IInputCommandExecutor & executor)
{
	executor.ExecuteCommand(*this);
}

}
