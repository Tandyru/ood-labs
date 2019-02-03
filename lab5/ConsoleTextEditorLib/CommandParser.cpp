#include "stdafx.h"
#include "CommandParser.h"

namespace command_parser
{

using namespace std;
using namespace input_command;

using CommandBuilder = std::function<unique_ptr<input_command::InputCommand>(const cmatch& match)>;

unique_ptr<input_command::InputCommand> ParseCommand(string_view input, const char* regexp, unsigned matchCount,
	const CommandBuilder& builder, const char* invalidFormatMessage)
{
	regex re(regexp);
	cmatch match;
	string str(input);
	if (regex_search(str.c_str(), match, re) && match.size() > matchCount)
	{
		return builder(match);
	}
	throw std::exception(invalidFormatMessage);
}

}
