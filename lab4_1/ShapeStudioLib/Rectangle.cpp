#include "stdafx.h"
#include "Rectangle.h"

namespace shape
{
	CRectangle::CRectangle(Color color, Point leftTop, Point rightBottom)
		: CShape(color, ShapeType::Rectangle)
		, m_leftTop(leftTop)
		, m_rightBottom(rightBottom)
	{
	}

	Point CRectangle::GetLeftTop() const
	{
		return m_leftTop;
	}

	Point CRectangle::GetRightBottom() const
	{
		return m_rightBottom;
	}

	bool CRectangle::operator==(const CRectangle& rectangle) const
	{
		return CShape::operator==(rectangle) &&
			m_leftTop == rectangle.m_leftTop &&
			m_rightBottom == rectangle.m_rightBottom;
	}

}