#pragma once
#include "ColorOptional.h"

namespace shape
{

class ILineStyle
{
public:
	typedef std::optional<double> ThicknessType;
	typedef ColorOptional ColorType;

	virtual void SetColor(const ColorType& color) = 0;
	virtual ColorType GetColor() const = 0;

	virtual void SetThickness(const ThicknessType& thickness) = 0;
	virtual ThicknessType GetThickness() const = 0;

	virtual ~ILineStyle() = default;
};


}