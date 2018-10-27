#include "stdafx.h"
#include "InputCommandsReader.h"
#include "InputCommandParser.h"
#include <istream>

using namespace input_command;
using namespace command_parser;

void ReadInputCommands(istream & input, const std::function<void(unique_ptr<input_command::InputCommand>&&)>& handler)
{
	string readline;
	while (getline(input, readline))
	{
		auto inputCommand = ParseInputCommand(readline);
		handler(move(inputCommand));
	}
}
