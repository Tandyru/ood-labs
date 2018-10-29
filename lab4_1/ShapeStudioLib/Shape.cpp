#include <stdafx.h>
#include "Shape.h"

namespace shape
{

CShape::CShape(Color color, shape::ShapeType type)
	: m_color(color)
	, m_type(type)
{}

Color CShape::GetColor() const
{
	return m_color;
}

shape::ShapeType CShape::GetType() const
{
	return m_type;
}

bool CShape::operator==(const CShape& shape) const
{
	return (m_type == shape.m_type) && (m_color == shape.m_color);
}

}
