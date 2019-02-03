#include "stdafx.h"
#include "InsertParagraphCommandParser.h"
#include "InsertParagraphInputCommand.h"
#include "PositionParser.h"
#include "CommandParser.h"

using namespace std;

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseInsertParagraphCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+|end)\s+)e", 2, [](const cmatch& match) {
		const string positionStr = match[2];
		const string text = match.suffix();
		const Position position = ParsePosition(positionStr);
		return make_unique<InsertParagraphInputCommand>(position, text);
	}, "Invalid 'InsertParagraph' command string format");
}

}
