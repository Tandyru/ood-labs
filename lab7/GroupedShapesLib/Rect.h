#pragma once
#include "Point.h"
#include <algorithm>

namespace shape
{

struct Rect
{
	double left = 0.0;
	double top = 0.0;
	double right = 0.0;
	double bottom = 0.0;

	Rect(const Point& point = { 0, 0 })
	{
		*this = point;
	}

	Rect(double left, double top, double right, double bottom)
		: left(left)
		, top(top)
		, right(right)
		, bottom(bottom)
	{
	}

	Rect& operator=(const Point& point)
	{
		left = right = point.x;
		top = bottom = point.y;
		return *this;
	}

	Rect& operator+=(const Point& point)
	{
		left = min(left, point.x);
		right = max(right, point.x);
		top = min(top, point.y);
		bottom = max(bottom, point.y);
		return *this;
	}

};

/*
inline Point GetCenter(const Rect& rect)
{
	return Point{ (rect.left + rect.right) / 2.0, (rect.top + rect.bottom) / 2.0 };
}*/


}