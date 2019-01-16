#include "stdafx.h"
#include "Ellipse.h"

namespace shape
{

CEllipse::CEllipse(Point center, double horizontalRadius, double verticalRadius)
	: m_center(center)
	, m_horizontalRadius(horizontalRadius)
	, m_verticalRadius(verticalRadius)
{
}

Rect CEllipse::GetFrame() const
{
	return Rect{ 
		m_center.x - m_horizontalRadius, 
		m_center.y - m_verticalRadius,
		m_center.x + m_horizontalRadius,
		m_center.y + m_verticalRadius
	};
}

void CEllipse::SetFrame(Rect rect)
{
	m_center = Point{
		(rect.left + rect.right) / 2, 
		(rect.top + rect.bottom) / 2
	};
	m_horizontalRadius = m_center.x - rect.left;
	m_verticalRadius = m_center.y - rect.top;
}

void CEllipse::DrawImpl(ICanvas & canvas)
{
	auto leftTop = Point{ m_center.x - m_horizontalRadius, m_center.y - m_verticalRadius };
	auto width = m_horizontalRadius * 2.0;
	auto height = m_verticalRadius * 2.0;
	canvas.FillEllipse(leftTop, width, height);
	canvas.DrawEllipse(leftTop, width, height);
}

}
