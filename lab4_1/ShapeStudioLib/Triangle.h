#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{
	class CTriangle : public CShape
	{
	public:
		CTriangle(Color color, Point vertex1, Point vertex2, Point vertex3);
		Point GetVertex1() const;
		Point GetVertex2() const;
		Point GetVertex3() const;

		bool operator==(const CTriangle& triangle) const;
	private:
		const Point m_vertex1;
		const Point m_vertex2;
		const Point m_vertex3;
	};

}