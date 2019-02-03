#pragma once
#include "InputCommand.h"

namespace command_parser
{
std::unique_ptr<input_command::InputCommand> ParseInsertParagraphCommand(std::string_view input);
}