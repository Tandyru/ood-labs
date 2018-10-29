#include "stdafx.h"
#include "Ellipse.h"

namespace shape
{
	CEllipse::CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius)
		: CShape(color, ShapeType::Ellipse)
		, m_center(center)
		, m_horizontalRadius(horizontalRadius)
		, m_verticalRadius(verticalRadius)
	{
	}

	Point CEllipse::GetCenter() const
	{
		return m_center;
	}

	double CEllipse::GetHorizontalRadius() const
	{
		return m_horizontalRadius;
	}

	double CEllipse::GetVerticalRadius() const
	{
		return m_verticalRadius;
	}

	void CEllipse::Draw(ICanvas & canvas)
	{
		canvas.SetColor(GetColor());
		auto center = GetCenter();
		auto hRadius = GetHorizontalRadius();
		auto vRadius = GetVerticalRadius();
		canvas.DrawEllipse({ center.x - hRadius, center.y - vRadius }, hRadius * 2, vRadius * 2);
	}

	bool CEllipse::operator==(const CShape& shape) const
	{
		if (!CShape::operator==(shape))
		{
			return false;
		}
		const CEllipse& ellipse = dynamic_cast<const CEllipse&>(shape);
		return 
			m_center == ellipse.m_center &&
			m_horizontalRadius == ellipse.m_horizontalRadius &&
			m_verticalRadius == ellipse.m_verticalRadius;
	}

}