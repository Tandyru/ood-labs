#pragma once
#include "InputCommand.h"

void ReadInputCommands(istream& input, const std::function<void(unique_ptr<input_command::InputCommand>&&)>& handler);
