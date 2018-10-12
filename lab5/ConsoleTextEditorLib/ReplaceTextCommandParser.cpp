#include "stdafx.h"
#include "ReplaceTextCommandParser.h"
#include "ReplaceTextInputCommand.h"
#include "PositionParser.h"
#include "CommandParser.h"

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseReplaceTextCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+)\s+)e", 2, [](const cmatch& match) {
		const string positionStr = match[2];
		const command::Position position = ParsePosition(positionStr);
		const string text = match.suffix();
		return make_unique<ReplaceTextInputCommand>(ReplaceTextInputCommand{ command::CommandType::ReplaceText, position, text });
	}, "Invalid 'ReplaceText' command string format");
}

}
