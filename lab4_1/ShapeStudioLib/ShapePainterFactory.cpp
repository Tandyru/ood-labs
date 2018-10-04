#include "stdafx.h"
#include "ShapePainterFactory.h"
#include "RectanglePainter.h"

namespace painter
{
	ShapePainter CreateShapePainter(const shape::CShape& shape)
	{
		switch (shape.GetType())
		{
		case shape::ShapeType::Rectangle:
			return CreateRectanglePainter(shape);
		}
		return ShapePainter();
	}
}
