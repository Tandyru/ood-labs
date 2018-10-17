#pragma once
#include "InputCommand.h"
#include "DocumentItemPosition.h"
#include <string>

namespace input_command
{

struct ReplaceTextInputCommand : public InputCommand
{
	command::Position position = command::END_POSITION;
	std::string text;
};

}