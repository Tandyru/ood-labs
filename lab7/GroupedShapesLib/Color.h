#pragma once

namespace shape
{

struct Color
{
	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = 0;
};

const Color NONE_COLOR;

inline bool operator==(const Color & color1, const Color & color2)
{
	return color1.r == color2.r &&
		color1.g == color2.g &&
		color1.b == color2.b &&
		color1.a == color2.a;
}

}

