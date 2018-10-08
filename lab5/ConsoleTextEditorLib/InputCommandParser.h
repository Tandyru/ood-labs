#pragma once
#include "InputCommand.h"
#include <string_view>

namespace command_parser
{

	unique_ptr<input_command::InputCommand> ParseInputCommand(string_view input);

}
