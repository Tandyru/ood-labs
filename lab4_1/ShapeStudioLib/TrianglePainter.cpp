#include "stdafx.h"
#include "TrianglePainter.h"
#include "Triangle.h"
#include <cassert>

namespace painter
{

	ShapePainter CreateTrianglePainter(const shape::CShape& shape)
	{
		assert(shape.GetType() == shape::ShapeType::Triangle);
		auto triangle = static_cast<const shape::CTriangle&>(shape);
		return [triangle](ICanvas& canvas) {
			canvas.SetColor(triangle.GetColor());
			auto vertex1 = triangle.GetVertex1();
			auto vertex2 = triangle.GetVertex2();
			auto vertex3 = triangle.GetVertex3();
			canvas.DrawLine(vertex1, vertex2);
			canvas.DrawLine(vertex2, vertex3);
			canvas.DrawLine(vertex3, vertex1);
		};
	}

}