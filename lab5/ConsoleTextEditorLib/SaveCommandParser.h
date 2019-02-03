#pragma once
#include "InputCommand.h"
#include "CommandParser.h"

namespace command_parser
{
std::unique_ptr<input_command::InputCommand> ParseSaveCommand(std::string_view input);
}