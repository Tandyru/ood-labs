#include "stdafx.h"
#include "RectanglePainter.h"
#include "Rectangle.h"
#include <cassert>

namespace painter
{

	ShapePainter CreateRectanglePainter(const shape::CShape& shape)
	{
		assert(shape.GetType() == shape::ShapeType::Rectangle);
		auto rectangle = static_cast<const shape::CRectangle&>(shape);
		return [rectangle](ICanvas& canvas) {
			canvas.SetColor(rectangle.GetColor());
			auto leftTop = rectangle.GetLeftTop();
			auto rightBottom = rectangle.GetRightBottom();
			const shape::Point rightTop{ rightBottom.x, leftTop.y };
			const shape::Point leftBottom{ leftTop.x, rightBottom.y };
			canvas.DrawLine(leftTop, rightTop);
			canvas.DrawLine(rightTop, rightBottom);
			canvas.DrawLine(rightBottom, leftBottom);
			canvas.DrawLine(leftBottom, leftTop);
		};
	}

}