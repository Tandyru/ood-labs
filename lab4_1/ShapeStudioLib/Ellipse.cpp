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

	bool CEllipse::operator==(const CEllipse& ellipse) const
	{
		return CShape::operator==(ellipse) &&
			m_center == ellipse.m_center &&
			m_horizontalRadius == ellipse.m_horizontalRadius &&
			m_verticalRadius == ellipse.m_verticalRadius;
	}

}