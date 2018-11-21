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

	virtual void SetLineThickness(const ThicknessType& thickness) = 0;
	virtual ThicknessType GetLineThickness() const = 0;

	virtual ~ILineStyle() = default;
};

}