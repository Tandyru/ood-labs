#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct ResizeImageInputCommand : public InputCommand
{
	command::Position position = command::END_POSITION;
	unsigned int width = 0;
	unsigned int height = 0;

	ResizeImageInputCommand(command::Position position, unsigned int width, unsigned int height);

	void Accept(IInputCommandVisitor& executor) override;

};

}