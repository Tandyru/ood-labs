#include "stdafx.h"
#include "ReplaceTextCommandParser.h"
#include "ReplaceTextInputCommand.h"
#include "PositionParser.h"
#include "CommandParser.h"

using namespace std;
using namespace input_command;

namespace command_parser
{

unique_ptr<input_command::InputCommand> ParseReplaceTextCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+)\s+)e", 2, [](const cmatch& match) {
		const string positionStr = match[2];
		const Position position = ParsePosition(positionStr);
		const string text = match.suffix();
		return make_unique<ReplaceTextInputCommand>(position, text);
	}, "Invalid 'ReplaceText' command string format");
}

}
