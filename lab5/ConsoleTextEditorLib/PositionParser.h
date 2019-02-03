#pragma once
#include "DocumentItemPosition.h"

namespace command_parser
{

input_command::Position ParsePosition(std::string_view str);

}