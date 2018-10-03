#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{
	class CEllipse : public CShape
	{
	public:
		CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius);
		Point GetCenter() const;
		double GetHorizontalRadius() const;
		double GetVerticalRadius() const;

		bool operator==(const CEllipse& triangle) const;
	private:
		const Point m_center;
		const double m_horizontalRadius;
		const double m_verticalRadius;
	};

}