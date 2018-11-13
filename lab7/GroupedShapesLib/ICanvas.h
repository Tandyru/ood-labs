#pragma once
#include "Color.h"
#include "Point.h"

namespace shape
{

struct ICanvas
{
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Point from, Point to) = 0;
	virtual void DrawEllipse(Point leftTop, double width, double height) = 0;

	virtual ~ICanvas() = default;
};

}
