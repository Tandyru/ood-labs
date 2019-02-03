#include "stdafx.h"
#include "ResizeImageCommandParser.h"
#include "ResizeImageInputCommand.h"
#include "PositionParser.h"

using namespace std;
using namespace input_command;

namespace command_parser
{

unique_ptr<InputCommand> ParseResizeImageCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+)\s+(\d+)\s+(\d+))e", 4, [](const cmatch& match) {
		const string positionStr = match[2];
		const unsigned int width = stoul(string(match[3]));
		const unsigned int height = stoul(string(match[4]));
		const Position position = ParsePosition(positionStr);
		return make_unique<ResizeImageInputCommand>(position, width, height);
	}, "Invalid 'ResizeImage' command string format");
}

}
