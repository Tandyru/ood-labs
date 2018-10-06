#include "stdafx.h"
#include "RegularPolygonPainter.h"
#include "RegularPolygon.h"
#include <cassert>
#include <cmath>

using namespace shape;

namespace painter
{

	ShapePainter CreateRegularPolygonPainter(const CShape& shape)
	{
		assert(shape.GetType() == ShapeType::RegularPolygon);
		auto polygon = static_cast<const CRegularPolygon&>(shape);
		return [polygon](ICanvas& canvas) {
			canvas.SetColor(polygon.GetColor());
			auto vertexCount = polygon.GetVertexCount();
			auto center = polygon.GetCenter();
			auto radius = polygon.GetRadius();
			auto pi = acos(-1);
			auto calcVertex = [&](decltype(vertexCount) index) -> Point {
				auto x = center.x + radius * cos(2 * pi * index / vertexCount);
				auto y = center.y + radius * sin(2 * pi * index / vertexCount);
				return { x, y };
			};
			for (decltype(vertexCount) idx = 0; idx < vertexCount; idx++)
			{
				auto vertex1 = calcVertex(idx);
				auto vertex2 = calcVertex(idx + 1);
				canvas.DrawLine(vertex1, vertex2);
			}
		};
	}

}