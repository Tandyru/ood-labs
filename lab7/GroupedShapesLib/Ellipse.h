#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{

class CEllipse : public CShape
{
public:
	CEllipse(Point center, double horizontalRadius, double verticalRadius);

	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;

	void Draw(ICanvas & canvas) const override;

private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};

}