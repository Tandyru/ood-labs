#pragma once
#include "InputCommand.h"

namespace command_parser
{
	unique_ptr<input_command::InputCommand> ParseInsertImageCommand(string_view input);
}