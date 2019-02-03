#pragma once
#include "InputCommand.h"

using InputCommandHandler = std::function<void(std::unique_ptr<input_command::InputCommand>&&)>;
using InputCommandErrorHandler = std::function<void(const std::exception& ex)>;
void ReadInputCommands(std::istream& input, std::ostream & out, const InputCommandHandler& handler, const InputCommandErrorHandler& errorHandler);
