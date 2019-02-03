#pragma once
#include "InputCommand.h"

namespace command_parser
{
std::unique_ptr<input_command::InputCommand> ParseSetTitleCommand(std::string_view input);
}