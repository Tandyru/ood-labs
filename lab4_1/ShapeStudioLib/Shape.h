#pragma once 
#include "Color.h"

namespace shape
{
	class CShape
	{
	public:
		CShape(Color color)
			: m_color(color)
		{}

		virtual ~CShape() = default;

		Color GetColor() const
		{
			return m_color;
		}
	private:
		const Color m_color;
	};
}