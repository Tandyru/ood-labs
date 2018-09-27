#include "stdafx.h"
#include "Rectangle.h"

namespace shape
{
	CRectangle::CRectangle(Color color, Point leftTop, Point rightBottom)
		: CShape(color)
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

}