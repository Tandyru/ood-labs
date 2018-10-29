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

		void Draw(ICanvas& canvas) override;

		bool operator==(const CShape& shape) const override;
	private:
		const Point m_center;
		const double m_horizontalRadius;
		const double m_verticalRadius;
	};

}