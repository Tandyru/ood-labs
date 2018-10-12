#pragma once
#include "InputCommand.h"
#include "CommandParser.h"

namespace command_parser
{
	unique_ptr<input_command::InputCommand> ParseDeleteItemCommand(string_view input);
}