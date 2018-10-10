#pragma once
#include "DocumentItemPosition.h"

namespace command_parser
{

command::Position ParsePosition(string_view str);

}