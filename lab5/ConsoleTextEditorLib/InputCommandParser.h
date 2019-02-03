#pragma once
#include "InputCommand.h"
#include <string_view>

namespace command_parser
{

	std::unique_ptr<input_command::InputCommand> ParseInputCommand(std::string_view input);

}
