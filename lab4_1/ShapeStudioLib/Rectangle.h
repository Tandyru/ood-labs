#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{
	class CRectangle : public CShape
	{
	public:
		CRectangle(Color color, Point leftTop, Point rightBottom);
		Point GetLeftTop() const;
		Point GetRightBottom() const;

		void Draw(ICanvas& canvas) override;

		bool operator==(const CShape& shape) const override;
	private:
		const Point m_leftTop;
		const Point m_rightBottom;
	};

}