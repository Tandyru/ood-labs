#include "stdafx.h"
#include "RegularPolygon.h"

namespace shape
{
	CRegularPolygon::CRegularPolygon(Color color, unsigned int vertexCount, Point center, double radius)
		: CShape(color, ShapeType::RegularPolygon)
		, m_vertexCount(vertexCount)
		, m_center(center)
		, m_radius(radius)
	{
	}

	unsigned int CRegularPolygon::GetVertexCount() const
	{
		return m_vertexCount;
	}

	Point CRegularPolygon::GetCenter() const
	{
		return m_center;
	}

	double CRegularPolygon::GetRadius() const
	{
		return m_radius;
	}

	void CRegularPolygon::Draw(ICanvas & canvas)
	{
		canvas.SetColor(GetColor());
		auto vertexCount = GetVertexCount();
		auto center = GetCenter();
		auto radius = GetRadius();
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
	}

	bool CRegularPolygon::operator==(const CShape& shape) const
	{
		if (!CShape::operator==(shape))
		{
			return false;
		}
		auto polygon = dynamic_cast<const CRegularPolygon&>(shape);
		return m_vertexCount == polygon.m_vertexCount &&
			m_center == polygon.m_center &&
			m_radius == polygon.m_radius;
	}

}