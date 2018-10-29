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

	void CTriangle::Draw(ICanvas & canvas)
	{
		canvas.SetColor(GetColor());
		auto vertex1 = GetVertex1();
		auto vertex2 = GetVertex2();
		auto vertex3 = GetVertex3();
		canvas.DrawLine(vertex1, vertex2);
		canvas.DrawLine(vertex2, vertex3);
		canvas.DrawLine(vertex3, vertex1);
	}

	bool CTriangle::operator==(const CShape& shape) const
	{
		if (!CShape::operator==(shape))
		{
			return false;
		}
		auto triangle = dynamic_cast<const CTriangle&>(shape);
		return m_vertex1 == triangle.m_vertex1 &&
			m_vertex2 == triangle.m_vertex2 &&
			m_vertex3 == triangle.m_vertex3;
	}

}