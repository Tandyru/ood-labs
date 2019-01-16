#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{

class CRectangle : public CShape
{
public:
	CRectangle(double left, double top, double right, double bottom);

	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;

	void DrawImpl(ICanvas & canvas) override;

private:
	Rect m_rectangle;
};

}