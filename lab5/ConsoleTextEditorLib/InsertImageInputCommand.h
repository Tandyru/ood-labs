#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct InsertImageInputCommand : public InputCommand
{
	Position position = END_POSITION;
	unsigned int width = 0;
	unsigned int height = 0;
	string path;

	InsertImageInputCommand(Position position, unsigned int width, unsigned int height, string path);

	void Execute(IInputCommandExecutor& executor) override;

};

}