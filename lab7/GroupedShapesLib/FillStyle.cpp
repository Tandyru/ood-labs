#include "stdafx.h"
#include "FillStyle.h"

namespace shape
{

//CFillStyle::CFillStyle()
//	: m_color(DEFAULT_COLOR)
//	, m_fill(true)
//{
//}

CFillStyle::CFillStyle(const Color & color, bool fill)
	: m_color(color)
	, m_fill(fill)
{
}

void CFillStyle::SetColor(const Color & color)
{
	m_color = color;
}

Color CFillStyle::GetColor() const
{
	return m_color;
}

void CFillStyle::SetFill(bool fill)
{
	m_fill = fill;
}

bool CFillStyle::GetFill() const
{
	return m_fill;
}


}
