#pragma once
#include "InputCommand.h"
#include <regex>
#include <functional>
#include <string>

namespace command_parser
{
using CommandBuilder = std::function<std::unique_ptr<input_command::InputCommand>(const std::cmatch& match)>;

std::unique_ptr<input_command::InputCommand> ParseCommand(string_view input, const char* regexp, unsigned matchCount,
	const CommandBuilder& builder, const char* invalidFormatMessage);
}