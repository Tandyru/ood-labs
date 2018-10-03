#pragma once
#include "Shape.h"
#include "Point.h"

namespace shape
{
	class CRegularPolygon : public CShape
	{
	public:
		CRegularPolygon(Color color, unsigned int vertexCount, Point center, double radius);
		unsigned int GetVertexCount() const;
		Point GetCenter() const;
		double GetRadius() const;

		bool operator==(const CRegularPolygon& polygon) const;
	private:
		const unsigned int m_vertexCount;
		const Point m_center;
		const double m_radius;
	};

}