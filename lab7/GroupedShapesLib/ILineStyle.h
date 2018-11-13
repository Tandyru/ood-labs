#pragma once
#include "Color.h"

namespace shape
{

class ILineStyle
{
public:
	virtual void SetColor(Color color) = 0;
	virtual Color GetColor() const = 0;

	virtual void SetLineThickness(size_t thickness) = 0;
	virtual size_t GetLineThickness() const = 0;

	virtual ~ILineStyle() = default;
};

}