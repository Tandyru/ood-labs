#include "stdafx.h"
#include "InsertParagraphCommandParser.h"
#include "InsertParagraphInputCommand.h"
#include "PositionParser.h"
#include "CommandParser.h"

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseInsertParagraphCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+|end)\s+)e", 2, [](const cmatch& match) {
		const string positionStr = match[2];
		const string text = match.suffix();
		const command::Position position = ParsePosition(positionStr);
		return make_unique<InsertParagraphInputCommand>(InsertParagraphInputCommand{ command::InputCommandType::InsertParagraph, position, text });
	}, "Invalid 'InsertParagraph' command string format");
}

}
