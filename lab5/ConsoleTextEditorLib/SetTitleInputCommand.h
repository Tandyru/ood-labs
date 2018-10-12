#pragma once
#include "InputCommand.h"
#include <string>

namespace input_command
{
	struct SetTitleInputCommand : public InputCommand
	{
		std::string title;
	};
}