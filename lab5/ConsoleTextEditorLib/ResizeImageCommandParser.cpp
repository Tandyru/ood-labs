#include "stdafx.h"
#include "ResizeImageCommandParser.h"
#include "ResizeImageInputCommand.h"
#include "PositionParser.h"

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseResizeImageCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+)\s+(\d+)\s+(\d+))e", 4, [](const cmatch& match) {
		const string positionStr = match[2];
		const unsigned int width = stoul(string(match[3]));
		const unsigned int height = stoul(string(match[4]));
		const command::Position position = ParsePosition(positionStr);
		return make_unique<ResizeImageInputCommand>(ResizeImageInputCommand{ command::InputCommandType::ResizeImage, position, width, height });
	}, "Invalid 'ResizeImage' command string format");
}

}
