#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct ResizeImageInputCommand : public InputCommand
{
	Position position = END_POSITION;
	unsigned int width = 0;
	unsigned int height = 0;

	ResizeImageInputCommand(Position position, unsigned int width, unsigned int height);

	void Execute(IInputCommandExecutor& executor) override;

};

}