#include "stdafx.h"
#include "InsertImageCommandParser.h"
#include "InsertImageInputCommand.h"
#include "PositionParser.h"
#include <regex>
#include <string>

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseInsertImageCommand(string_view input)
{
	regex re(R"e(^(\w+)\s+(\d+|end)\s+(\d+))e"); // s+(\d+)
	cmatch match;
	string str(input);
	if (regex_search(str.c_str(), match, re) /*&& match.size() > 4*/) {
		const string positionStr = match[2];
		const unsigned int width = stoul(string(match[3]));
		const unsigned int height = stoul(string(match[4]));
		const command::Position position = ParsePosition(positionStr);
		const string path = match.suffix();
		return make_unique<InsertImageInputCommand>(InsertImageInputCommand{ command::CommandType::InsertImage, position, width, height, path });
	}
	throw std::exception("Invalid 'InsertImage' command string format");
}

}
