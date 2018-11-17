#pragma once
#include "Color.h"

namespace shape
{

class ILineStyle
{
public:
	typedef size_t ThicknessType;

	virtual void SetColor(Color color) = 0;
	virtual Color GetColor() const = 0;

	virtual void SetLineThickness(ThicknessType thickness) = 0;
	virtual ThicknessType GetLineThickness() const = 0;

	virtual ~ILineStyle() = default;
};

}