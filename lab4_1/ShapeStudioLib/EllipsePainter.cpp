#include "stdafx.h"
#include "EllipsePainter.h"
#include "Ellipse.h"
#include <cassert>

namespace painter
{

	ShapePainter CreateEllipsePainter(const shape::CShape& shape)
	{
		assert(shape.GetType() == shape::ShapeType::Ellipse);
		auto ellipse = static_cast<const shape::CEllipse&>(shape);
		return [ellipse](ICanvas& canvas) {
			canvas.SetColor(ellipse.GetColor());
			auto center = ellipse.GetCenter();
			auto hRadius = ellipse.GetHorizontalRadius();
			auto vRadius = ellipse.GetVerticalRadius();
			canvas.DrawEllipse({ center.x - hRadius, center.y - vRadius }, hRadius * 2, vRadius * 2);
		};
	}

}