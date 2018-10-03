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

	bool CRegularPolygon::operator==(const CRegularPolygon& polygon) const
	{
		return CShape::operator==(polygon) &&
			m_vertexCount == polygon.m_vertexCount &&
			m_center == polygon.m_center &&
			m_radius == polygon.m_radius;
	}

}