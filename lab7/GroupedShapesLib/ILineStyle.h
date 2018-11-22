#pragma once
#include "Color.h"

namespace shape
{

class ILineStyle
{
public:
	typedef optional<double> ThicknessType;
	typedef optional<Color> ColorType;

	virtual void SetColor(const ColorType& color) = 0;
	virtual ColorType GetColor() const = 0;

	virtual void SetThickness(const ThicknessType& thickness) = 0;
	virtual ThicknessType GetThickness() const = 0;

	virtual ~ILineStyle() = default;
};

inline bool operator==(const ILineStyle::ColorType& color1, const ILineStyle::ColorType& color2)
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

inline bool operator!=(const ILineStyle::ColorType& color1, const ILineStyle::ColorType& color2)
{
	return !(color1 == color2);
}

}