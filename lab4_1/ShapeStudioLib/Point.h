#pragma once

namespace shape
{
	struct Point
	{
		double x = 0;
		double y = 0;
	};

	inline bool operator==(const Point& point1, const Point& point2)
	{
		return (point1.x == point2.x) && (point1.y == point2.y);
	}
}