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

	private:
		const Point m_leftTop;
		const Point m_rightBottom;
	};

}