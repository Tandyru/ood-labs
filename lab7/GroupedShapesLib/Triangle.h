#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{

class CTriangle : public CShape
{
public:
	CTriangle(Point vertex1, Point vertex2, Point vertex3);

	// Inherited via IShape
	Rect GetFrame() const override;
	void SetFrame(Rect rect) override;

	void DrawImpl(ICanvas & canvas) override;

private:
	Point m_vertex1;
	Point m_vertex2;
	Point m_vertex3;
};

}