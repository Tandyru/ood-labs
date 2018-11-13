#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{

class CTriangle : public CShape
{
public:
	CTriangle(Point vertex1, Point vertex2, Point vertex3);

	// IShape
	void Draw(ICanvas & canvas) const override;

private:
	Point vertex1;
	Point vertex2;
	Point vertex3;
};

}