#pragma once
#include "InputCommand.h"

using InputCommandHandler = std::function<void(unique_ptr<input_command::InputCommand>&&)>;
using InputCommandErrorHandler = std::function<void(const exception& ex)>;
void ReadInputCommands(istream& input, ostream & out, const InputCommandHandler& handler, const InputCommandErrorHandler& errorHandler);
