#include "stdafx.h"
#include "Triangle.h"

namespace shape
{

CTriangle::CTriangle(Point vertex1, Point vertex2, Point vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
}

Rect CTriangle::GetFrame() const
{
	Rect result(m_vertex1);
	result += m_vertex2;
	result += m_vertex3;
	return result;
}

namespace
{

struct Range
{
	double minValue;
	double maxValue;
};

double GetMiddleOfRange(const Range& range)
{
	return (range.minValue + range.maxValue) / 2.0;
}

double GetScale(const Range& oldRange, const Range& newRange)
{
	return (newRange.maxValue - newRange.minValue) / (oldRange.maxValue - oldRange.minValue);
}

double TransformValueToNewRange(double value, const Range& oldRange, const Range& newRange)
{
	double oldMiddle = GetMiddleOfRange(oldRange);
	double newMiddle = GetMiddleOfRange(newRange);
	double scale = GetScale(oldRange, newRange);
	if (value > oldMiddle)
	{
		return newMiddle + (value - oldMiddle) * scale;
	}
	else if (value < oldMiddle)
	{
		return newMiddle - (oldMiddle - value) * scale;
	}
	return newMiddle;
}

Point TransformVertexToNewRect(Point vertex, const Rect& oldRect, const Rect& newRect)
{
	const Range oldXRange{ oldRect.left, oldRect.right };
	const Range oldYRange{ oldRect.top, oldRect.bottom };
	const Range newXRange{ newRect.left, newRect.right };
	const Range newYRange{ newRect.top, newRect.bottom };
	const auto newX = TransformValueToNewRange(vertex.x, oldXRange, newXRange);
	const auto newY = TransformValueToNewRange(vertex.y, oldYRange, newYRange);
	return { newX, newY };
}

}

void CTriangle::SetFrame(Rect rect)
{
	const auto oldRect = GetFrame();
	m_vertex1 = TransformVertexToNewRect(m_vertex1, oldRect, rect);
	m_vertex2 = TransformVertexToNewRect(m_vertex2, oldRect, rect);
	m_vertex3 = TransformVertexToNewRect(m_vertex3, oldRect, rect);
}

void CTriangle::Draw(ICanvas & canvas) const
{
	// ??
}

}
