#pragma once
#include "InputCommand.h"
#include <string>

namespace input_command
{
	struct SaveInputCommand : public InputCommand
	{
		std::string path;
	};
}