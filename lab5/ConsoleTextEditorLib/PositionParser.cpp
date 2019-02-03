#include "stdafx.h"
#include "PositionParser.h"

using namespace std;

namespace command_parser
{

namespace
{
const auto END_POSITION_STRING_VALUE = "end";
}

input_command::Position ParsePosition(string_view str)
{
	if (str == END_POSITION_STRING_VALUE)
	{
		return input_command::END_POSITION;
	}
	return input_command::Position(stoul(string(str)));
}

}
