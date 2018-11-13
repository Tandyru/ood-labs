#pragma once
#include "Color.h"

namespace shape
{

struct IFillStyle
{
	virtual void SetColor(Color color) = 0;
	virtual Color GetColor() const = 0;

	virtual ~IFillStyle() = default;
};

}