#include "stdafx.h"
#include "ShapePainterFactory.h"
#include "ShapePainters.h"

namespace painter
{
	ShapePainter CreateShapePainter(const shape::CShape& shape)
	{
		switch (shape.GetType())
		{
		case shape::ShapeType::Rectangle:
			return CreateRectanglePainter(shape);
		case shape::ShapeType::Triangle:
			return CreateTrianglePainter(shape);
		case shape::ShapeType::Ellipse:
			return CreateEllipsePainter(shape);
		case shape::ShapeType::RegularPolygon:
			return CreateRegularPolygonPainter(shape);
		}
		return ShapePainter();
	}
}
