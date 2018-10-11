#include "stdafx.h"
#include "InsertParagraphCommandParser.h"
#include "InsertParagraphInputCommand.h"
#include "PositionParser.h"
#include <regex>
#include <string>

namespace command_parser
{

using namespace input_command;

unique_ptr<input_command::InputCommand> ParseInsertParagraphCommand(string_view input)
{

	regex re(R"e(^(\w+)\s+(\d+|end)\s+)e");
	cmatch match;
	string str(input);
	if (regex_search(str.c_str(), match, re) && match.size() > 2) {
		const string positionStr = match[2];
		const string text = match.suffix();
		const command::Position position = ParsePosition(positionStr);
		return make_unique<InsertParagraphInputCommand>(InsertParagraphInputCommand{ command::CommandType::InsertParagraph, position, text });
	}
	throw std::exception("Invalid 'InsertParagraph' command string format");
}

}
