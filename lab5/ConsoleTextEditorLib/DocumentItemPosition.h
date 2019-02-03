#pragma once
#include <limits>

namespace input_command
{

//const unsigned int END_POSITION = std::numeric_limits<unsigned int>::max();
//using Position = unsigned int;
using Position = std::optional<size_t>;
const auto END_POSITION = Position();

}