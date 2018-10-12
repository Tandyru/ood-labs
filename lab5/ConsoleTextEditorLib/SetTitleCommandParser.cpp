#include "stdafx.h"
#include "SetTitleCommandParser.h"
#include "SetTitleInputCommand.h"
#include "CommandParser.h"

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseSetTitleCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s*)e", 1, [](const cmatch& match) {
		const string title = match.suffix();
		return make_unique<SetTitleInputCommand>(SetTitleInputCommand{ command::CommandType::SetTitle, title });
	}, "Invalid 'SetTitle' command string format");
}

}
