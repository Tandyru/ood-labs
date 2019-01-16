#pragma once
#include "ColorOptional.h"

namespace shape
{

struct IFillStyle
{
	typedef ColorOptional ColorType;
	typedef std::optional<bool> FillType;

	virtual void SetColor(const ColorType& color) = 0;
	virtual ColorType GetColor() const = 0;

	virtual void SetFill(const FillType& fill) = 0;
	virtual FillType GetFill() const = 0;

	virtual ~IFillStyle() = default;
};

}