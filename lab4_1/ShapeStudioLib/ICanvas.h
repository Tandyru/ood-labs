#pragma once
#include "Color.h"
#include "Point.h"

struct ICanvas
{
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(shape::Point from, shape::Point to) = 0;
	virtual void DrawEllipse(shape::Point leftTop, double width, double height) = 0;

	virtual ~ICanvas() = default;
};