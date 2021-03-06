#include "stdafx.h"
#include "InsertImageCommandParser.h"
#include "InsertImageInputCommand.h"
#include "PositionParser.h"

using namespace std;
using namespace input_command;

namespace command_parser
{

unique_ptr<input_command::InputCommand> ParseInsertImageCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+|end)\s+(\d+)\s+(\d+)\s+)e", 4, [](const cmatch& match) {
		const string positionStr = match[2];
		const unsigned int width = stoul(string(match[3]));
		const unsigned int height = stoul(string(match[4]));
		const Position position = ParsePosition(positionStr);
		const string path = match.suffix();
		return make_unique<InsertImageInputCommand>(position, width, height, path);
	}, "Invalid 'InsertImage' command string format");
}

}
