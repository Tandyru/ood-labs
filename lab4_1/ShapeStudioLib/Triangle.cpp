#include "stdafx.h"
#include "Triangle.h"

namespace shape
{
	CTriangle::CTriangle(Color color, Point vertex1, Point vertex2, Point vertex3)
		: CShape(color, ShapeType::Triangle)
		, m_vertex1(vertex1)
		, m_vertex2(vertex2)
		, m_vertex3(vertex3)
	{
	}

	Point CTriangle::GetVertex1() const
	{
		return m_vertex1;
	}

	Point CTriangle::GetVertex2() const
	{
		return m_vertex2;
	}

	Point CTriangle::GetVertex3() const
	{
		return m_vertex3;
	}

	bool CTriangle::operator==(const CTriangle& triangle) const
	{
		return CShape::operator==(triangle) &&
			m_vertex1 == triangle.m_vertex1 &&
			m_vertex2 == triangle.m_vertex2 &&
			m_vertex3 == triangle.m_vertex3;
	}

}