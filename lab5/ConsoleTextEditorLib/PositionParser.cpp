#include "stdafx.h"
#include "PositionParser.h"

namespace command_parser
{

namespace
{
const auto END_POSITION_STRING_VALUE = "end";
}

command::Position ParsePosition(string_view str)
{
	if (str == END_POSITION_STRING_VALUE)
	{
		return command::END_POSITION;
	}
	return command::Position(stoul(string(str)));
}

}
