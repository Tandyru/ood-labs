#include "stdafx.h"
#include "SetTitleCommandParser.h"
#include "SetTitleInputCommand.h"
#include "CommandParser.h"

using namespace std;
using namespace input_command;

namespace command_parser
{

unique_ptr<InputCommand> ParseSetTitleCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s*)e", 1, [](const cmatch& match) {
		const string title = match.suffix();
		return make_unique<SetTitleInputCommand>(title);
	}, "Invalid 'SetTitle' command string format");
}

}
