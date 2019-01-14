#include "stdafx.h"
#include "Transformations.h"

namespace shape
{
namespace transform
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

Rect TransformRect(Rect rect, const Rect& oldRect, const Rect& newRect)
{
	const Range oldXRange{ oldRect.left, oldRect.right };
	const Range oldYRange{ oldRect.top, oldRect.bottom };
	const Range newXRange{ newRect.left, newRect.right };
	const Range newYRange{ newRect.top, newRect.bottom };
	const auto newLeft = TransformValueToNewRange(rect.left, oldXRange, newXRange);
	const auto newTop = TransformValueToNewRange(rect.top, oldYRange, newYRange);
	const auto newRight = TransformValueToNewRange(rect.right, oldXRange, newXRange);
	const auto newBottom = TransformValueToNewRange(rect.bottom, oldYRange, newYRange);
	return { newLeft, newTop, newRight, newBottom };
}

}
}
