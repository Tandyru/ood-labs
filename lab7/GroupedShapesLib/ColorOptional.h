#pragma once
#include "Color.h"
#include <optional>

namespace shape
{

typedef std::optional<Color> ColorOptional;

inline bool operator==(const ColorOptional& color1, const ColorOptional& color2)
{
	if (!color1 && !color2)
	{
		return true;
	}
	if ((!color1 && color2) || (color1 && !color2))
	{
		return false;
	}
	return *color1 == *color2;
}

inline bool operator!=(const ColorOptional& color1, const ColorOptional& color2)
{
	return !(color1 == color2);
}

}