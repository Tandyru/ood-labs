#include "stdafx.h"
#include "DeleteItemCommandParser.h"
#include "DeleteItemInputCommand.h"
#include "PositionParser.h"

namespace command_parser
{

using namespace std;
using namespace input_command;

unique_ptr<InputCommand> ParseDeleteItemCommand(string_view input)
{
	return ParseCommand(input, R"e(^(\w+)\s+(\d+))e", 2, [](const cmatch& match) {
		const string positionStr = match[2];
		const Position position = ParsePosition(positionStr);
		return make_unique<DeleteItemInputCommand>(position);
	}, "Invalid 'DeleteItem' command string format");
}

}
