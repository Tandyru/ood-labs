#pragma once
#include "Color.h"

namespace shape
{

struct IFillStyle
{
	virtual void SetColor(const Color& color) = 0;
	virtual Color GetColor() const = 0;

	virtual void SetFill(bool fill) = 0;
	virtual bool GetFill() const = 0;

	virtual ~IFillStyle() = default;
};

}