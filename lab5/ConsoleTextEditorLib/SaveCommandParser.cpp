#include "stdafx.h"
#include "SaveCommandParser.h"
#include "SaveInputCommand.h"
#include "PositionParser.h"

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseSaveCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+)e", 1, [](const cmatch& match) {
		const string path = match.suffix();
		return make_unique<SaveInputCommand>(SaveInputCommand{ command::CommandType::Save, path });
	}, "Invalid 'Save' command string format");
}

}
