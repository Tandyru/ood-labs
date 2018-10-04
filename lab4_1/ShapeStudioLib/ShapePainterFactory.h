#pragma once
#include "ShapePainter.h"
#include "Shape.h"

namespace painter
{
	ShapePainter CreateShapePainter(const shape::CShape& shape);
}
