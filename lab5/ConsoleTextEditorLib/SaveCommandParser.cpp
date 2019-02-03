#include "stdafx.h"
#include "SaveCommandParser.h"
#include "SaveInputCommand.h"
#include "PositionParser.h"

using namespace std;

namespace command_parser
{

using namespace input_command;

unique_ptr<InputCommand> ParseSaveCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+)e", 1, [](const cmatch& match) {
		const string path = match.suffix();
		return make_unique<SaveInputCommand>(path);
	}, "Invalid 'Save' command string format");
}

}
