#pragma once 
#include "Color.h"
#include "ShapeType.h"
#include "ICanvas.h"

namespace shape
{
	class CShape
	{
	public:
		CShape(Color color, shape::ShapeType type);

		virtual ~CShape() = default;

		Color GetColor() const;

		shape::ShapeType GetType() const;

		virtual void Draw(ICanvas& canvas) = 0;

		virtual bool operator==(const CShape& shape) const;

	private:
		shape::ShapeType m_type;
		const Color m_color;
	};
}