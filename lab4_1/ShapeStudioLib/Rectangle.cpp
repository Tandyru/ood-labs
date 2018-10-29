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

	void CRectangle::Draw(ICanvas & canvas)
	{
		canvas.SetColor(GetColor());
		const auto leftTop = GetLeftTop();
		const auto rightBottom = GetRightBottom();
		const shape::Point rightTop{ rightBottom.x, leftTop.y };
		const shape::Point leftBottom{ leftTop.x, rightBottom.y };
		canvas.DrawLine(leftTop, rightTop);
		canvas.DrawLine(rightTop, rightBottom);
		canvas.DrawLine(rightBottom, leftBottom);
		canvas.DrawLine(leftBottom, leftTop);
	}

	bool CRectangle::operator==(const CShape& shape) const
	{
		if (!CShape::operator==(shape))
		{
			return false;
		}
		const CRectangle& rectangle = dynamic_cast<const CRectangle&>(shape);
		return m_leftTop == rectangle.m_leftTop &&
			m_rightBottom == rectangle.m_rightBottom;
	}

}