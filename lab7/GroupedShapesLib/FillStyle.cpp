#include "stdafx.h"
#include "FillStyle.h"

namespace shape
{

CFillStyle::CFillStyle(const Color & color, bool fill)
	: m_color(color)
	, m_fill(fill)
{
}

void CFillStyle::SetColor(const ColorType & color)
{
	m_color = color;
}

IFillStyle::ColorType CFillStyle::GetColor() const
{
	return m_color;
}

void CFillStyle::SetFill(const FillType& fill)
{
	m_fill = fill;
}

IFillStyle::FillType CFillStyle::GetFill() const
{
	return m_fill;
}


}
